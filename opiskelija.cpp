#include "Opiskelija.h"
#include <iostream>

using std::cout; using std::endl; using std::cin; using std::getline;

Opiskelija::Opiskelija() : henkilo(), opiskelijanumero_("")
{}

Opiskelija::Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero) :
henkilo(etunimi, sukunimi, osoite, puhelinnumero), opiskelijanumero_(opiskelijanumero)
{}

Opiskelija::~Opiskelija()
{}

Opiskelija::Opiskelija(const Opiskelija& alkup) : henkilo(alkup), opiskelijanumero_(alkup.opiskelijanumero_)
{}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

void Opiskelija::asetaOpiskelijanumero(string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

void Opiskelija::tulosta() const
{
	henkilo::tulosta();
	cout << " " << opiskelijanumero_ << endl;
}

void Opiskelija::kysyTiedot()
{
	//kysyy henkilö-luokan kysytiedoilla muut tiedot, opiskelijanumero tässä funktiossa
	henkilo::kysyTiedot();
	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero_);
}

