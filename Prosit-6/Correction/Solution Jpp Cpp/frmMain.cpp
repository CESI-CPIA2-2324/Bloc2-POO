#include "pch.h"
#include "frmMain.h"
#include "SQLAccess.h"
#include "GestionPersonnes.h"

using namespace System::Collections::ObjectModel;
using namespace System::Windows::Forms;

namespace PersonnesEtAdresses
{

	int frmMain::getPersonneIndex()
	{
		return _personneIndex;
	}

	void frmMain::setPersonneIndex(int value)
	{
		if (value != _personneIndex)
		{
			_personneIndex = value;
			RefreshUI();
		}
	}

	int frmMain::getCurrentPersonId()
	{
		if (_personneIndex < 0 || _personneIndex >= _personnes->Count)
		{
			return -1;
		}
		return _personnes[_personneIndex]->Id;
	}

	List<Adresse^>^ frmMain::getAdressesDeLaPersonne()
	{
		return _adressesDeLaPersonne;
	}

	void frmMain::setAdressesDeLaPersonne(List<Adresse^>^ value)
	{
		_adressesDeLaPersonne = value;
		dgvAdresses->DataSource = nullptr;
		bindingSource->DataSource = gcnew ObservableCollection<Adresse^>(_adressesDeLaPersonne);;
		bindingSource->DataMember = nullptr;
		dgvAdresses->DataSource = bindingSource;
	}

	frmMain::ModeEnum frmMain::getMode()
	{
		return _mode;
	}

	void frmMain::setMode(ModeEnum value)
	{
		if (_mode == value)
		{
			return;
		}
		_mode = value;
		RefreshUI();
	}

	frmMain::frmMain()
	{
		InitializeComponent();
		InitializeDB();
	}

	void frmMain::InitializeDB()
	{
		SQLAccess^ sqlAccess = gcnew SQLAccess(_connectionString);
		_repository = gcnew GestionPersonnes(sqlAccess);
		ReloadData();
	}

	void frmMain::ReloadData()
	{
		_personneIndex = -1;
		_personnes = _repository->GetPersonnes();
		Log(String::Format(L"{0} personnes trouvées.", _personnes->Count));
		setPersonneIndex(0); // ceci rappelera RafraichirUI();
	}

	void frmMain::RefreshUI()
	{
		switch (getMode())
		{
		case ModeEnum::Read:
			if (_personnes->Count==0)
			{
				txbId->Clear();
				txbNom->Clear();
				txbPrenom->Clear();
				txbId->Clear();
				setAdressesDeLaPersonne(gcnew List<Adresse^>());
			}
			else
			{
				auto personne = _personnes[_personneIndex];
				txbId->Text = Convert::ToString(personne->Id);
				txbNom->Text = personne->Nom;
				txbPrenom->Text = personne->Prenom;
				setAdressesDeLaPersonne(_repository->GetAdresses(getCurrentPersonId()));
				Log(L"Chargement de l'enregistrement : " + Convert::ToString((getPersonneIndex() + 1)));
			}

			break;
		case ModeEnum::Insert:
			txbId->Clear();
			txbNom->Clear();
			txbPrenom->Clear();
			txbId->Clear();
			setAdressesDeLaPersonne(gcnew List<Adresse^>());
			break;
		case ModeEnum::Update:
			break;
		default:
			throw gcnew Exception(String::Format(L"Note pour le développeur : Ce mode {0} n'est pas géré", getMode()));
		}

		dgvAdresses->Columns[L"Id"]->Visible = false;
		dgvAdresses->Columns[L"PersonneId"]->Visible = false;

		bool modeWrite = (getMode() == ModeEnum::Insert || getMode() == ModeEnum::Update);
		btnSave->Enabled = modeWrite;
		btnCancel->Enabled = modeWrite;
		dgvAdresses->ReadOnly = !modeWrite;
		dgvAdresses->AllowUserToAddRows = modeWrite;
		txbNom->Enabled = modeWrite;
		txbPrenom->Enabled = modeWrite;

		btnFirst->Enabled = !modeWrite && _personnes->Count > 0 && getPersonneIndex() > 0;
		btnPrevious->Enabled = !modeWrite && _personnes->Count > 0 && getPersonneIndex() > 0;
		btnNext->Enabled = !modeWrite && _personnes->Count > 0 && getPersonneIndex() < _personnes->Count - 1;
		btnLast->Enabled = !modeWrite && _personnes->Count > 0 && getPersonneIndex() < _personnes->Count - 1;

		btnUpdate->Enabled = _personnes->Count > 0 && getMode() == ModeEnum::Read;
		btnDelete->Enabled = _personnes->Count > 0 && getMode() == ModeEnum::Read;
		btnNew->Enabled = getMode() == ModeEnum::Read;
	}

