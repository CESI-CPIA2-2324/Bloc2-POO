using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonnesEtAdresses
{
    public class MappingSQLAdresse : MappingSQL<Adresse>
    {
        public override string Delete(int id)
        {
            return $"DELETE FROM Adresse " +
                   $"WHERE(Id = {id})";
        }

        public override string Insert(Adresse adresse)
        {
            return $"INSERT INTO Adresse(CodePostal, Ville, PersonneId) " +
                   $"VALUES('{adresse.CodePostal}', '{adresse.Ville}', '{adresse.PersonneId}'); "+
                   $"SELECT CAST(SCOPE_IDENTITY() AS INT) AS LAST_IDENTITY; "; // C.F. https://stackoverflow.com/questions/2601620/why-does-select-scope-identity-return-a-decimal-instead-of-an-integer
        }

        public override string SelectAll()
        {
            return $"SELECT Id, CodePostal, Ville, PersonneId " +
                   $"FROM Adresse ";
        }

        public override string SelectById(int id)
        {
            return $"SELECT Id, CodePostal, Ville, PersonneId " +
                   $"FROM Adresse " +
                   $"WHERE (Id= {id})";
        }

        public override string Update(Adresse adresse)
        {
            return $"UPDATE Adresse " +
                   $"SET CodePostal ='{adresse.CodePostal}', Ville ='{adresse.Ville}', PersonneId = '{adresse.PersonneId}' " +
                   $"WHERE(Id = {adresse.Id}) ";
        }

        public string SelectByPersonneId(int personneId)
        {
            return $"SELECT Id, CodePostal, Ville, PersonneId " +
                   $"FROM Adresse " +
                   $"WHERE (PersonneId= {personneId})";
        }
    }
}
