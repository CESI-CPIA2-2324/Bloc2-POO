

//CLservicesFichier.h
#pragma once
#include "CLexplorateur.h"

using namespace System;

namespace NS_services
{
	ref class CLserviceFichier
	{
	private:
		NS_composants::CLfichier^ fichier;
	public:
		CLserviceFichier(void);
		void copier(array<String^>^, String^);
		void copierEffacer(array<String^>^, String^);
		void effacer(array<String^>^);
		array<String^>^ explorer(String^);
	};
}