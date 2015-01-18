#pragma once
#include "Koulu.h"

class Sovellus
{
public:
	Sovellus();
	Sovellus(string, string);
	virtual ~Sovellus();
	void aja() const;
	void tulostaValikko() const;

private:
	string nimi_;
	string polku_;
};