	void frmMain::Log(String^ message)
	{
		txbMessage->Text += message + L"\r\n";
	}

	void frmMain::btnFirst_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (_personnes->Count >= 0)
		{
			setPersonneIndex(0);
		}
	}

	void frmMain::btnPrevious_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (getPersonneIndex() > 0)
		{
			setPersonneIndex(getPersonneIndex() - 1);
		}
	}

	void frmMain::btnNext_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (getPersonneIndex() < _personnes->Count - 1)
		{
			setPersonneIndex(getPersonneIndex() + 1);
		}
	}

	void frmMain::btnLast_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (_personnes->Count >= 0)
		{
			setPersonneIndex(_personnes->Count - 1);
		}
	}

	void frmMain::btnNew_Click(System::Object^ sender, System::EventArgs^ e)
	{
		setMode(ModeEnum::Insert);
		Log(L"Veuillez saisir les renseignements avant d'enregister");
	}

	void frmMain::btnSave_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrEmpty(txbNom->Text))
		{
			MessageBox::Show("Veuillez saisir un nom", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			txbNom->Focus();
			return;
		}
		if (String::IsNullOrEmpty(txbPrenom->Text))
		{
			MessageBox::Show("Veuillez saisir un prénom", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			txbNom->Focus();
			return;
		}
		switch (getMode())
		{
		case ModeEnum::Insert:
		{
			Personne^ newPersonne = gcnew Personne();
			newPersonne->Id = -1;
			newPersonne->Nom = txbNom->Text;
			newPersonne->Prenom = txbPrenom->Text;
			_repository->Add(newPersonne, GetAdressesFromUI());
			ReloadData();
			setPersonneIndex(_personnes->Count - 1);
			break;
		}
		case ModeEnum::Update:
		{
			Personne^ updatedPersonne = _personnes[_personneIndex];
			updatedPersonne->Nom = txbNom->Text;
			updatedPersonne->Prenom = txbPrenom->Text;
			_repository->Update(updatedPersonne, GetAdressesFromUI());
			break;
		}
		default:
			throw gcnew  Exception(String::Format("Note pour le développeur : Il ne doit pas être possible de cliquer sur le bouton enregistrer dans ce mode {0}", getMode()));
		}
		setMode ( ModeEnum::Read);
	}

	List<Adresse^>^ frmMain::GetAdressesFromUI()
	{
		BindingSource^ bindingSource = safe_cast<BindingSource^>(dgvAdresses->DataSource);
		ObservableCollection<Adresse^>^ observableCollection = (ObservableCollection<Adresse^>^)(bindingSource->DataSource);
		return gcnew List<Adresse^>(observableCollection);
	}

	void frmMain::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
	{
		setMode ( ModeEnum::Update);
		Log("Veuillez modifier les renseignements avant d'enregister");
	}

	void frmMain::btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (MessageBox::Show("Etes vous sur de vouloir supprimer cette personne ?", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Question) != System::Windows::Forms::DialogResult::Yes)
			return;

		int id = getCurrentPersonId();
		if (id == -1)
			return;
		_repository->Delete(id);
		Log(String::Format("L'enregistrement a été supprimé (personne avec id = {0})", id));
		ReloadData();
	}

	void frmMain::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
	{
		setMode( ModeEnum::Read);
	}

	void frmMain::dgvAdresses_CellValidating(System::Object^ sender, DataGridViewCellValidatingEventArgs^ e)
	{
		if (String::IsNullOrEmpty(safe_cast<String^>(e->FormattedValue)))
		{
			MessageBox::Show("Le code postal et la ville sont des données obligatoires", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			e->Cancel = true;
		}
	}
}
