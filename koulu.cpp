#include "Koulu.h"
#include <iostream>
#include <string>
#include <fstream>
using std::cout; using std::cin; using std::getline; using std::endl;
using std::ifstream; using std::ofstream; using std::ios;

//oletusrakentaja
Koulu::Koulu() : nimi_(""), koulutusohjelmat_()
{}

//parametrillinen rakentaja
Koulu::Koulu(string nimi, string polku)
{
    this->nimi_ = nimi;
    this->polku_ = polku;
}

//purkaja
Koulu::~Koulu()
{}

void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::lisaaKoulutusohjelma()
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin,nimi);
	//luetaan nimi ja lisätään se koulutusohjelmat_ -vektorin viimeiseksi alkioksi
	koulutusohjelmat_.push_back(Koulutusohjelma(nimi, "U:\\olio-ohjelmointi\\harkkatyo\\oik harkka\\"));
}

void Koulu::tulostaKoulutusohjelma() const
{
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		//hakee ohjelmien nimet ja tulostaa ne
		cout << koulutusohjelmat_.at(i).annaNimi() << endl;
	}
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	//tarkistaa vektorin koon eli ohjelmien määrän ja tulostaa sen
		cout << "Koulutusohjelmien lukumaara: " << koulutusohjelmat_.size() << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	//indeksi on koulutusohjelman järjestysnumero vektorissa, johon opettaja lisätään
	if (indeksi >= 0)
		koulutusohjelmat_.at(indeksi).lisaaOpettaja();
	else
		cout << "Koulutusohjelmaa ei loydy!" << endl;
}

void Koulu::tulostaKoulutusohjelmanOpettaja() const
{
	int indeksi = etsiKoulutusohjelma();


	if (indeksi >= 0)
		koulutusohjelmat_.at(indeksi).tulostaOpettajat();
	else
		cout << "Koulutusohjelmaa ei loydy!" << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
		koulutusohjelmat_.at(indeksi).lisaaOpiskelija();

	else
		cout << "koulutusohjelmaa ei loydy!" << endl;
}

void Koulu::tulostaKoulutusohjelmanOpiskelija() const
{
	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0)
		koulutusohjelmat_.at(indeksi).tulostaOpiskelijat();
	else
		cout << "Koulutusohjelmaa ei loydy!" << endl;
}



void Koulu::paivitaKoulutusohjelmanNimi()
{
	string nimi; string uusinimi;
	cout << "Koulutusohjelman nimi? " << endl;
	getline(cin, nimi);

	int apu = 0;

	//haetaan ohjelma
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (koulutusohjelmat_.at(i).annaNimi() == nimi)
		{
			//ohjelma loydetty, annetaan uusi nimi
			cout << "Koulutusohjelman uusi nimi?";
			getline(cin, uusinimi);
			int found = 1;
			for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
			{
				if (koulutusohjelmat_.at(i).annaNimi() == uusinimi)
				{	
					//jos ohjelma loytyy jo, ei nimeä vaihdeta ja annetaan virheilmoitus
					cout << "Loytyy jo!" << endl;
					found = 1;
				}
				else
					//muuten int found = 0, ohjelmaa ei loydy ja siirrytään vaihtamaan nimi
					found = 0;
				apu = 1;
			}

			if (found == 0){

				//haetaan vaihdettavan ohjelman järjestysluku ja vaihdetaan alkion (ohjelman) nimi
				for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++){
					
					if (koulutusohjelmat_.at(i).annaNimi() == nimi)
					{
						koulutusohjelmat_.at(i).asetaNimi(uusinimi);
						apu = 1;
					}
				}
			}
		
		}
	}
	if (apu == 0)
		cout << "Koulutusohjelmaa ei loydy!" << endl;
}

void Koulu::poistaKoulutusohjelma()
{
	
	string nimi;
	cout << "Koulutusohjelman nimi?" << endl;
	getline(cin, nimi);

	int apu = 0;

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (koulutusohjelmat_.at(i).annaNimi() == nimi)
		{
			//jos haettu ohjelma löytyy, poistetaan se
			koulutusohjelmat_.erase(koulutusohjelmat_.begin() + i);
			apu = 1;
			cout << "Koulutusohjelma poistettu " << endl;
		}
	}
	if (apu == 0)
		cout << "Koulutusohjelmaa ei loydy!" << endl;
}

