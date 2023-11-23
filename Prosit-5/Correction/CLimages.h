
//CLimages.h
#pragma once

using namespace System;
namespace NS_composants
{
	public ref class CLimages
	{
	public:
		//System::Drawing acquisitionImage(String^); // JPP2
		System::Drawing::Bitmap^ CLimages::acquisitionImage(String^ fichier); // JPP2
	};
}