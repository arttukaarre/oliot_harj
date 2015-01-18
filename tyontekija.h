#pragma once
#include "henkilo.h"

class Tyontekija :
	public henkilo
{
public:
	//setters
	Tyontekija();
	Tyontekija(string, string, string, string, string, double);
	Tyontekija(const Tyontekija&);
	void asetaTunnus(string);
	void asetaPalkka(double);
	~Tyontekija();

	//getters
	string annaTunnus() const;
	double annaPalkka() const;

	void tulosta() const;
	void kysyTiedot();

private:
	string Tunnus_;
	double Palkka_;
};
