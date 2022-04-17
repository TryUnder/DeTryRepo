public class Generics_1{
    public void SetName<T>(){
        var typeT = typeof(T);
        Name = typeT.Name;
    }

    public class GenericList<T>{
        public void Add(T input) {}
    }

    public class Abc<TObjectPerson, TClass>
        where TObjectPerson : Person
        where TClass : class
    {
        private TObjectPerson _type;
        public int Id { get; set; }
        public string Name { get; set; }
        public TClass Type { get; set; }
    }

    public static void Main(){
        GenericList<int> list1 = new GenericList<int>();
        list1.Add(1);

        GenericList<string> list2 = new GenericList<string>();
        list2.Add("");

        GenericList<Person> list3 = new GenericList<Person>();
        list3.Add(new Person());

        Abc<Person, Subject> abc = new Abc<Person, Subject>();
        abc.SetName<Stream>();
    }

}