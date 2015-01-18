#pragma once
#include "henkilo.h"
class Opiskelija : 
	public henkilo
{
public:
	Opiskelija();
	Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero);
	~Opiskelija();
	Opiskelija(const Opiskelija&);

	string annaOpiskelijanumero() const;
	void asetaOpiskelijanumero(string opiskelijanumero);
	void tulosta() const;
	void kysyTiedot();
private:
	string opiskelijanumero_;
};

