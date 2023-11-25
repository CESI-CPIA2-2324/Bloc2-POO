#pragma once

using namespace System;
using namespace System::Data;

namespace PersonnesEtAdresses
{
	public ref class ISQLAccess abstract
	{
	public:
		virtual void ExecuteNonQuery(String^ sql) = 0;
		virtual int ExecuteScalar(String^ sql) = 0;
		virtual DataSet^ GetRows(String^ sql, String^ dataTableName) = 0;
	};
}
