#pragma once

#include "MappingSQL.h"
#include "Personne.h"
using namespace System;

namespace PersonnesEtAdresses
{
	public ref class MappingSQLPersonne : public MappingSQL<Personne^>
	{
	public:
		String^ Delete(int id) override;

		String^ Insert(Personne ^personne) override;

		String^ SelectAll() override;

		String^ SelectById(int id) override;

		String^ Update(Personne ^personne) override;
	};
}
