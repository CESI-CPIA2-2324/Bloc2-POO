//CL_svc_gestionClient.h
#pragma once
#include "CL_CAD.h"
#include "CL_mappTBPERSONNE.h"
#include "CL_mappTBADRESSE.h"

using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

namespace NS_SVC
{
	ref class CL_svc_gestionClients
	{
	private:
		NS_Composants::CL_CAD^ cad;
		NS_Composants::CL_mappTBPERSONNE^ personne;
		NS_Composants::CL_mappTBADRESSE^ adresse;
		DataSet^ ds;
	public:
		CL_svc_gestionClients(void);
		DataSet^ listeClients(String^);
		DataSet^ adressesClient(int, String^);
		void ajouter(String^, String^, array<String^>^);
		void modifier(int, String^, String^, array<String^>^);
		void supprimer(int);
	};
}