void Koulu::poistaKoulutusohjelmanOpiskelija()
{
	string nimi;
	cout << "Koulutusohjelman nimi? " << endl;
	getline(cin, nimi);

	int apu = 0;

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (koulutusohjelmat_.at(i).annaNimi() == nimi)
		{
			//jos koulutusohjelma löytyy, ajetaan opiskelijanpoistofunktio
			koulutusohjelmat_.at(i).poistaKoulutusohjelmanOpiskelija();
			apu = 1;
		}
	}
	if (apu == 0)
		cout << "Koulutusohjelmaa ei loydy!" << endl;
}


void Koulu::poistaKoulutusohjelmanOpettaja()
{
	string nimi;
	cout << "Koulutusohjelman nimi? " << endl;
	getline(cin, nimi);

	int apu = 0;

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (koulutusohjelmat_.at(i).annaNimi() == nimi)
		{
			//jos koulutusohjelma löytyy, ajetaan opettajanpoistofunktio
			koulutusohjelmat_.at(i).poistaKoulutusohjelmanOpettaja();
			apu = 1;
		}
	}
	if (apu == 0)
		cout << "Koulutusohjelmaa ei loydy!" << endl;
}

void Koulu::paivitaKoulutusohjelmanOpettajanTiedot()
{
	string nimi;
	cout << "Koulutusohjelman nimi? " << endl;
	getline(cin, nimi);

	int apu = 0;

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (koulutusohjelmat_.at(i).annaNimi() == nimi)
		{
			//jos koulutusohjelma löytyy, ajetaan opettajan päivitys -funktio
			koulutusohjelmat_.at(i).paivitaKoulutusohjelmanOpettaja();
			apu = 1;
		}
	}
	if (apu == 0)
		cout << "Koulutusohjelmaa ei loydy!" << endl;
}

void Koulu::paivitaKoulutusohjelmanOpiskelijanTiedot()
{
	string nimi;
	cout << "Koulutusohjelman nimi? " << endl;
	getline(cin, nimi);

	int apu = 0;

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (koulutusohjelmat_.at(i).annaNimi() == nimi)
		{
			//jos koulutusohjelma löytyy, ajetaan opiskelijan päivitys -funktio
			koulutusohjelmat_.at(i).paivitaKoulutusohjelmanOpiskelija();
			apu = 1;
		}
	}
	if (apu == 0)
		cout << "Opiskelijaa ei loydy!" << endl;
}

bool Koulu::lueTiedot(){
	
	ifstream tied;
	string nimi;
	tied.open(polku_ + "Koulutusohjelma.csv");
	//avataan mainissa määritellyn polun päässä oleva tiedosto Koulutusohjelma.csv
	if (tied.is_open()){
	
		while (tied.peek() != EOF)
		{
			//haetaan rivinvaihtoon loppuvan rivin tiedot ja lisätään ne koulutusohjelmat_ -vektoriin
			getline(tied, nimi, '\n');
			if (nimi.length() > 0)
				koulutusohjelmat_.push_back(Koulutusohjelma(nimi, polku_));
		}
	tied.close();
	//sulkee tiedoston
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		//ajaa opiskelijat ja opettajat tiedostoista lukevat funktiot
		koulutusohjelmat_.at(i).lueOpettajat();
		koulutusohjelmat_.at(i).lueOpiskelijat();
	}
	return true;

}
	else
	return false;
}

bool Koulu::tallennaTiedot(){
	ofstream tied;
	tied.open(polku_ + "Koulutusohjelma.csv");
	//avataan mainissa määritellyn polun päässä oleva tiedosto Koulutusohjelma.csv

	if (tied.is_open())
	{
		for (unsigned int i = 0; i<koulutusohjelmat_.size(); i++)
		{
			tied << koulutusohjelmat_.at(i).annaNimi() << endl;
			//kirjoittaa tiedostoon tämänhetkiset koulutusohjelmat
		}
		tied.close();

		bool ope_ok = false, opisk_ok = false;
		for (unsigned int i = 0; i<koulutusohjelmat_.size(); i++)
		{
			//ajaa opettajat ja opiskelijat tiedostoon tallentavat funktiot
			ope_ok = koulutusohjelmat_.at(i).tallennaOpettajat(i);
			opisk_ok = koulutusohjelmat_.at(i).tallennaOpiskelijat(i);
		}
		if (ope_ok && opisk_ok)
			return true;
		else
			return false;
	}
	else
	{
		cout << "Tiedostoa ei voi avata!" << endl;
		return false;
	}
}


int Koulu::etsiKoulutusohjelma()const
{
	string nimi;
	cout << "Koulutusohjelman nimi? ";
	getline(cin, nimi);

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_.at(i).annaNimi())
			return i;
	}
	return -1;
}

