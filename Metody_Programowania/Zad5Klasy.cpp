


int main (int argc, char* argv[])try {

  if (argc !=2) throw int(0);
  if (strlen(argv[1]) < 5 ) throw int(1);
  if (string(argv[1]+(strlen(argv[1])-3))!="txt") throw 2 ;

  ifstream file(argv[1]);
  if(!file) throw int (3);
  {
    polygon poly;
    try{
      poly.read(file);
      cout<< "obwód : " << poly.obwod()<< endl;
      cout<< "pole  : " << poly.pole()<< endl;
    }
    catch ( const string& e ){ cout << e << endl;}
    catch ( const blad&   e ){ cout << e ;}
    file.close();
  }


  return 0;
}
catch (int err){
  switch (err) {
    case 0: cout << err <<": Zła liczba parametrów programu.\n";
    break;
    case 1: cout << err <<": Zła nazwa pliku z danymi.\n";
    break;
    case 2: cout << err <<": Złe rozszerzenie pliku z danymi - musi być *.txt .\n";
    break;
    case 3: cout << err <<": Brak pliku o nazwie "<< argv[1] << " .\n";
  }
}
catch ( ... ) { cout << "Nieznana sytuacja wyjątkowa.\n"; }
