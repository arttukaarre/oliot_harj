#include "Koulutusohjelma.h"


Koulutusohjelma::Koulutusohjelma() :nimi_(""), opiskelijat_(), opettajat_()
{}

Koulutusohjelma::Koulutusohjelma(string nimi, string polku) : nimi_(nimi),polku_(polku), opiskelijat_(),
opettajat_()
{}

Koulutusohjelma::~Koulutusohjelma()
{}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja apu;
	apu.kysyTiedot();
	//kysytään open tiedot ja lisätään opettajat_ -vektoriin
	opettajat_.push_back(apu);
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija apu;
	apu.kysyTiedot();
	//kysytään opiskelijan tiedot ja lisätään opiskelijat_ -vektoriin
	opiskelijat_.push_back(apu);
}

bool Koulutusohjelma::tallennaOpettajat(int indeksi)
{
	ofstream tied;
	if (indeksi > 0)
		tied.open(polku_ + "Opettaja.csv", ios::app);
	//jos tiedosto löytyy, lisätään uudet tiedot tiedoston loppuun, ei yliajeta vanhaa dataa
	else
		tied.open(polku_ + "Opettaja.csv");
	//avataan tiedosto
	if (tied.is_open())
	{
		for (unsigned int i = 0; i < opettajat_.size(); i++){
			//tallennetaan yhdelle riville opettajan tiedot, kaikki puolipisteellä erotellen
			tied << nimi_ << ";" << opettajat_.at(i).annaEtunimi() << ";" << opettajat_.at(i).annaSukunimi()
				<< ";" << opettajat_.at(i).annaOsoite() << ";"
				<< opettajat_.at(i).annaPuhelinnumero() << ";"
				<< opettajat_.at(i).annaTunnus() << ";"
				<< opettajat_.at(i).annaPalkka() << ";"
				<< opettajat_.at(i).annaOpetusala() << endl;
		}
		tied.close();
		return true;
	}
	else{
		cout << "Opettaja.csv-tiedostoa ei voi avata!" << endl;
		return false;
	}
}

bool Koulutusohjelma::tallennaOpiskelijat(int indeksi)
{
	ofstream tied;
	if (indeksi > 0)
		tied.open(polku_ + "Opiskelija.csv", ios::app);
	//jos tiedosto löytyy, lisätään uudet tiedot tiedoston loppuun, ei yliajeta vanhaa dataa
	else
		tied.open(polku_ + "Opiskelija.csv");
	if (tied.is_open())
	{
		for (unsigned int i = 0; i < opiskelijat_.size(); i++){
			//tallennetaan yhdelle riville opiskelijan tiedot, kaikki puolipisteellä erotellen
			tied << nimi_ << ";"
				<< opiskelijat_.at(i).annaEtunimi() << ";"
				<< opiskelijat_.at(i).annaSukunimi() << ";"
				<< opiskelijat_.at(i).annaOsoite() << ";"
				<< opiskelijat_.at(i).annaPuhelinnumero() << ";"
				<< opiskelijat_.at(i).annaOpiskelijanumero() << endl;
				
		}
		tied.close();
		return true;
	}
	else {
		cout << "Opiskelija.csv-tiedostoa ei voi avata!" << endl;
		return false;
	}
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		opiskelijat_.at(i).tulosta();
	}
}

void Koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		opettajat_.at(i).tulosta();
	}
}
void Koulutusohjelma::poistaKoulutusohjelmanOpettaja()
{
	string nimi;
	cout << "Opettajan tunnus? ";
	getline(cin, nimi);

	int apu = 0;
	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		if (opettajat_.at(i).annaTunnus() == nimi)
		{
			//jos opettaja löytyy tunnuksen perusteella, se poistetaan
			opettajat_.erase(opettajat_.begin() + i);
			cout << "Opettja tunnuksella" << nimi << "on poistettu" << endl;
			apu = 1;
		}
	}
	if (apu == 0)
		cout << "Opettajaa ei loydy" << endl;

}

