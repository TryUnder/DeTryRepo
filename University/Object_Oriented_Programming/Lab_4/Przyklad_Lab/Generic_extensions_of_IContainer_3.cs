using System;
using System.Collections.Generic;

namespace Some_Example{
    public class Generic_extensions_of_IContainer_3{
        public static IContainer Add<TObjectType>(this IContainer container, TObjectType obj){
            container.Set<TObjectType>()?.Add(obj);
            return container;
        }

        public static IList<TObjectType> Set<TObjectType>(this IContainer containerObject){
            var containerObjectType = containerObject.GetType();
            var propertyInfo = containerObjectType.GetProperties().
                FirstOrDefault(propertyInfo => propertyType == typeof(IList<TObjectType>));
            var value = propertyInfo?.GetValue(containerObject);
            return value as IList<TObjectType>;
        }

        public static void Main(){

        }
    }
}