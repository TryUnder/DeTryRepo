using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    public class Lista_Laczona<T> : IEnumerable<T> where T : IComparable
    {
        public T Node { get; }
        public Lista_Laczona<T>? Next { get; }

        public Lista_Laczona(T node, Lista_Laczona<T>? next)
        {
            Node = node;
            Next = next;
        }


        public IEnumerator<T> GetEnumerator()
        {
            var a = this;
            while (true)
            {
                yield return a.Node;
                if (a.Next != null)
                {
                    a = a.Next;
                }
                else
                {
                    yield break;
                }
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            // this will invoke the public generic
            // version, so there is no recursion
            return this.GetEnumerator();
        }

        public bool CzyWszystkie(Expression<Func<T, bool>> lambda)
        {
            var la2 = lambda.Compile();
            return this.All(la2);
        }

        public T? Maksymalny()
        {
            return this.Max();
        }
    }
}

// Program

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq.Expressions;
using System.Collections;
namespace Test
{
    class Program
    {

        public static void Main()
        {
            var my_li = new Lista_Laczona<int>(4, null);
            var my_li2 = new Lista_Laczona<int>(5, my_li);
            var my_li3 = new Lista_Laczona<int>(4, my_li2);

            bool iftr = my_li3.CzyWszystkie(x => x == 5);
            Console.WriteLine(iftr);
            Console.WriteLine(my_li3.Count());
            Console.WriteLine(my_li3.Maksymalny());
        }
    }
}
