using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonnesEtAdresses
{
    public class GestionPersonnes : IRepository
    {
        private readonly ISQLAccess _sqlAccess;
        private readonly MappingSQLPersonne _mappingSQLPersonne = new MappingSQLPersonne();
        private readonly MappingSQLAdresse _mappingSQLAdresse = new MappingSQLAdresse();

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="sqlAccess"></param>
        public GestionPersonnes(ISQLAccess sqlAccess)
        {
            _sqlAccess = sqlAccess;
        }

        private Personne ConvertDataRowToPersonne(DataRow dataRow)
        {
            var result = new Personne();
            result.Id = (int)dataRow["Id"];
            result.Nom = (string)dataRow["Nom"];
            result.Prenom = (string)dataRow["Prenom"];
            return result;
        }

        private Adresse ConvertDataRowToAdresse(DataRow dataRow)
        {
            var result = new Adresse();
            result.Id = (int)dataRow["Id"];
            result.CodePostal = (string)dataRow["CodePostal"];
            result.Ville = (string)dataRow["Ville"];
            result.PersonneId = (int)dataRow["PersonneId"];
            return result;
        }

        private IList<T> ConvertDataRowCollectionToList<T>(DataRowCollection dataRows, Func<DataRow, T> convertFunc)
        {
            var result = new List<T>();
            foreach (var dataRow in dataRows)
                result.Add(convertFunc((DataRow)dataRow));
            return result;
        }

        private IList<Personne> ConvertPersonnes(DataRowCollection dataRows)
        {
            return ConvertDataRowCollectionToList(dataRows, ConvertDataRowToPersonne);
        }
        private IList<Adresse> ConvertAdresses(DataRowCollection dataRows)
        {
            return ConvertDataRowCollectionToList(dataRows, ConvertDataRowToAdresse);
        }

        public IList<Personne> GetPersonnes()
        {
            string sql = _mappingSQLPersonne.SelectAll();
            var dataset = _sqlAccess.GetRows(sql, "Personnes");
            var dataRows = dataset.Tables["Personnes"].Rows;
            return ConvertPersonnes(dataRows);
        }

        public IList<Adresse> GetAdresses(int personneId)
        {
            string sql = _mappingSQLAdresse.SelectByPersonneId(personneId);
            var dataset = _sqlAccess.GetRows(sql, "Adresses");
            var dataRows = dataset.Tables["Adresses"].Rows;
            return ConvertAdresses(dataRows);
        }

        public int Add(Personne personne, IList<Adresse> adresses)
        {
            string sql = _mappingSQLPersonne.Insert(personne);
            var personneId = (int)_sqlAccess.ExecuteScalar(sql);
            InsertAdressesFromPersonne(adresses, personneId);
            return personneId;
        }

        private void InsertAdressesFromPersonne(IList<Adresse> adresses, int personneId)
        {
            if (adresses != null)
                foreach (var adresse in adresses)
                {
                    adresse.PersonneId = personneId;
                    string sql = _mappingSQLAdresse.Insert(adresse);
                    _sqlAccess.ExecuteScalar(sql);
                }
        }

        public void Update(Personne personne, IList<Adresse> adresses)
        {
            string sql = _mappingSQLPersonne.Update(personne);
            DeleteAllAdressesFromAPersonne(personne.Id);
            InsertAdressesFromPersonne(adresses, personne.Id);
            _sqlAccess.ExecuteNonQuery(sql);
        }

        public void Delete(int personneId)
        {
            DeleteAllAdressesFromAPersonne(personneId);

            string sql = _mappingSQLPersonne.Delete(personneId);
            _sqlAccess.ExecuteNonQuery(sql);
        }

        private void DeleteAllAdressesFromAPersonne(int personneId)
        {
            var adresses = GetAdresses(personneId);
            foreach (var adresse in adresses)
            {
                string sql = _mappingSQLAdresse.Delete(adresse.Id);
                _sqlAccess.ExecuteNonQuery(sql);
            }
        }
    }
}
