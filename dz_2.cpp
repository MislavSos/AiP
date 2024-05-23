#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;

struct Ucenik
{
    char imePrezime[50];
    float prosjek;
};
bool cmp(const Ucenik &a, const Ucenik &b)
{
    return a.prosjek > b.prosjek;
}
int main()
{
    struct Ucenik ucenici[100];
    int brUcenika = 0;
    fstream datoteka("ucenici.bin", ios::binary | ios::in);
    while(datoteka.read((char*)&ucenici[brUcenika], sizeof(Ucenik)))
    {
        cout << ucenici[brUcenika].imePrezime << " " << ucenici[brUcenika].prosjek << endl;
        brUcenika++;
    }
    datoteka.close();
    int n;
    cout << "Unesite broj ucenika koje hocete unijeti: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Unesite ime i prezime ucenika: ";
        cin.getline(ucenici[brUcenika + i].imePrezime, 50);
        cout << "Unesite prosjek ucenika: ";
        cin >> ucenici[brUcenika + i].prosjek;
        cin.ignore();
    }
    sort(ucenici, ucenici + brUcenika + n, cmp);
    for (int i = 0; i < brUcenika; i++)
    {
        cout << ucenici[i].imePrezime << " " << ucenici[i].prosjek << endl;
    }
    datoteka.open("ucenici.bin", ios::binary | ios::out | ios::trunc);
    datoteka.write((char *)ucenici, sizeof(Ucenik) * (brUcenika + n));
    datoteka.close();
    return 0;
}