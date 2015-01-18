#include "Sovellus.h"
#include "Koulu.h"
#include <iostream>

using std::cout; using std::endl; using std::cin;
Sovellus::Sovellus(void)
{}

Sovellus::Sovellus(string nimi, string polku) : nimi_(nimi), polku_(polku)
{}

Sovellus::~Sovellus(void)
{}

void Sovellus::aja() const
{
	Koulu amk(nimi_, polku_);
	string valinta = "";
	cout << "Tervetuloa " << amk.annaNimi() << "iin!" << endl;
	int lopullinenvalinta = 1;
	while ( lopullinenvalinta != 0)
	{
		try
		{
			tulostaValikko();
			//tulostaa valikon	
			getline(cin, valinta);
			//syötetään valinta

			//alla olevat ifit "muuttavat" syötetyn valinnan stringistä intiksi
			if (valinta == "1")
			{
				throw 1;
			}
			else if (valinta == "2")
			{
				throw 2;
			}
			else if (valinta == "3")
			{
				throw 3;
			}
			else if (valinta == "4")
			{
				throw 4;
			}
			else if (valinta == "5")
			{
				throw 5;
			}
			else if (valinta == "6")
			{
				throw 6;
			}
			else if (valinta == "7")
			{
				throw 7;
			}
			else if (valinta == "8")
			{
				throw 8;
			}
			else if (valinta == "9")
			{
				throw 9;
			}
			else if (valinta == "10")
			{
				throw 10;
			}
			else if (valinta == "11")
			{
				throw 11;
			}
			else if (valinta == "12")
			{
				throw 12;
			}
			else if (valinta == "13")
			{
				throw 13;
			}
			else if (valinta == "14")
			{
				throw 14;
			}
			else if (valinta == "15")
			{
				throw 15;
			}
			else if (valinta == "0")
			{
				throw 0;
			}
			//valinta jotain muuta kuin luku 0-15, "heitetään" kirjainjono "virhe"
			else
				throw "virhe";
		}


		catch (int valinta)
		{
			//valinta oli luku väliltä 0-15, suoritetaan sitä vastaava toimenpide
			if (valinta == 1)
			{
				amk.lisaaKoulutusohjelma();
			}
			else if (valinta == 2)
			{
				amk.tulostaKoulutusohjelma();
			}
			else if (valinta == 3)
			{
				amk.tulostaKoulutusohjelmienMaara();
			}
			else if (valinta == 4)
			{
				amk.lisaaKoulutusohjelmaanOpettaja();
			}
			else if (valinta == 5)
			{
				amk.tulostaKoulutusohjelmanOpettaja();
			}
			else if (valinta == 6)
			{
				amk.lisaaKoulutusohjelmaanOpiskelija();
			}
			else if (valinta == 7)
			{
				amk.tulostaKoulutusohjelmanOpiskelija();
			}
			else if (valinta == 8)
			{
				amk.poistaKoulutusohjelma();
			}
			else if (valinta == 9)
			{
				amk.poistaKoulutusohjelmanOpettaja();
			}
			else if (valinta == 10)
			{
				amk.poistaKoulutusohjelmanOpiskelija();
			}
			else if (valinta == 11)
			{
				amk.paivitaKoulutusohjelmanNimi();
			}
			else if (valinta == 12)
			{
				amk.paivitaKoulutusohjelmanOpettajanTiedot();
			}
			else if (valinta == 13)
			{
				amk.paivitaKoulutusohjelmanOpiskelijanTiedot();
			}
			else if (valinta == 14)
			{
				amk.lueTiedot();
			}
			else if (valinta == 15)
			{
				amk.tallennaTiedot();
			}
			else if (valinta == 0)
			{
				cout << " Nakemiin!" << endl;
				lopullinenvalinta = 0;
				//lopullinenvalinta asetetaan nollaksi, jolloin while-silmukka loppuu ja ohjelma sammutetaan
			}
		}

		catch (const char* valinta)
		{
			//syötetty jotain muuta kuin luku 0-15, virheilmoitus
			cout << "virheellinen syote";
		}
	}

}

void Sovellus::tulostaValikko() const
{
	cout << " 1) Lisaa koulutusohjelma\n";
	cout << " 2) Tulosta koulutusohjelmien nimet\n";
	cout << " 3) Tulosta koulutusohjelmien maara\n";
	cout << " 4) Lisaa koulutusohjelmaan opettaja\n";
	cout << " 5) Tulosta koulutusohjelman opettajat\n";
	cout << " 6) Lisaa koulutusohjelmaan opiskelija\n";
	cout << " 7) Tulosta koulutusohjelman opiskelijat\n";
	cout << " 8) Poista koulutusohjelma\n";
	cout << " 9) Poista opettaja\n";
	cout << "10) Poista opiskelija\n";
	cout << "11) Paivita koulutusohjelman nimi\n";
	cout << "12) Paivita opettajan tiedot\n";
	cout << "13) Paivita opiskelijan tiedot\n";
	cout << "14) Lue tiedot\n";
	cout << "15) Tallenna tiedot\n";
	cout << " 0) Lopeta\n";
	cout << "Anna valintasi: ";
}
