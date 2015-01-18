#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Opettaja.h"
#include "Opiskelija.h"
#include <fstream>
using std::string;  using std::vector; using std::cin; using std::endl; using std::cout; using std::ifstream; using std::ofstream; using std::ios;
class Koulutusohjelma
{

public:
	Koulutusohjelma();
	Koulutusohjelma(string, string);
	~Koulutusohjelma();
	void lisaaOpettaja();
	void lisaaOpiskelija();
	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;
	void asetaNimi(string);
	string annaNimi() const;
	void poistaKoulutusohjelmanOpettaja();
	void paivitaKoulutusohjelmanOpettaja();
	void poistaKoulutusohjelmanOpiskelija();
	void paivitaKoulutusohjelmanOpiskelija();
	bool lueOpettajat();
	bool lueOpiskelijat();
	bool tallennaOpettajat(int);
	bool tallennaOpiskelijat(int);

private:
	string nimi_;
	string polku_;
	vector <Opiskelija> opiskelijat_;
	vector <Opettaja> opettajat_;
};
