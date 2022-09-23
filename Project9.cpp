

#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<iomanip>;
#include<ctime>;
using namespace std;



struct Studentas {
    string var, pav;
    int i = 0, paz, o;
    vector <string> vardai, pavardes;
    vector <int> pazymiai, egzaminas;
    double suma, k, pazymis, temp1;
    vector <double> mediana, vidurkis;
    void ivedimas() {
        cout << "iveskite varda  "; cin >> var;
        cout << "iveskite pavarde  "; cin >> pav;
        vardai.push_back(var);
        pavardes.push_back(pav);


    }
    void ranka() {


        cout << "iveskite egzamino pazymi  "; cin >> paz;
        egzaminas.push_back(paz);
        suma = 0;
        o = 1;
        k = 0;

        while (o != 0) {

            cout << "iveskite   pazymi  "; cin >> pazymis;

            suma += pazymis;
            k += 1;

            pazymiai.push_back(pazymis);
            cout << "ar norite testi yes(1),no(0)"; cin >> o;
        }
        sort(pazymiai.begin(), pazymiai.end());
        for (const auto& i : pazymiai);
        vidurkis.push_back(suma / k);
        if (pazymiai.size() == 2) {
            temp1 = (pazymiai[0] + pazymiai[1]) / 2;
            mediana.push_back(temp1);
            temp1 = 0;
        }
        if (pazymiai.size() == 1) {
            temp1 = pazymiai[0];
            mediana.push_back(temp1);
            temp1 = 0;
        }
        if (pazymiai.size() % 2 != 0) {
            temp1 = pazymiai[pazymiai.size() / 2];
            mediana.push_back(temp1);
            temp1 = 0;
        }
        if (pazymiai.size() % 2 == 0) {

            temp1 = pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1];
            mediana.push_back(temp1);
            temp1 = 0;
        }
        for (int i = 0; i < pazymiai.size(); i++) {
            pazymiai.pop_back();
        }
        i += 1;

    }

    void automatiskai() {
        srand(time(0));

        for (int x = 1; x < 2; x++) {
            paz = rand() % 11;
            egzaminas.push_back(paz);
        }
        for (int x = 1; x < 2; x++) {
            k = rand() % 11;
        }
        suma = 0;

        for (int i = 0; i < k; i++) {

            pazymis = rand() % 11;
            pazymiai.push_back(pazymis);
            suma += pazymis;
        }
        vidurkis.push_back(suma / k);
        sort(pazymiai.begin(), pazymiai.end());
        for (const auto& i : pazymiai);

        if (pazymiai.size() == 2) {
            temp1 = (pazymiai[0] + pazymiai[1]) / 2;
            egzaminas.push_back(paz);
            temp1 = 0;
        }
        if (pazymiai.size() % 2 != 0) {
            temp1 = pazymiai[pazymiai.size() / 2];
            egzaminas.push_back(paz);
            temp1 = 0;
        }
        if (pazymiai.size() % 2 == 0) {

            temp1 = pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1];
            egzaminas.push_back(paz);
            temp1 = 0;
        }
        if (pazymiai.size() == 1) {
            temp1 = pazymiai[0];
            egzaminas.push_back(paz);
            temp1 = 0;
        }
        for (int i = 0; i < pazymiai.size(); i++) {
            pazymiai.pop_back();

        }
        i += 1;




    }



};
int main()
{
    int skaicius;
    string atsakymas1, atsakymas2;
    Studentas tomas;
    cout << "iveskite studentu skaiciu "; cin >> skaicius;
    for (int i = 0; i < skaicius; i++) {
        tomas.ivedimas();
        cout << "ar norite sugeneruoti pazymius automatiskai (t/n)"; cin >> atsakymas1;
        if (atsakymas1 == "t") {
            tomas.automatiskai();
        }
        if (atsakymas1 == "n") {
            tomas.ranka();
        }
    }
    cout << " ar norite galutini pazymi skaiciuoti su vidurkiu ar mediana (v/m)"; cin >> atsakymas2;
    if (atsakymas2 == "v") {
        printf("%15s %15s", "Vardas", "Pavarde"), printf("%30s", "Galutinis Pazymis"); cout << endl;
        cout << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < skaicius; i++) {

            printf("%15s %15s", tomas.vardai[i].c_str(), tomas.pavardes[i].c_str()), printf("%23.2f", tomas.vidurkis[i] * 0.6 + tomas.egzaminas[i] * 0.4); cout << endl;
        }
    }
    if (atsakymas2 == "m") {
        printf("%15s %15s", "Vardas", "Pavarde"), printf("%30s", "Galutinis Pazymis"); cout << endl;
        cout << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < skaicius; i++) {
            printf("%15s %15s", tomas.vardai[i].c_str(), tomas.pavardes[i].c_str()), printf("%23.2f", tomas.mediana[i] * 0.6 + tomas.egzaminas[i] * 0.4); cout << endl;
        }
    }

}

