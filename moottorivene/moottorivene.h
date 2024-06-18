#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Moottorivene {
public:

	Moottorivene();
	Moottorivene(const string aMerkki, const float aPituus, const int aTeho);
	~Moottorivene();
	void setTeho(int sTeho);
	void setPituus(float sPituus);
	void setMerkki(string sMerkki);
	int getTeho() const;
	float getPituus() const;
	string getMerkki() const;
	void tulostaVene() const;

private:

	int aTeho;
	float aPituus;
	string aMerkki;

};
