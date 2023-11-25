#include "pch.h"
#include "GestionPersonnes.h"
using namespace System::Data;

namespace PersonnesEtAdresses
{

	GestionPersonnes::GestionPersonnes(ISQLAccess^ sqlAccess) : _sqlAccess(sqlAccess)
	{
	}

	Personne^ GestionPersonnes::ConvertDataRowToPersonne(DataRow^ dataRow)
	{
		auto result = gcnew Personne();
		result->Id = (safe_cast<int>(dataRow[L"Id"]));
		result->Nom = (safe_cast<String^>(dataRow[L"Nom"]));
		result->Prenom = (safe_cast<String^>(dataRow[L"Prenom"]));

		return result;
	}

	Adresse^ GestionPersonnes::ConvertDataRowToAdresse(DataRow^ dataRow)
	{
		auto result = gcnew Adresse();
		result->Id = (safe_cast<int>(dataRow[L"Id"]));
		result->CodePostal= (safe_cast<String^>(dataRow[L"CodePostal"]));
		result->Ville = (safe_cast<String^>(dataRow[L"Ville"]));
		result->PersonneId= (safe_cast<int>(dataRow[L"PersonneId"]));

		return result;
	}

	List<Personne^>^ GestionPersonnes::ConvertPersonnes(DataRowCollection^ dataRows)
	{
		List<Personne^>^ result = gcnew List<Personne^>();
		for each (auto dataRow in dataRows)
		{
			result->Add(ConvertDataRowToPersonne(safe_cast<DataRow^>(dataRow)));
		}
		return result;
	}

	List<Adresse^>^ GestionPersonnes::ConvertAdresses(DataRowCollection^ dataRows)
	{
		List<Adresse^>^ result = gcnew List<Adresse^>();
		for each (auto dataRow in dataRows)
		{
			result->Add(ConvertDataRowToAdresse(safe_cast<DataRow^>(dataRow)));
		}
		return result;
	}

	List<Personne^>^ GestionPersonnes::GetPersonnes()
	{
		String^ sql = _mappingSQLPersonne->SelectAll();
		DataSet^ dataset = _sqlAccess->GetRows(sql, L"Personnes");
		DataRowCollection^ dataRows = dataset->Tables[L"Personnes"]->Rows;
		return ConvertPersonnes(dataRows);
	}

	List<Adresse^>^ GestionPersonnes::GetAdresses(int personneId)
	{
		String^ sql = _mappingSQLAdresse->SelectByPersonneId(personneId);
		DataSet^ dataset = _sqlAccess->GetRows(sql, L"Adresses");
		DataRowCollection^ dataRows = dataset->Tables[L"Adresses"]->Rows;
		return ConvertAdresses(dataRows);
	}

	int GestionPersonnes::Add(Personne^ personne, List<Adresse^>^ adresses)
	{
		String^ sql = _mappingSQLPersonne->Insert(personne);
		auto personneId = safe_cast<int>(_sqlAccess->ExecuteScalar(sql));
		InsertAdressesFromPersonne(adresses, personneId);
		return personneId;
	}

	void GestionPersonnes::InsertAdressesFromPersonne(List<Adresse^>^ adresses, int personneId)
	{
		if (adresses->Count == 0)
			return;
		for each (Adresse^ adresse in adresses)
		{
			adresse->PersonneId = personneId;
			String^ sql = _mappingSQLAdresse->Insert(adresse);
			_sqlAccess->ExecuteScalar(sql);
		}
	}

	void GestionPersonnes::Update(Personne^ personne, List<Adresse^>^ adresses)
	{
		String^ sql = _mappingSQLPersonne->Update(personne);
		DeleteAllAdressesFromAPersonne(personne->Id);
		InsertAdressesFromPersonne(adresses, personne->Id);
		_sqlAccess->ExecuteNonQuery(sql);
	}

	void GestionPersonnes::Delete(int personneId)
	{
		DeleteAllAdressesFromAPersonne(personneId);

		String^ sql = _mappingSQLPersonne->Delete(personneId);
		_sqlAccess->ExecuteNonQuery(sql);
	}

	void GestionPersonnes::DeleteAllAdressesFromAPersonne(int personneId)
	{
		auto adresses = GetAdresses(personneId);
		for each (auto adresse in adresses)
		{
			String^ sql = _mappingSQLAdresse->Delete(adresse->Id);
			_sqlAccess->ExecuteNonQuery(sql);
		}
	}
}
