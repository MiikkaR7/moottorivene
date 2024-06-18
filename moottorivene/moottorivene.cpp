#include <iostream>
#include <stdlib.h>
#include <string>
#include "moottorivene.h"
using namespace std;

Moottorivene::Moottorivene()

	: aMerkki{ "Merkki" }, aPituus{ 5 }, aTeho{ 200 }

{
}
Moottorivene::Moottorivene(const string sMerkki, const float sPituus, const int

	sTeho)

	: aMerkki(sMerkki), aPituus(sPituus), aTeho(sTeho)

{
}
Moottorivene::~Moottorivene() {
}
void Moottorivene::setTeho(int sTeho) {

	aTeho = sTeho;

}
void Moottorivene::setPituus(float sPituus) {

	aPituus = sPituus;

}
void Moottorivene::setMerkki(string sMerkki) {

	aMerkki = sMerkki;

}
int Moottorivene::getTeho() const {

	return aTeho;

}
float Moottorivene::getPituus() const {

	return aPituus;

}
string Moottorivene::getMerkki() const {

	return aMerkki;

}
void Moottorivene::tulostaVene() const {

	cout << "Veneen merkki: " << getMerkki() << endl;
	cout << "Veneen pituus: " << getPituus() << " metriä" << endl;
	cout << "Veneen teho: " << getTeho() << " Hv" << endl;

}