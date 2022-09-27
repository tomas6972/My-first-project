#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include<ctime>;
#include <algorithm>
#include<vector>


using namespace std;

struct studentas
{
    string var, pav;
    int egz;
    float vidurkis, mediana;
};
studentas* studentas1;

int main()
{
    int count, pazymis, suma, kiekis, o;


    vector<int> pazymiai;
    cout << "Iveskite studentu skaiciu  ";
    cin >> count;
    
    
    string atsakymas2;

    studentas1 = new studentas;

    

    for (int i = 0; i < count; i++)
    {
        o = 1;
        kiekis = 0;
        suma = 0;
        string atsakymas1;

        cout << "Iveskite varda "; cin >> studentas1[i].var;
        cout << "Iveskite pavarde"; cin >> studentas1[i].pav;
        cout << "ar norite sugeneruoti pazymius automatiskai (t/n)"; cin >> atsakymas1;
        if (atsakymas1 == "n") {
            cout << "Iveskite egzamino pazymi"; cin >> studentas1[i].egz;
            while (o != 0) {

                cout << "iveskite   pazymi  "; cin >> pazymis;

                suma += pazymis;
                pazymiai.push_back(pazymis);
                kiekis += 1;
                cout << "ar norite testi yes(1),no(0)"; cin >> o;
            }
            studentas1[i].vidurkis = suma / kiekis;
            if (pazymiai.size() == 2) {
                studentas1[i].mediana = (pazymiai[0] + pazymiai[1]) / 2;

            }
            if (pazymiai.size() % 2 != 0) {
                studentas1[i].mediana = pazymiai[pazymiai.size() / 2];

            }
            if (pazymiai.size() % 2 == 0) {

                studentas1[i].mediana = pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1];

            }
            if (pazymiai.size() == 1) {
                studentas1[i].mediana = pazymiai[0];

            }
            for (int i = 0; i < pazymiai.size(); i++) {
                pazymiai.pop_back();

            }
        }
        if (atsakymas1 == "t") {
            srand(time(0));

            for (int x = 1; x < 2; x++) {
                studentas1[i].egz = rand() % 11;

            }
            for (int x = 1; x < 2; x++) {
                kiekis = rand() % 11;
            }
            for (int i = 0; i < kiekis; i++) {

                pazymis = rand() % 11;
                pazymiai.push_back(pazymis);

                suma += pazymis;
            }

            studentas1[i].vidurkis = suma / kiekis;
            if (pazymiai.size() == 2) {
                studentas1[i].mediana = (pazymiai[0] + pazymiai[1]) / 2;

            }
            if (pazymiai.size() % 2 != 0) {
                studentas1[i].mediana = pazymiai[pazymiai.size() / 2];

            }
            if (pazymiai.size() % 2 == 0) {

                studentas1[i].mediana = pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1];

            }
            if (pazymiai.size() == 1) {
                studentas1[i].mediana = pazymiai[0];

            }
            for (int i = 0; i < pazymiai.size(); i++) {
                pazymiai.pop_back();

            }

        }



        cout << endl;
    }cout << endl;

    cout << " ar norite galutini pazymi skaiciuoti su vidurkiu ar mediana (v/m)"; cin >> atsakymas2;
    if (atsakymas2 == "v") {
        printf("%15s %15s", "Vardas", "Pavarde"), printf("%30s", "Galutinis Pazymis"); cout << endl;
        cout << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < count; i++)
        {
            printf("%15s %15s", studentas1[i].var.c_str(), studentas1[i].pav.c_str()), printf("%23.2f", studentas1[i].egz * 0.4 + studentas1[i].vidurkis * 0.6); cout << endl;

        }
    }
    if (atsakymas2 == "m") {
        printf("%15s %15s", "Vardas", "Pavarde"), printf("%30s", "Galutinis Pazymis"); cout << endl;
        cout << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < count; i++)
        {
            printf("%15s %15s", studentas1[i].var.c_str(), studentas1[i].pav.c_str()), printf("%23.2f", studentas1[i].egz * 0.4 + studentas1[i].mediana * 0.6); cout << endl;

        }
    }
    delete[] studentas1;
    return 0;
}
