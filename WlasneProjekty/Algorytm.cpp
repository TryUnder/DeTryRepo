#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void filtr(ifstream& file, ofstream& fout)
{
    if (!file.good() || !fout.good())
    {
        cerr << "BLAD OTWARCIA PLIKU" << endl;
    }
    string line;
    string wyraz;
    int pos_n;
    int pos_s = 0;
    int licznik = 0;
    while (!file.eof())
    {
        pos_s = 0;
        licznik = 0;
        do
        {
            getline(file, line);
        } while (line.empty());
        for (size_t i = 0; i < line.length(); i++)
        {
            wyraz += " ";
            if (isspace(line.at(i)))
            {
                pos_n = i;
                int j = 0;
                for (pos_s; pos_s < pos_n; pos_s++)
                {
                    wyraz.at(j) = line.at(pos_s);
                    j++;
                }
                if (licznik == 0) { wyraz.resize(wyraz.length() - 1); licznik++; }
                pos_s = pos_n;
                fout << wyraz;
                wyraz.clear();
            }
        }
        if (file.eof())fout.close();
        else fout << endl;
    }
    fout.close();
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Zla liczba parametrow uruchomienia programu" << endl;
        cout << "argv[1] - in.txt" << endl;
        cout << "argv[2] - out.txt" << endl;
    }
    ifstream fin;
    fin.open(argv[1]);
    ofstream fout;
    fout.open(argv[2]);
    filtr(fin, fout);

}