#include "czesc.h"


czesc::czesc(void)
{
	ilosc = 7; // tablice liczymy od zera ;p
}
void czesc::zaladuj()
	/* Dla niekumatego, zrobilem zamiane z int (czyli z naszego i w petli) na string abym mogl
	zaladowac pliki czesci do tablicy za pomoc¹ petli. Nie pytaj jak d³ugo tego szuka³em.
	*/
{
	for(int i = 0; i <= ilosc; i++)
	{
		ostringstream nazwa;
		nazwa << i;
		nazwaPliku = nazwa.str();
		if(!czesciObrazka[i].loadFromFile(nazwaPliku))
		{
			cout << "Nie moge zaladowac pliku" << i << "czesci obrazka" << endl;
		}else
		{

		}
	}
}

czesc::~czesc(void)
{
}
