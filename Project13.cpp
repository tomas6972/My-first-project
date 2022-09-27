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
    vector <string> var, pav;
    vector <int> egz;
    vector <float> vidurkis, mediana;
};
studentas* studentas1;

int main()
{
    int count, pazymis, suma, kiekis, o, egzaminas;
    vector<int> pazymiai;
    cout << "Iveskite studentu skaiciu  ";
    cin >> count;
    string atsakymas2, vardas, pavarde;

    studentas tomas;

    for (int i = 0; i < count; i++)
    {
        o = 1;
        kiekis = 0;
        suma = 0;
        string atsakymas1;

        cout << "Iveskite varda "; cin >> vardas;
        tomas.var.push_back(vardas);
        cout << "Iveskite pavarde"; cin >> pavarde;
        tomas.pav.push_back(pavarde);

        cout << "ar norite sugeneruoti pazymius automatiskai (t/n)"; cin >> atsakymas1;
        if (atsakymas1 == "n") {
            cout << "Iveskite egzamino pazymi"; cin >> egzaminas;
            tomas.egz.push_back(egzaminas);
            while (o != 0) {

                cout << "iveskite   pazymi  "; cin >> pazymis;

                suma += pazymis;
                pazymiai.push_back(pazymis);
                kiekis += 1;
                cout << "ar norite testi yes(1),no(0)"; cin >> o;
            }
            tomas.vidurkis.push_back(suma / kiekis);
            if (pazymiai.size() == 2) {
                tomas.mediana.push_back((pazymiai[0] + pazymiai[1]) / 2);

            }
            if (pazymiai.size() % 2 != 0) {
                tomas.mediana.push_back(pazymiai[pazymiai.size() / 2]);

            }
            if (pazymiai.size() % 2 == 0) {

                tomas.mediana.push_back(pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]);

            }
            if (pazymiai.size() == 1) {
                tomas.mediana.push_back(pazymiai[0]);

            }
            for (int i = 0; i < pazymiai.size(); i++) {
                pazymiai.pop_back();

            }
        }
        if (atsakymas1 == "t") {
            srand(time(0));

            for (int x = 1; x < 2; x++) {
                tomas.egz.push_back(rand() % 11);

            }
            for (int x = 1; x < 2; x++) {
                kiekis = rand() % 11;
            }
            for (int i = 0; i < kiekis; i++) {

                pazymis = rand() % 11;
                pazymiai.push_back(pazymis);

                suma += pazymis;
            }

            tomas.vidurkis.push_back(suma / kiekis);
            if (pazymiai.size() == 2) {
                tomas.mediana.push_back((pazymiai[0] + pazymiai[1]) / 2);

            }
            if (pazymiai.size() % 2 != 0) {
                tomas.mediana.push_back(pazymiai[pazymiai.size() / 2]);

            }
            if (pazymiai.size() % 2 == 0) {

                tomas.mediana.push_back(pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]);

            }
            if (pazymiai.size() == 1) {
                tomas.mediana.push_back(pazymiai[0]);

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
            printf("%15s %15s", tomas.var[i].c_str(), tomas.pav[i].c_str()), printf("%23.2f", tomas.egz[i] * 0.4 + tomas.vidurkis[i] * 0.6); cout << endl;

        }
    }
    if (atsakymas2 == "m") {
        printf("%15s %15s", "Vardas", "Pavarde"), printf("%30s", "Galutinis Pazymis"); cout << endl;
        cout << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < count; i++)
        {
            printf("%15s %15s", tomas.var[i].c_str(), tomas.pav[i].c_str()), printf("%23.2f", tomas.egz[i] * 0.4 + tomas.mediana[i] * 0.6); cout << endl;

        }
    }
    
    return 0;
}