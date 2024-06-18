#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <memory>
#include <algorithm>
#include "moottorivene.h"
using namespace std;
//Kättäjälle annettava dialogi konsolissa
void dialogi() {
	cout << endl;
	cout << endl;
	cout << "Valitse operaatio" << endl;
	cout << "(L) lisää veneen" << endl;
	cout << "(T) tulostaa tallennetut veneet" << endl;
	cout << "(P) poistaa veneen" << endl;
	cout << "(J) järjestää veneet" << endl;
	cout << "(X) poistu ohjelmasta" << endl;
	cout << "Syötä haluttu operaatio" << endl;

}
int main() {

	setlocale(LC_ALL, "fi_FI");
	//Muuttujia
	char operaatio;
	string venenimi;
	string venemerkki;
	int venemäärä{ 0 };
	auto poistonumero{ 0 };
	int veneteho{ 0 };
	int järjestelyperuste{ 0 };
	float venepituus{ 0 };
	//Veneiden tallennuspaikka
	vector<Moottorivene> veneet;
	//Järjestelyperusteet (lambdat) merkin, pituuden ja moottorin tehon mukaan
	auto MerkkiJärjestely = [](Moottorivene a, Moottorivene b) {

		return a.getMerkki() < b.getMerkki();

	};
	auto PituusJärjestely = [](Moottorivene a, Moottorivene b) {

		return a.getPituus() > b.getPituus();

	};
	auto TehoJärjestely = [](Moottorivene a, Moottorivene b) {

		return a.getTeho() > b.getTeho();

	};
	cout << "Moottoriveneiden ylläpito-ohjelma" << endl;
	dialogi();
	//do-while loop, jossa käyttäjä valitsee operaation
	do {

		cin >> operaatio;
		//Lisäys-operaatio
		if (operaatio == 'l') {

			unique_ptr<Moottorivene> vene(new Moottorivene);
			cout << "Anna veneen merkki: " << endl;
			cin >> venemerkki;
			if (venemerkki.length() == 0) {

				cout << "Kirjoita merkki: " << endl;

			}
			(*vene).setMerkki(venemerkki);
			cout << "Anna veneen teho(Hv): " << endl;
			cin >> veneteho;
			if (veneteho < 1) {

				cout << "Anna ei-negatiivinen arvo" << endl;

				cin >> veneteho;

			}
			(*vene).setTeho(veneteho);
			cout << "Anna veneen pituus(m): " << endl;
			cin >> venepituus;
			if (venepituus < 0) {

				cout << "Anna ei-negatiivinen arvo" << endl;

				cin >> venepituus;

			}
			(*vene).setPituus(venepituus);
			veneet.push_back(*vene);
			venemäärä++;

		}
		//Tulostus-operaatio
		if (operaatio == 't') {
			cout << endl;

			if (venemäärä == 0) {

				cout << "Ei tallennetuja veneitä" << endl;

			}

			else {

				for (int i = 0; i < veneet.size(); i++) {
					cout << "Veneen numero: " << i + 1 << endl;

					veneet.at(i).tulostaVene();
					cout << endl;

				}

			}

		}
		//Poisto-operaatio
		if (operaatio == 'p') {
			cout << endl;
			cout << "Anna poistettavan veneen järjestysnumero vektorissa " << endl;

				cout << "Vaihtoehtoisesti näppäile 0 poiston keskeyttämiseksi" << endl;

				cin >> poistonumero;
			if (poistonumero > venemäärä) {

				cout << "Järjestysnumeroa ei ole olemassa" << endl;

				cin >> poistonumero;

			}
			if (poistonumero < 0) {

				cout << "Järjestysnumeroa ei ole olemassa"

					<< endl;

				cin >> poistonumero;

			}
			if (poistonumero == 0) {

				cout << "Poisto keskeytetty" << endl;

			}
			else {

				veneet.erase(veneet.begin() + poistonumero - 1);

				cout << "Vene numero " << poistonumero << " poistettu" << endl;

				venemäärä--;

			}

		}
		//Järjestely-operaatio
		if (operaatio == 'j') {
			if (venemäärä < 1) {
				cout << endl;
				cout << "Ei veneitä järjestettäväksi" << endl;

			}

			else {

				cout << "Millä perusteella veneet järjestetään ? " << endl;

				cout << "0: Peruuta järjestely" << endl;
				cout << "1: Merkin aakkosjärjestys" << endl;

				cout << "2: Pituus" << endl;
				cout << "3: Moottorin teho" << endl;
				cin >> järjestelyperuste;
				if (järjestelyperuste == 1) {
					sort(veneet.begin(),

						veneet.end(), MerkkiJärjestely);

					cout << "Järjestelty veneen merkin mukaan" << endl;

				}
				else if (järjestelyperuste == 2) {
					cout << "Järjestelty veneen pituuden mukaan" << endl;

						sort(veneet.begin(), veneet.end(), PituusJärjestely);

				}
				else if (järjestelyperuste == 3) {
					cout << "Järjestelty moottorin tehon mukaan" << endl;

						sort(veneet.begin(), veneet.end(), TehoJärjestely);

				}
				else if (järjestelyperuste == 0) {
					cout << "Järjestely peruttu" << endl;

				}

			}

		}

		dialogi();

	}
	//Ohjelmasta poistuminen
	while (operaatio != 'x');
	return 0;

}