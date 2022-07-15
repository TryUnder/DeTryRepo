class Drzewo<T>
    {
        public T Value { get; set; }
        public Drzewo<T> Left { get; set; }
        public Drzewo<T> Right { get; set; }

        public Drzewo(T wartosc, Drzewo<T> lewy, Drzewo<T> prawy)
        {
            Value = wartosc;
            Left = lewy;
            Right = prawy;
        }
        
        public void WalkTree()
        {
            if(this.Left != null)
            {
                this.Left.WalkTree();
            }
            Console.WriteLine(this.Value);
            if(this.Right != null)
            {
                Right.WalkTree();
            }
        }
        public int Agregat(Func<T,bool> warunek)
        {
            int count = 0;
            if (warunek(Value) == true)
            {
                count++;
            }
            if (this.Left != null)
            {
                count += this.Left.Agregat(warunek);
            }
            Console.WriteLine(this.Value);
            if (this.Right != null)
            {
                count += Right.Agregat(warunek);
            }
            return count;
        }
    }