using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonnesEtAdresses
{
    public class SQLAccess : ISQLAccess
    {
        private readonly string _connectionString;
        public SQLAccess(string connectionString)
        {
            _connectionString = connectionString;
        }

        public DataSet GetRows(string sql, string dataTableName)
        {
            DataSet result = new DataSet();
            using (var sqlConnection = new SqlConnection(_connectionString))
            using (var sqlCommand = new SqlCommand(sql, sqlConnection))
            using (var sqlDataAdapter = new SqlDataAdapter(sqlCommand))
            {
                sqlDataAdapter.Fill(result, dataTableName);
            }
            return result;
        }

        public int ExecuteScalar(string sql)
        {
            using (var sqlConnection = new SqlConnection(_connectionString))
            using (var sqlCommand = new SqlCommand(sql, sqlConnection))
            {
                sqlConnection.Open();
                var result = sqlCommand.ExecuteScalar();
                return (int)result;
            }
        }

        public void ExecuteNonQuery(string sql)
        {
            using (var sqlConnection = new SqlConnection(_connectionString))
            using (var sqlCommand = new SqlCommand(sql, sqlConnection))
            {
                sqlConnection.Open();
                sqlCommand.ExecuteNonQuery();
            }
        }
    }
}
