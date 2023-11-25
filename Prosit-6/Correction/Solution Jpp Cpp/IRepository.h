#pragma once

#include "Adresse.h"
#include "Personne.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;

namespace PersonnesEtAdresses
{
	public ref class IRepository abstract
	{
	public:
		virtual int Add(Personne^ personne, List<Adresse^ >^ adresses) = 0;
		virtual void Delete(int personneId) = 0;
		virtual List<Adresse^>^ GetAdresses(int personneId) = 0;
		virtual List<Personne^ >^ GetPersonnes() = 0;
		virtual void Update(Personne^ personne, List<Adresse^ >^ adresses) = 0;
	};
}
