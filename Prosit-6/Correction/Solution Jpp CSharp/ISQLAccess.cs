using System.Data;

namespace PersonnesEtAdresses
{
    public interface ISQLAccess
    {
        void ExecuteNonQuery(string sql);
        int ExecuteScalar(string sql);
        DataSet GetRows(string sql, string dataTableName);
    }
}