#pragma once
#include <string>
using std::string;

class henkilo
{
public:
	//setters
	henkilo();
	henkilo(string, string, string, string);
	henkilo(const henkilo&);
	void asetaEtunimi (string);
	void asetaSukunimi(string);
	void asetaOsoite(string);
	void asetaPuhelinnumero(string);
	~henkilo();

	//getters
	string annaEtunimi() const;
	string annaSukunimi() const;
	string annaOsoite() const;
	string annaPuhelinnumero() const;

	void tulosta() const;
	void kysyTiedot();

private:
	string Etunimi_;
	string Sukunimi_;
	string Osoite_;
	string Puhelinnumero_;

};
