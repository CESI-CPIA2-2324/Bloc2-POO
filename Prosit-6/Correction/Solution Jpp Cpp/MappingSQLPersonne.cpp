#include "pch.h"
#include "MappingSQLPersonne.h"

using namespace System;

namespace PersonnesEtAdresses
{

	String^ MappingSQLPersonne::Delete(int id)
	{
		return String::Format(L"DELETE FROM Personne ") + String::Format(L"WHERE(Id = {0})", id);
	}

	String^ MappingSQLPersonne::Insert(Personne ^personne)
	{
		return String::Format(L"INSERT INTO Personne ") + String::Format(L"(Nom, Prenom) ") + String::Format(L"VALUES('{0}', '{1}'); ", personne->Nom, personne->Prenom) + String::Format(L"SELECT CAST(SCOPE_IDENTITY() AS INT) AS LAST_IDENTITY; "); // C.F. https://stackoverflow.com/questions/2601620/why-does-select-scope-identity-return-a-decimal-instead-of-an-integer
	}

	String^ MappingSQLPersonne::SelectAll()
	{
		return String::Format(L"SELECT Id, Nom, Prenom ") + String::Format(L"FROM Personne ");
	}

	String^ MappingSQLPersonne::SelectById(int id)
	{
		return String::Format(L"SELECT Id, Nom, Prenom ") + String::Format(L"FROM Personne ") + String::Format(L"WHERE id = {0} ", id);
	}

	String^ MappingSQLPersonne::Update(Personne ^personne)
	{
		return String::Format(L"UPDATE Personne ") + String::Format(L"SET Nom = '{0}', Prenom = '{1}' ", personne->Nom, personne->Prenom) + String::Format(L"WHERE(Id = {0});", personne->Id);
	}
}
