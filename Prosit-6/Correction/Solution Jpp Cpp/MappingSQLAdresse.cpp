#include "pch.h"
#include "MappingSQLAdresse.h"

namespace PersonnesEtAdresses
{

	String^ MappingSQLAdresse::Delete(int id)
	{
		return String::Format(L"DELETE FROM Adresse ") + String::Format(L"WHERE(Id = {0})", id);
	}

	String^ MappingSQLAdresse::Insert(Adresse ^adresse)
	{
		return String::Format(L"INSERT INTO Adresse(CodePostal, Ville, PersonneId) ") + String::Format(L"VALUES('{0}', '{1}', '{2}'); ", adresse->CodePostal, adresse->Ville, adresse->PersonneId) + String::Format(L"SELECT CAST(SCOPE_IDENTITY() AS INT) AS LAST_IDENTITY; "); // C.F. https://stackoverflow.com/questions/2601620/why-does-select-scope-identity-return-a-decimal-instead-of-an-integer
	}

	String^ MappingSQLAdresse::SelectAll()
	{
		return String::Format(L"SELECT Id, CodePostal, Ville, PersonneId ") + String::Format(L"FROM Adresse ");
	}

	String^ MappingSQLAdresse::SelectById(int id)
	{
		return String::Format(L"SELECT Id, CodePostal, Ville, PersonneId ") + String::Format(L"FROM Adresse ") + String::Format(L"WHERE (Id= {0})", id);
	}

	String^ MappingSQLAdresse::Update(Adresse ^adresse)
	{
		return String::Format(L"UPDATE Adresse ") + String::Format(L"SET CodePostal ='{0}', Ville ='{1}', PersonneId = '{2}' ", adresse->CodePostal, adresse->Ville, adresse->PersonneId + String::Format(L"WHERE(Id = {0}) ", adresse->Id));
	}

	String^ MappingSQLAdresse::SelectByPersonneId(int personneId)
	{
		return String::Format(L"SELECT Id, CodePostal, Ville, PersonneId ") + String::Format(L"FROM Adresse ") + String::Format(L"WHERE (PersonneId= {0})", personneId);
	}
}
