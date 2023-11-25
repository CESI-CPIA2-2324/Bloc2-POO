#include "pch.h"
                                   //CL_mappTBPERSONNE.cpp
#include "CL_mappTBPERSONNE.h"

namespace NS_Composants
{
	CL_mappTBPERSONNE::CL_mappTBPERSONNE(void)
	{
		this->id_personne = -1;
		this->nom = "RIEN";
		this->prenom = "RIEN";
	}
	String^ CL_mappTBPERSONNE::SELECT(void)
	{
		return "SELECT id_personne, nom, prenom "+
			   "FROM TB_PERSONNE;";
	}
	String^ CL_mappTBPERSONNE::INSERT(void)
	{
		return "INSERT INTO TB_PERSONNE " +
			   "(nom, prenom) " +
			   "VALUES('" + this->getNom() + "', '" + this->getPrenom() + "');SELECT @@IDENTITY;";
	}
	String^ CL_mappTBPERSONNE::UPDATE(void)
	{
		return "UPDATE TB_PERSONNE " +
			   "SET nom = '" + this->getNom() + "', prenom = '" + this->getPrenom() + "' " +
			   "WHERE(id_personne = "+ this->getId() + ");";
	}
	String^ CL_mappTBPERSONNE::DELETE(void)
	{
		return "DELETE FROM TB_PERSONNE " +
			   "WHERE(id_personne = " + this->getId() + ");";
	}
	void CL_mappTBPERSONNE::setID(int id_personne)
	{
		if (id_personne > 0)
		{
			this->id_personne = id_personne;
		}
	}
	void CL_mappTBPERSONNE::setPrenom(String^ prenom)
	{
		if (prenom !="")
		{
			this->prenom = prenom;
		}
	}
	void CL_mappTBPERSONNE::setNom(String^ nom)
	{
		if (nom != "")
		{
			this->nom = nom;
		}
	}
	int CL_mappTBPERSONNE::getId(void)
	{
		return this->id_personne;
	}
	String^ CL_mappTBPERSONNE::getNom(void) 
	{
		return this->nom;
	}
	String^ CL_mappTBPERSONNE::getPrenom(void)
	{
		return this->prenom;
	}
}

