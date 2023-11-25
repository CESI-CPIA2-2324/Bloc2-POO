#pragma once

#include "Adresse.h"
#include "MappingSQL.h"
using namespace System;

namespace PersonnesEtAdresses
{
	public ref class MappingSQLAdresse : public MappingSQL<Adresse^>
	{
	public:
		String^ Delete(int id) override;

		String^ Insert(Adresse ^adresse) override;

		String^ SelectAll() override;

		String^ SelectById(int id) override;

		String^ Update(Adresse ^adresse) override;

		String^ SelectByPersonneId(int personneId);
	};
}
