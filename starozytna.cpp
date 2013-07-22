#include "starozytna.h"

/* 
ustwawienie atrybutów zaklecia, metdy i zmienne mówi¹ same za siebie ;)
*/
starozytna::starozytna(void)
{
	czasLotu = milliseconds(500);
	nazwaZaklecia = "Starozytna Strzala";
	szybkoscLotu = 1.f; // inaczej przyspieszenie ;p
	maxSzybkosc = 100;
	szybkosc = 0;
	obrazenia = 20;
	
}
int starozytna::zaladuj()
{
		if(!teksturaZaklecia.loadFromFile("starozytna.png"))
		{
			cout << "Zaklecie" << nazwaZaklecia << "nie moze zostac wczytane" << endl;
			return EXIT_FAILURE;
		}else
		{
			teksturaZaklecia.setSmooth(true);
			duchZaklecie.setTexture(teksturaZaklecia);
			duchZaklecie.setOrigin(32,32);
			duchZaklecie.setScale(0.5f, 0.5f);
			duchZaklecie.setPosition(400, 590);
		}
		return EXIT_SUCCESS;
}
void starozytna::lot()
{
		szybkoscLotu++;
		szybkosc =+ szybkoscLotu;
		duchZaklecie.move(0, -szybkoscLotu);
		if(szybkosc > maxSzybkosc)
		{
			szybkosc = maxSzybkosc;
		}
	
}
void starozytna::ustawObwiednie()
{
	kolizja = duchZaklecie.getGlobalBounds();
}

starozytna::~starozytna(void)
{
}
