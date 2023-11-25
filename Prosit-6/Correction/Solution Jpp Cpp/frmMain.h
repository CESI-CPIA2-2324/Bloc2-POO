#pragma once

#include "Personne.h"
#include "Adresse.h"
#include "IRepository.h"

using namespace System::Windows::Forms;
using namespace System::Collections::ObjectModel;
namespace PersonnesEtAdresses
{
	public ref class frmMain : public System::Windows::Forms::Form
	{

	private:
		enum class ModeEnum
		{
			Read,
			Insert,
			Update
		};

		String^ _connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Prosit6Database;Trusted_Connection=True";

	private:
		List<Personne^>^ _personnes;
	private: System::Windows::Forms::DataGridView^ dgvAdresses;
	private: System::Windows::Forms::BindingSource^ bindingSource;
















		int _personneIndex = -1;
	public:
		virtual ~frmMain()
		{
			delete _repository;
			delete components;
			delete btnFirst;
			delete lblId;
			delete txbMessage;
			delete dgvAdresses;
			delete lblPrenom;
			delete lblNom;
			delete btnDelete;
			delete btnUpdate;
			delete btnNew;
			delete btnLast;
			delete btnNext;
			delete btnPrevious;
			delete btnSave;
			delete txbPrenom;
			delete txbNom;
			delete txbId;
			delete lblMessage;
			delete lblAdresses;
			delete btnCancel;
		}

	private:
		int getPersonneIndex();
		void setPersonneIndex(int value);

		int getCurrentPersonId();

		List<Adresse^>^ _adressesDeLaPersonne;

		List<Adresse^>^ getAdressesDeLaPersonne();
		void setAdressesDeLaPersonne(List<Adresse^>^ value);

		ModeEnum _mode = ModeEnum::Read;

		ModeEnum getMode();
		void setMode(ModeEnum value);

		IRepository^ _repository;

	public:
		frmMain();

	private:
		void InitializeDB();

		void ReloadData();

	public:
		void RefreshUI();

	private:
		void Log(String^ message);

		void btnFirst_Click(System::Object^, System::EventArgs^ e);

		void btnPrevious_Click(System::Object^, System::EventArgs^ e);

		void btnNext_Click(System::Object^, System::EventArgs^ e);

		void btnLast_Click(System::Object^, System::EventArgs^ e);

		void btnNew_Click(System::Object^, System::EventArgs^ e);

		void btnSave_Click(System::Object^, System::EventArgs^ e);

		List<Adresse^>^ GetAdressesFromUI();

		void btnUpdate_Click(System::Object^, System::EventArgs^ e);

		void btnDelete_Click(System::Object^, System::EventArgs^ e);

		void btnCancel_Click(System::Object^, System::EventArgs^ e);

		void dgvAdresses_CellValidating(System::Object^, DataGridViewCellValidatingEventArgs^ e);


		/// <summary>
		///  Required designer variable.
		/// </summary>
		System::ComponentModel::IContainer^ components = nullptr;

		/// <summary>
		///  Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
	protected:

		//		#region Windows Form Designer generated code

				/// <summary>
				///  Required method for Designer support - do not modify
				///  the contents of this method with the code editor.
				/// </summary>
	private:
		void InitializeComponent()
        {
			this->components = (gcnew System::ComponentModel::Container());
			this->btnFirst = (gcnew System::Windows::Forms::Button());
			this->lblId = (gcnew System::Windows::Forms::Label());
			this->txbMessage = (gcnew System::Windows::Forms::TextBox());
			this->lblPrenom = (gcnew System::Windows::Forms::Label());
			this->lblNom = (gcnew System::Windows::Forms::Label());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnLast = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnPrevious = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->txbPrenom = (gcnew System::Windows::Forms::TextBox());
			this->txbNom = (gcnew System::Windows::Forms::TextBox());
			this->txbId = (gcnew System::Windows::Forms::TextBox());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->lblAdresses = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->dgvAdresses = (gcnew System::Windows::Forms::DataGridView());
			this->bindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAdresses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource))->BeginInit();
			this->SuspendLayout();
			// 
			// btnFirst
			// 
			this->btnFirst->Location = System::Drawing::Point(33, 207);
			this->btnFirst->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnFirst->Name = L"btnFirst";
			this->btnFirst->Size = System::Drawing::Size(54, 36);
			this->btnFirst->TabIndex = 3;
			this->btnFirst->Text = L"<<";
			this->btnFirst->UseVisualStyleBackColor = true;
			this->btnFirst->Click += gcnew System::EventHandler(this, &frmMain::btnFirst_Click);
			// 
			// lblId
			// 
			this->lblId->AutoSize = true;
			this->lblId->Location = System::Drawing::Point(31, 7);
			this->lblId->Name = L"lblId";
			this->lblId->Size = System::Drawing::Size(23, 20);
			this->lblId->TabIndex = 1;
			this->lblId->Text = L"Id";
			// 
			// txbMessage
			// 
			this->txbMessage->Anchor = safe_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txbMessage->Location = System::Drawing::Point(33, 413);
			this->txbMessage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txbMessage->Multiline = true;
			this->txbMessage->Name = L"txbMessage";
			this->txbMessage->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txbMessage->Size = System::Drawing::Size(740, 414);
			this->txbMessage->TabIndex = 2;
			this->txbMessage->TabStop = false;
			// 
			// lblPrenom
			// 
			this->lblPrenom->AutoSize = true;
			this->lblPrenom->Location = System::Drawing::Point(31, 134);
			this->lblPrenom->Name = L"lblPrenom";
			this->lblPrenom->Size = System::Drawing::Size(64, 20);
			this->lblPrenom->TabIndex = 4;
			this->lblPrenom->Text = L"Prénom";
			// 
			// lblNom
			// 
			this->lblNom->AutoSize = true;
			this->lblNom->Location = System::Drawing::Point(31, 68);
			this->lblNom->Name = L"lblNom";
			this->lblNom->Size = System::Drawing::Size(42, 20);
			this->lblNom->TabIndex = 5;
			this->lblNom->Text = L"Nom";
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(33, 341);
			this->btnDelete->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(113, 36);
			this->btnDelete->TabIndex = 10;
			this->btnDelete->Text = L"&Supprimer";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &frmMain::btnDelete_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(33, 296);
			this->btnUpdate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(113, 36);
			this->btnUpdate->TabIndex = 8;
			this->btnUpdate->Text = L"&Mise à jour";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &frmMain::btnUpdate_Click);
			// 
			// btnNew
			// 
			this->btnNew->Location = System::Drawing::Point(33, 251);
			this->btnNew->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(113, 36);
			this->btnNew->TabIndex = 7;
			this->btnNew->Text = L"&Nouveau";
			this->btnNew->UseVisualStyleBackColor = true;
			this->btnNew->Click += gcnew System::EventHandler(this, &frmMain::btnNew_Click);
			// 
			// btnLast
			// 
			this->btnLast->Location = System::Drawing::Point(211, 206);
			this->btnLast->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnLast->Name = L"btnLast";
			this->btnLast->Size = System::Drawing::Size(54, 36);
			this->btnLast->TabIndex = 6;
			this->btnLast->Text = L">>";
			this->btnLast->UseVisualStyleBackColor = true;
			this->btnLast->Click += gcnew System::EventHandler(this, &frmMain::btnLast_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(151, 207);
			this->btnNext->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(54, 36);
			this->btnNext->TabIndex = 5;
			this->btnNext->Text = L">";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &frmMain::btnNext_Click);
			// 
			// btnPrevious
			// 
			this->btnPrevious->Location = System::Drawing::Point(92, 207);
			this->btnPrevious->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnPrevious->Name = L"btnPrevious";
			this->btnPrevious->Size = System::Drawing::Size(54, 36);
			this->btnPrevious->TabIndex = 4;
			this->btnPrevious->Text = L"<";
			this->btnPrevious->UseVisualStyleBackColor = true;
			this->btnPrevious->Click += gcnew System::EventHandler(this, &frmMain::btnPrevious_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(151, 251);
			this->btnSave->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(113, 81);
			this->btnSave->TabIndex = 9;
			this->btnSave->Text = L"&Enregistrer";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmMain::btnSave_Click);
			// 
			// txbPrenom
			// 
			this->txbPrenom->Location = System::Drawing::Point(31, 157);
			this->txbPrenom->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txbPrenom->Name = L"txbPrenom";
			this->txbPrenom->Size = System::Drawing::Size(233, 26);
			this->txbPrenom->TabIndex = 2;
			// 
			// txbNom
			// 
			this->txbNom->Location = System::Drawing::Point(31, 90);
			this->txbNom->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txbNom->Name = L"txbNom";
			this->txbNom->Size = System::Drawing::Size(233, 26);
			this->txbNom->TabIndex = 1;
			// 
			// txbId
			// 
			this->txbId->Location = System::Drawing::Point(31, 30);
			this->txbId->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txbId->Name = L"txbId";
			this->txbId->ReadOnly = true;
			this->txbId->Size = System::Drawing::Size(233, 26);
			this->txbId->TabIndex = 0;
			this->txbId->TabStop = false;
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->Location = System::Drawing::Point(33, 391);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(74, 20);
			this->lblMessage->TabIndex = 17;
			this->lblMessage->Text = L"Message";
			// 
			// lblAdresses
			// 
			this->lblAdresses->AutoSize = true;
			this->lblAdresses->Location = System::Drawing::Point(286, 7);
			this->lblAdresses->Name = L"lblAdresses";
			this->lblAdresses->Size = System::Drawing::Size(76, 20);
			this->lblAdresses->TabIndex = 18;
			this->lblAdresses->Text = L"Adresses";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(151, 341);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(113, 36);
			this->btnCancel->TabIndex = 11;
			this->btnCancel->Text = L"&Annuler";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmMain::btnCancel_Click);
			// 
			// dgvAdresses
			// 
			this->dgvAdresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAdresses->Location = System::Drawing::Point(290, 30);
			this->dgvAdresses->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dgvAdresses->Name = L"dgvAdresses";
			this->dgvAdresses->RowHeadersWidth = 62;
			this->dgvAdresses->Size = System::Drawing::Size(481, 291);
			this->dgvAdresses->TabIndex = 19;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(821, 838);
			this->Controls->Add(this->dgvAdresses);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->lblAdresses);
			this->Controls->Add(this->lblMessage);
			this->Controls->Add(this->txbId);
			this->Controls->Add(this->txbNom);
			this->Controls->Add(this->txbPrenom);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnPrevious);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnLast);
			this->Controls->Add(this->btnNew);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->lblNom);
			this->Controls->Add(this->lblPrenom);
			this->Controls->Add(this->txbMessage);
			this->Controls->Add(this->lblId);
			this->Controls->Add(this->btnFirst);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"frmMain";
			this->Text = L"Personnes & Adresses";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAdresses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		//		#endregion

		System::Windows::Forms::Button^ btnFirst;
		System::Windows::Forms::Label^ lblId;
		System::Windows::Forms::TextBox^ txbMessage;

		System::Windows::Forms::Label^ lblPrenom;
		System::Windows::Forms::Label^ lblNom;
		System::Windows::Forms::Button^ btnDelete;
		System::Windows::Forms::Button^ btnUpdate;
		System::Windows::Forms::Button^ btnNew;
		System::Windows::Forms::Button^ btnLast;
		System::Windows::Forms::Button^ btnNext;
		System::Windows::Forms::Button^ btnPrevious;
		System::Windows::Forms::Button^ btnSave;
		System::Windows::Forms::TextBox^ txbPrenom;
		System::Windows::Forms::TextBox^ txbNom;
		System::Windows::Forms::TextBox^ txbId;
		System::Windows::Forms::Label^ lblMessage;
		System::Windows::Forms::Label^ lblAdresses;

		System::Windows::Forms::Button^ btnCancel;
	};
}
