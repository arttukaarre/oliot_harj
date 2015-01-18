#pragma once
#include "Tyontekija.h"

class Opettaja : 
	public Tyontekija
{
public:

	Opettaja();
	Opettaja(string etunimi, string sukunimi, string osoite,
		string puhelinnumero, string tunnus, double palkka, string opetusala);
	~Opettaja();
	Opettaja(const Opettaja&ope);

	string annaOpetusala() const;
	void asetaOpetusala(string);
	void tulosta() const;
	void kysyTiedot();
private:
	string opetusala_;
};
