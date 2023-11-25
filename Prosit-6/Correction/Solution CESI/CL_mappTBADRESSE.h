//CL_mapp_TBADRESSE.h
#pragma once
using namespace System;

namespace NS_Composants
{
	ref class CL_mappTBADRESSE
	{
	private:
		int id_adresse;
		String^ adresse;
		String^ cp;
		String^ ville;
		int id_personne;
	public:
		CL_mappTBADRESSE(void);
		String^ SELECTByIdPersonne(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setIdAdresse(int);
		void setAdresse(String^);
		void setCp(String^);
		void setVille(String^);
		void setIdPersonne(int);
		int getIdAdresse(void);
		String^ getAdresse(void);
		String^ getCp(void);
		String^ getVille(void);
		int getIdPersonne(void);
	};
}