void Koulutusohjelma::paivitaKoulutusohjelmanOpettaja()
{
	string nimi;
	cout << "Opettajan tunnus? ";
	getline(cin, nimi);

	int apu = 0;
	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		if (opettajat_.at(i).annaTunnus() == nimi)
		{
			//jos opettaja löytyy, ajetaan sama funktio jolla uusi opettaja lisättäisiin
			//jolloin uusi data yksinkertaisesti yliajaa vanhan
			opettajat_.at(i).kysyTiedot();
			cout << "Opettja tunnuksella" << nimi << "on paivitettu" << endl;
			apu = 1;
		}
	}
	if (apu == 0)
		cout << "Opettajaa ei loydy" << endl;

}

void Koulutusohjelma::poistaKoulutusohjelmanOpiskelija()
{
	string nimi;
	cout << "Opiskelijan numero? ";
	getline(cin, nimi);

	int apu = 0;
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		if (opiskelijat_.at(i).annaOpiskelijanumero() == nimi)
		{
			//jos opiskelija löytyy opiskelijanumeron perusteella, se poistetaan

			opiskelijat_.erase(opiskelijat_.begin() + i);
			cout << "Opiskelija tunnuksella" << nimi << "on poistettu" << endl;
			apu = 1;
		}
	}
	if (apu == 0)
		cout << "Opiskelijaa ei loydy" << endl;

}
void Koulutusohjelma::paivitaKoulutusohjelmanOpiskelija()
{
	string nimi;
	cout << "Opiskelijanumero? " << endl;
	getline(cin, nimi);

	int apu = 0;

	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		//jos opiskelija löytyy, ajetaan sama funktio jolla uusi opiskelija lisättäisiin
		//jolloin uusi data yksinkertaisesti yliajaa vanhan
		cout << opiskelijat_.at(i).annaOpiskelijanumero() << endl;
		string apu = opiskelijat_.at(i).annaOpiskelijanumero();
		if (opiskelijat_.at(i).annaOpiskelijanumero() == nimi)
		{
			
			opiskelijat_.at(i).kysyTiedot();
			apu = 1;
		}
	}
	if (apu == 0)
		cout << "Opiskelijaa ei löydy!" << endl;
}

bool Koulutusohjelma::lueOpettajat()
{
		ifstream tied;
		string ko_nimi, enimi, snimi, osoite, puhelin, tunnus, opetusala, apu, apu_palkka;
		double palkka;
		//avaa opettajien datan sisältävän tiedoston
		tied.open(polku_ + "Opettaja.csv");
		if (tied.is_open()){
			while (tied.peek() != EOF){
				getline(tied, ko_nimi, ';');
				if (nimi_ == ko_nimi){
					getline(tied, enimi, ';');
					getline(tied, snimi, ';');
					getline(tied, osoite, ';');
					getline(tied, puhelin, ';');
					getline(tied, tunnus, ';');
					getline(tied, apu_palkka, ';');
					palkka = atof(apu_palkka.c_str());
					getline(tied, opetusala, '\n');
					opettajat_.push_back(Opettaja(enimi, snimi, osoite, puhelin, tunnus, palkka, opetusala));
					//lukee puolipisteillä erotellun datan, antaa ne oikeille muuttujille ja lisää be opettajat_ -vektoriin
				}
				else
					getline(tied, apu, '\n'); //luetaan rivin yli
			}
			return true;
		}
		return false;
	}

bool Koulutusohjelma::lueOpiskelijat()
{
		ifstream tied;
		string ko_nimi, enimi, snimi, osoite, puhelin, opiskelijanumero,apu;
		//avaa opiskelijoiden datan sisältävän tiedoston
		tied.open(polku_ + "Opiskelija.csv");
		if (tied.is_open()){
			while (tied.peek() != EOF){
				getline(tied, ko_nimi, ';');
				if (nimi_ == ko_nimi){
					getline(tied, enimi, ';');
					getline(tied, snimi, ';');
					getline(tied, osoite, ';');
					getline(tied, puhelin, ';');
					getline(tied, opiskelijanumero, '\n');
					opiskelijat_.push_back(Opiskelija(enimi, snimi, osoite, puhelin, opiskelijanumero));
					//lukee puolipisteillä erotellun datan, antaa ne oikeille muuttujille ja lisää be opiskelijat_ -vektoriin
				}
				else
					getline(tied, apu, '\n'); //luetaan rivin yli
			}
			return true;
		}
		return false;
	}


void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}


string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}
