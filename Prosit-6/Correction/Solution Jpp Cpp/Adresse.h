#pragma once

using namespace System;

namespace PersonnesEtAdresses
{
	public ref class Adresse
	{
	private:
		int _id = 0;
		String^ _codePostal;
		String^ _ville;
		int _personneId = 0;

	public:
		property int Id
		{
			int get()
			{
				return _id;
			}
			void set(int value)
			{
				_id = value;
			}
		};

		property String^ CodePostal
		{
			String^ get()
			{
				return _codePostal;
			}
			void set(String^ value)
			{
				_codePostal = value;
			}
		};

		property String^ Ville
		{
			String^ get()
			{
				return _ville;
			}
			void set(String^ value)
			{
				_ville = value;
			}
		};

		property int PersonneId
		{
			int get()
			{
				return _personneId;
			}
			void set(int value)
			{
				_personneId = value;
			}
		};


	};
}
