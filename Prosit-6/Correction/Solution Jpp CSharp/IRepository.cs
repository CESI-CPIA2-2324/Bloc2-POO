using System.Collections.Generic;

namespace PersonnesEtAdresses
{
    public interface IRepository
    {
        int Add(Personne personne, IList<Adresse> adresses);
        void Delete(int personneId);
        IList<Adresse> GetAdresses(int personneId);
        IList<Personne> GetPersonnes();
        void Update(Personne personne, IList<Adresse> adresses);
    }
}