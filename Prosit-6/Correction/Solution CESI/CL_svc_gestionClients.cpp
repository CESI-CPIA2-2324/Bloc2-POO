#include "pch.h"
                                                      //CL_svc_gestionClients.cpp
#include "CL_svc_gestionClients.h"

namespace NS_SVC
{
	CL_svc_gestionClients::CL_svc_gestionClients(void)
	{
		this->cad = gcnew NS_Composants::CL_CAD();
		this->personne = gcnew NS_Composants::CL_mappTBPERSONNE();
		this->adresse = gcnew NS_Composants::CL_mappTBADRESSE();
	}
	DataSet^ CL_svc_gestionClients::listeClients(String^ dataTableName)
	{
		this->ds = gcnew DataSet();
		this->ds = this->cad->getRows(this->personne->SELECT(), dataTableName);
		return this->ds;
	}
	DataSet^ CL_svc_gestionClients::adressesClient(int id_personne, String^ dataTableName)
	{
		this->ds = gcnew DataSet();
		this->adresse->setIdPersonne(id_personne);
		this->ds = this->cad->getRows(this->adresse->SELECTByIdPersonne(),  dataTableName);
		return this->ds;
	}
	void CL_svc_gestionClients::ajouter(String^ nom, String^ prenom, array<String^>^ lesAdresses)
	{
		int id;
		int i;
		
		this->personne->setNom(nom);
		this->personne->setPrenom(prenom);
		id = this->cad->actionRowsID(this->personne->INSERT());

		for (i = 0; i < lesAdresses->Length - 1; i++)
		{
			this->adresse->setAdresse(lesAdresses[i]); i++;
			this->adresse->setVille(lesAdresses[i]); i++;
			this->adresse->setCp(lesAdresses[i]);
			this->adresse->setIdPersonne(id);
			this->cad->actionRows(this->adresse->INSERT());
		}
	}
	void CL_svc_gestionClients::CL_svc_gestionClients::modifier(int id_personne,String^ nom, String^ prenom, array<String^>^ lesAdresses)
	{
		int i;

		this->personne->setID(id_personne);
		this->personne->setNom(nom);
		this->personne->setPrenom(prenom);
		this->cad->actionRows(this->personne->UPDATE());

		for (i = 0; i < lesAdresses->Length - 1; i++)
		{
			this->adresse->setIdAdresse(Convert::ToInt32(lesAdresses[i])); i++;
			this->adresse->setAdresse(lesAdresses[i]); i++;
			this->adresse->setVille(lesAdresses[i]); i++;
			this->adresse->setCp(lesAdresses[i]);
			this->cad->actionRows(this->adresse->UPDATE());
		}
	}
	void CL_svc_gestionClients::supprimer(int idPersonne)
	{
		this->personne->setID(idPersonne);
		this->cad->actionRows(this->personne->DELETE());
	}
}


