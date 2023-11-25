using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonnesEtAdresses
{
    public abstract class MappingSQL<T>
    {
        public abstract string SelectById(int id);
        public abstract string SelectAll();
        public abstract string Update(T entity);
        public abstract string Delete(int id);
        public abstract string Insert(T entity);
    }
}
