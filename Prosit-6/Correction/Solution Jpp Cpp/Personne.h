#pragma once

using namespace System;

namespace PersonnesEtAdresses
{
	public ref class Personne
	{
	private:
		int _id = 0;
		String^ _nom;
		String^ _prenom;
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

		property String^ Nom
		{
			String^ get()
			{
				return _nom;
			}
			void set(String^ value)
			{
				_nom = value;
			}
		};		
		
		property String^ Prenom
		{
			String^ get()
			{
				return _prenom;
			}
			void set(String^ value)
			{
				_prenom = value;
			}
		};
	};
}
