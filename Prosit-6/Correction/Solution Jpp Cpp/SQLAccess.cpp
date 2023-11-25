#include "pch.h"
#include "SQLAccess.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::Sql;
using namespace System::Data::SqlClient;

namespace PersonnesEtAdresses
{

	SQLAccess::SQLAccess(String^ connectionString) : _connectionString(connectionString)
	{
	}

	DataSet^ SQLAccess::GetRows(String^ sql, String^ dataTableName)
	{
		DataSet^ result = gcnew DataSet();
		SqlConnection^ sqlConnection = gcnew SqlConnection(_connectionString);
		SqlCommand^ sqlCommand = gcnew SqlCommand(sql, sqlConnection);
		SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter(sqlCommand);
		sqlDataAdapter->Fill(result, dataTableName);
		delete sqlConnection;
		return result;
	}

	int SQLAccess::ExecuteScalar(String^ sql)
	{
		SqlConnection^ sqlConnection = gcnew SqlConnection(_connectionString);
		SqlCommand^ sqlCommand = gcnew SqlCommand(sql, sqlConnection);
		sqlConnection->Open();
		Object^ result = sqlCommand->ExecuteScalar();
		delete sqlConnection;
		return safe_cast<int>(result);
	}

	void SQLAccess::ExecuteNonQuery(String^ sql)
	{
		SqlConnection^ sqlConnection = gcnew SqlConnection(_connectionString);
		SqlCommand^ sqlCommand = gcnew SqlCommand(sql, sqlConnection);
		sqlConnection->Open();
		sqlCommand->ExecuteNonQuery();
		delete sqlConnection;
	}
}
