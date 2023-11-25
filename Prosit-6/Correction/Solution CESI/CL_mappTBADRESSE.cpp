#include "pch.h"

//CL_mappTBADRESSES.cpp
#include "CL_mappTBADRESSE.h"

namespace NS_Composants
{
	CL_mappTBADRESSE::CL_mappTBADRESSE(void)
	{
		this->id_adresse = -1;
		this->adresse = "RIEN";
		this->cp= "RIEN";
		this->ville = "RIEN";
		this->id_personne = -1;
	}
	String^ CL_mappTBADRESSE::SELECTByIdPersonne(void)
	{
		return "SELECT id_adresse, adresse, ville, cp, id_personne " +
			"FROM TB_ADRESSE " +
			"WHERE(id_personne = " + this->id_personne + ");";
	}
	String^ CL_mappTBADRESSE::INSERT(void)
	{
		return "INSERT INTO TB_ADRESSE(adresse, ville, cp, id_personne) " +
			"VALUES('" + this->adresse + "', '" + this->ville + "', '" + this->cp + "', " + this->id_personne + ");";
	}
	String^ CL_mappTBADRESSE::UPDATE(void)
	{		
		return "UPDATE TB_ADRESSE " +
			"SET adresse ='"+ this->adresse +"', ville ='"+ this->ville +"', cp ='"+ this->cp + "' " +
			"WHERE(id_adresse =  "+ this->id_adresse + "); ";
	}
	String^ CL_mappTBADRESSE::DELETE(void)
	{
		return "DELETE FROM TB_ADRESSE " +
			"WHERE(id_adresse = "+this->id_adresse+");";
	}
	void CL_mappTBADRESSE::setIdAdresse(int IdAdresse)
	{
		if (IdAdresse > 0)this->id_adresse = IdAdresse;
	}
	void CL_mappTBADRESSE::setAdresse(String^ Adresse)
	{
		if (Adresse != "")this->adresse = Adresse;
	}
	void CL_mappTBADRESSE::setCp(String^ Cp)
	{
		if (Cp != "")this->cp = Cp;
	}
	void CL_mappTBADRESSE::setVille(String^ Ville)
	{
		if (Ville != "")this->ville = Ville;
	}
	void CL_mappTBADRESSE::setIdPersonne(int IdPersonne)
	{
		if (IdPersonne >0)this->id_personne = IdPersonne;
	}
	int CL_mappTBADRESSE::getIdAdresse(void)
	{
		return this->id_adresse;
	}
	String^ CL_mappTBADRESSE::getAdresse(void)
	{
		return this->adresse;
	}
	String^ CL_mappTBADRESSE::getCp(void)
	{
		return this->cp;
	}
	String^ CL_mappTBADRESSE::getVille(void)
	{
		return this->ville;
	}
	int CL_mappTBADRESSE::getIdPersonne(void)
	{
		return this->id_personne;
	}
}

