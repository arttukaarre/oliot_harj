
#include "Sovellus.h"
#include <iostream>

int main()
{
	//luodaan sovellus, jonka koulu TAMK ja tiedostojen polku jotain
	Sovellus sov("TAMK", "polku tahan");

	//ajetaan itse sovellus
	sov.aja();

	system("pause");
	return 0;
}
