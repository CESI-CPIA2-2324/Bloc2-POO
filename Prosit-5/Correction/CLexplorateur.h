//CLexplorateur.h

 #pragma once

using namespace System::IO;
using namespace System;

namespace NS_composants
{
	ref class CLfichier
	{
	public:
		//array<String^> explorerUnDossier(String^); // JPP1
		array<String^>^ CLfichier::explorerUnDossier(String^ dossier); // JPP1
		void effacer(String^);
		void copier(String^,String^);
	};
}
