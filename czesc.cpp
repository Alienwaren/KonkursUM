#include "czesc.h"


czesc::czesc(void)
{
	ilosc = 8; 
	png = ".png";
	x = 212;
	y = 384;
}
void czesc::zaladuj()
	/* Dla niekumatego, zrobilem zamiane z int (czyli z naszego i w petli) na string abym mogl
	zaladowac pliki czesci do tablicy za pomoc¹ petli. Nie pytaj jak d³ugo tego szuka³em.
	*/
{
	for(int i = 1; i <= ilosc; i++)
	{
		ostringstream nazwa;
		nazwa << i;
		nazwaPliku = nazwa.str();
		nazwaPliku += png;
		if(!czesciObrazka[i].loadFromFile(nazwaPliku))
		{
			cout << "Nie moge zaladowac pliku" << i << "czesci obrazka" << endl;
		}
			duchyObrazka[i].setTexture(czesciObrazka[i]); // ustawienie sprite od tekstur
			duchyObrazka[i].setOrigin(100, 150);
			obwiednieKolizje[i] = duchyObrazka[i].getGlobalBounds();

	}
}
void czesc::pobierzPozycje()
{
	for(int i = 1; i <= ilosc; i++)
	{
		pozycjaX[i] = duchyObrazka[i].getPosition().x;
		pozycjaY[i] = duchyObrazka[i].getPosition().y;
	}
	
}
void czesc::ustawPozycje()
{
	for(int i = 1; i <= ilosc; i++)
	{
		duchyObrazka[i].setPosition(x, 150);
	}
	
}
void czesc::ruch()
{
	for(int i = 1; i <= ilosc; i++)
	{
		odleglascPomiedy = 10;
		duchyObrazka[i].move(odleglascPomiedy * i, 0);
		
		
	}
}
czesc::~czesc(void)
{
}
