using System.Collections.Generic;
using System.Linq;
using System;

namespace Assignment_2{
    public static class Crud{
        public static IContainer Add<T>(this IContainer c, T o){
            c.Set<T>?.Add(o);
            return c;
        }

        public static IList<T> Set<T>(this IContainer c){
            return (c.GetType().GetProperties().FirstOrDefault(i => i.PropertyType == typeof(IList<T>))?.GetValue(c)) as IList<T>;
        }
        public static IList<T> GetList<T>(this IContainer c, Func<T, bool> lambda){
            return c.Set<T>?.Where<T>(lambda)?.ToList<T>();
        }
    }
}

// doesn't compile