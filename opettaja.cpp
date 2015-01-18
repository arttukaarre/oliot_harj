#include "Opettaja.h"
#include <iostream>

using std::cout; using std::endl; using std::getline; using std::cin;


Opettaja::Opettaja() : Tyontekija(), opetusala_("")
{}

Opettaja::Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, string tunnus, double palkka, string opetusala) :
Tyontekija(etunimi, sukunimi, osoite, puhelinnumero, tunnus, palkka), opetusala_(opetusala)
{}

Opettaja::~Opettaja()
{}

Opettaja::Opettaja(const Opettaja& alkup) : Tyontekija(alkup), opetusala_(alkup.opetusala_)
{}

string Opettaja::annaOpetusala() const
{
	return opetusala_;
}

void Opettaja::asetaOpetusala(string opetusala)
{
	opetusala_ = opetusala;
}

void Opettaja::tulosta() const
{
	Tyontekija::tulosta();
	cout << " " << opetusala_ << endl;
}

void Opettaja::kysyTiedot()
{
	//kysyy työntekijän kysytiedoilla muut tiedot, tässä funktiossa vain opetusala
	Tyontekija::kysyTiedot();
	cout << "Anna opetusala: ";
	getline(cin, opetusala_);
}

