using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonnesEtAdresses
{
    public class MappingSQLPersonne : MappingSQL<Personne>
    {
        public override string Delete(int id)
        {
            return $"DELETE FROM Personne " +
                   $"WHERE(Id = {id})";
        }

        public override string Insert(Personne personne)
        {
            return $"INSERT INTO Personne " +
                   $"(Nom, Prenom) " +
                   $"VALUES('{personne.Nom}', '{personne.Prenom}'); "+
                   $"SELECT CAST(SCOPE_IDENTITY() AS INT) AS LAST_IDENTITY; "; // C.F. https://stackoverflow.com/questions/2601620/why-does-select-scope-identity-return-a-decimal-instead-of-an-integer
        }

        public override string SelectAll()
        {
            return $"SELECT Id, Nom, Prenom " +
                   $"FROM Personne ";
        }

        public override string SelectById(int id)
        {
            return $"SELECT Id, Nom, Prenom " +
                   $"FROM Personne "+
                   $"WHERE id = {id} ";
        }

        public override string Update(Personne personne)
        {
            return $"UPDATE Personne " +
                   $"SET Nom = '{personne.Nom}', Prenom = '{personne.Prenom}' " +
                   $"WHERE(Id = {personne.Id});";
        }
    }
}
