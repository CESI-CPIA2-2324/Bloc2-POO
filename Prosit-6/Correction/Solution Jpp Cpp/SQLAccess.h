#pragma once

#include "ISQLAccess.h"
using namespace System;
using namespace System::Data;

namespace PersonnesEtAdresses
{
	public ref class SQLAccess : public ISQLAccess
	{
	private:
		String^ _connectionString;
	public:
		SQLAccess(String^connectionString);

		DataSet^ GetRows(String^sql, String^dataTableName)  override;

		int ExecuteScalar(String^sql)  override;

		void ExecuteNonQuery(String^sql)  override;
	};
}
