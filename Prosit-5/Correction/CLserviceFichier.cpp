

//CLserviceFichier.cpp
#include "CLserviceFichier.h"

namespace NS_services
{
	CLserviceFichier::CLserviceFichier(void)
	{
		this->fichier = gcnew NS_composants::CLfichier();
	}
	void CLserviceFichier::copier(array<String^>^ fichiersSources, String^ destination)
	{
		int i;

		i = 0;
		for (i = 0; i < fichiersSources->Length; i++)
		{
			this->fichier->copier(fichiersSources[i], destination);
		}
	}
	void CLserviceFichier::copierEffacer(array<String^>^ fichiersSources, String^ fichierDestination)
	{
		this->copier(fichiersSources, fichierDestination);
		this->effacer(fichiersSources);
	}
	void CLserviceFichier::effacer(array<String^>^ fichiersSources)
	{
		int i;

		i = 0;
		for (i = 0; i < fichiersSources->Length; i++)
		{
			this->fichier->effacer(fichiersSources[i]);
		}
	}
	array<String^>^ CLserviceFichier::explorer(String^ dossier)
	{
		return this->fichier->explorerUnDossier(dossier);
	}
}