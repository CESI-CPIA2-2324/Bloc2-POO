#pragma once

#include "IRepository.h"
#include "ISQLAccess.h"
#include "MappingSQLPersonne.h"
#include "MappingSQLAdresse.h"
#include "Personne.h"
#include "Adresse.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections;

namespace PersonnesEtAdresses
{
	public ref class GestionPersonnes : public IRepository
	{
	private:
		ISQLAccess^ _sqlAccess;
		MappingSQLPersonne^ _mappingSQLPersonne = gcnew MappingSQLPersonne();
		MappingSQLAdresse^ _mappingSQLAdresse = gcnew MappingSQLAdresse();

		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="sqlAccess"></param>
	public:
		virtual ~GestionPersonnes()
		{
			delete _sqlAccess;
			delete _mappingSQLPersonne;
			delete _mappingSQLAdresse;
		}

		GestionPersonnes(ISQLAccess^ sqlAccess);

	private:
		Personne^ ConvertDataRowToPersonne(DataRow^ dataRow);

		Adresse^ ConvertDataRowToAdresse(DataRow^ dataRow);


		List<Personne^>^ ConvertPersonnes(DataRowCollection^ dataRows);
		List<Adresse^>^ ConvertAdresses(DataRowCollection^ dataRows);

	public:
		List<Personne^>^ GetPersonnes() override;
		List<Adresse^>^ GetAdresses(int personneId) override;

		int Add(Personne^ personne, List<Adresse^>^ adresses) override;

	private:
		void InsertAdressesFromPersonne(List<Adresse^>^ adresses, int personneId);

	public:
		void Update(Personne^ personne, List<Adresse^>^ adresses) override;

		void Delete(int personneId) override;

	private:
		void DeleteAllAdressesFromAPersonne(int personneId);
	};
}
