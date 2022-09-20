
#include <algorithm>
#include <iostream>
#include <iostream>
#include <string>
#include<vector>
#include<iomanip>;
using namespace std;
class Lentele {
public:
	int egz;
	vector <int> paz;
	int studentai, sum;
	double kiekis;
	string var, pav;
	float vidurkis, mediana;
	int k;
	double temp, temp1;
	double u = 0;

	void veiksmas() {
		cout << "iveskite varda  "; cin >> var;
		cout << "iveskite pavarde  "; cin >> pav;
		cout << "iveskite egzamino pazymi  "; cin >> egz;
		cout << "iveskite pazymiu kieki  "; cin >> kiekis;
		u = 0;
		for (int i = 0; i < kiekis; i++) {
			cout << "iveskite  " << i + 1 << "  pazymi  "; cin >> k;
			paz.push_back(k);
			u += k;
		}
		cout << "pazymiai yra" << endl;
		for (int i = 0; i < paz.size(); i++) {
			cout << paz[i] << " ";
		}
		sort(paz.begin(), paz.end());
		for (const auto& i : paz);
		if (paz.size() == 1) {
			temp = paz[0];
			mediana = temp;
		}
		if (paz.size() == 2) {
			temp = paz[0] + paz[1];
			mediana = temp / 2;
		}
		if (paz.size() % 2 != 0) {
			temp = paz[paz.size() / 2];
			mediana = temp;
		}
		if (paz.size() % 2 == 0) {
			temp1 = paz.size();
			temp = paz[temp1 / 2] + paz[temp1 / 2 - 1];
			mediana = temp / 2;
		}
		cout << endl;
		paz.resize(0);
	}
};
int main() {
	vector <double >skaiciai, median, egzaminas, vidurkis;
	vector<int> pazymiai;
	vector <string> vard, pavd;
	int m;
	cout << "iveskite studentu skaiciu  "; cin >> m;
	Lentele tomas;
	for (int i = 0; i < m; i++) {
		tomas.veiksmas();
		vard.push_back(tomas.var);
		pavd.push_back(tomas.pav);
		median.push_back(tomas.mediana);
		vidurkis.push_back(tomas.u / tomas.kiekis);
		egzaminas.push_back(tomas.egz);
		pazymiai.insert(pazymiai.end(), tomas.paz.begin(), tomas.paz.end());
	}
	cout << "| Vardas     |" << "|Pavarde   | " << "Vidurkis  " << "Egzamino pazymis " << " | Galutinis pazymis   " << "    " << "Mediana " << endl;
	for (int i = 0; i < m; i++) {
		cout << vard[i] << "         " << pavd[i] << "          " << fixed << setprecision(2) << vidurkis[i] << "        " << egzaminas[i] << "                   " << egzaminas[i] * 0.4 + vidurkis[i] * 0.6 << "            " << median[i] << endl;
	}







}
