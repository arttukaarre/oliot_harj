#include "Tyontekija.h"
#include <iostream>
using std::cout; using std::endl; using std::cin; using std::getline;

Tyontekija::Tyontekija() : henkilo(), Tunnus_(""), Palkka_(0.0)
{
}

Tyontekija::Tyontekija(string e, string s, string o, string p, string tunnus, double palkka) :
henkilo(e, s, o, p), Tunnus_(tunnus), Palkka_(palkka)
{
}

Tyontekija::Tyontekija(const Tyontekija& alkup) :
henkilo(alkup), Tunnus_(alkup.Tunnus_), Palkka_(alkup.Palkka_)
{
}

Tyontekija::~Tyontekija()
{
}

void Tyontekija::asetaTunnus(string tunnus)
{
	Tunnus_ = tunnus;
}

void Tyontekija::asetaPalkka(double palkka)
{
	Palkka_ = palkka;
}

string Tyontekija::annaTunnus() const
{
	return Tunnus_;
}

double Tyontekija::annaPalkka() const
{
	return Palkka_;
}

void Tyontekija::kysyTiedot()
{
	string apu;
	//kysyy henkilössä yleiset tiedot, tässä funktiossa kysytään vain opettajaan liittyvät tiedot tunnus ja palkka
	henkilo::kysyTiedot();
	cout << "Anna tunnus: ";
	getline(cin, Tunnus_);
	cout << "Anna palkka: ";
	getline(cin, apu);
	//muuttaa palkka-string doubleksi
	Palkka_ = atof(apu.c_str());
}

void Tyontekija::tulosta() const
{
	henkilo::tulosta();
	cout << Tunnus_ << " " << Palkka_ << " ";
	
}
