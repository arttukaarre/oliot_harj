#pragma once
#include "koulutusohjelma.h"
class Koulu

{
public:
	Koulu();
	Koulu(string, string);
	virtual ~Koulu();

	void asetaNimi(string);
	string annaNimi() const;

	void lisaaKoulutusohjelma();
	void tulostaKoulutusohjelma() const;

	void tulostaKoulutusohjelmienMaara() const;
	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettaja() const;
	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOpiskelija() const;

	void poistaKoulutusohjelma();
	void poistaKoulutusohjelmanOpettaja();
	void paivitaKoulutusohjelmanNimi();
	void poistaKoulutusohjelmanOpiskelija();
	void paivitaKoulutusohjelmanOpettajanTiedot();
	void paivitaKoulutusohjelmanOpiskelijanTiedot();
	bool lueTiedot();
	bool tallennaTiedot();

private:
	int Koulu::etsiKoulutusohjelma() const;
	string nimi_;
	string polku_;
	vector <Koulutusohjelma> koulutusohjelmat_;
};

