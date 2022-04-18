using System;
using System.Collections.Generic;
namespace Przyklad{
    public static class Extension_methods_2{
        public static void SetValue(this List<int> list, int val){}

        public static void Main(){
            List<int> l = new List<int>();
            l.SetValue(2);
        }
    }
}