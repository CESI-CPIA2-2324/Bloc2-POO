

//CLserviceImage.h
#pragma once
#include "CLimages.h"

namespace NS_services
{
	ref class CLserviceImage
	{
	private:
		NS_composants::CLimages^ image;
	public:
		CLserviceImage(void);
		System::Drawing::Bitmap^ lireImage(String^);
	};
}
