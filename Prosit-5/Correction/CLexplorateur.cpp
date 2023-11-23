

//CLexplorateur.cpp
#include "CLexplorateur.h"

namespace NS_composants
{
	array<String^>^ CLfichier::explorerUnDossier(String^ dossier)
	{
		array<String^>^ file = Directory::GetFiles(dossier); // JPP9
		return file;
	}
	void CLfichier::effacer(String^ fichier)
	{
		System::IO::File::Delete(fichier);
	}
	void CLfichier::copier(String^ fichierSource, String^ fichierDestination)
	{
		String^ nomDeFichierExtension;
		nomDeFichierExtension = System::IO::Path::GetFileName(fichierSource);
		System::IO::File::Copy(fichierSource, fichierDestination + "\\" + nomDeFichierExtension);
	}
}