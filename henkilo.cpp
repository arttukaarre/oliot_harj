#include "henkilo.h"
#include <iostream>
using std::cout; using std::endl; using std::cin; using std::getline;

henkilo::henkilo() : Etunimi_(""), Sukunimi_(""), Osoite_(""), Puhelinnumero_("")
{
}

henkilo::henkilo(string e, string s, string o, string p) : 
Etunimi_(e), Sukunimi_(s), Osoite_(o), Puhelinnumero_(p)
{
}

//kopiorakentaja
henkilo::henkilo(const henkilo& alkup) : 
Etunimi_(alkup.Etunimi_), Sukunimi_(alkup.Sukunimi_), 
Osoite_(alkup.Osoite_), Puhelinnumero_(alkup.Puhelinnumero_)
{

}

henkilo::~henkilo()
{
}

void henkilo::asetaEtunimi(string etunimi)
{
	Etunimi_ = etunimi;
}

void henkilo::asetaSukunimi(string sukunimi)
{
	Sukunimi_ = sukunimi;
}

void henkilo::asetaOsoite(string osoite)
{
	Osoite_ = osoite;
}

void henkilo::asetaPuhelinnumero(string numero)
{
	Puhelinnumero_ = numero;
}

string henkilo::annaEtunimi() const
{
	return Etunimi_;
}

string henkilo::annaSukunimi() const
{
	return Sukunimi_;
}

string henkilo::annaOsoite() const
{
	return Osoite_;
}

string henkilo::annaPuhelinnumero() const
{
	return Puhelinnumero_;
}

void henkilo::kysyTiedot()
{
	cout << "Anna etunimi: ";
	getline(cin, Etunimi_);
	cout << "Anna sukunimi: ";
	getline(cin, Sukunimi_);
	cout << "Anna osoite: ";
	getline(cin, Osoite_);
	cout << "Anna puhelinnumero: ";
	getline(cin, Puhelinnumero_);
}

void henkilo::tulosta() const
{
	cout << Etunimi_ << " " << Sukunimi_ << " " << Osoite_ << " " << Puhelinnumero_ << endl;
}
