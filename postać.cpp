#include "postaæ.h"

#include <iostream>

using namespace std;
// Inicjacja w konstruktorze tymczasowych atrybutów postaci
postaæ::postaæ(void)
{
	str = 10;
	intel = 20;
	agl = 15;
	mana = intel * 10;
	hp = str * 10;
	obr = str * 0,5;
	zyje = false;
	
}
//ladowanie i inicjacja grafiki gracza glowniego // TODO: ulepszyæ jego grafikê
int postaæ::zaladuj()
{
	if(!grafikaPostaci.loadFromFile("char.png"))
	{
		cout << "Nie mozna zaladowac pliku postaci" << endl;
		return EXIT_FAILURE;
	}else
	{
	grafikaPostaci.setSmooth(true); // wygladzanie krawedzi
	grafikaPostaci.setRepeated(false);
	duchPostaci.setTexture(grafikaPostaci);
	duchPostaci.setScale(Vector2f(0.5f, 0.5f)); // zeskalowanie o polowe 
	duchPostaci.setOrigin(Vector2f(65, 21));	// zmiana punktu zaczepienia na œrodek gracza
	duchPostaci.move(400, 590); // poruszenie postaci
	
	}
}
void postaæ::ustawObwiednie()
{
	kolizja = duchPostaci.getGlobalBounds();

}
bool postaæ::czyZyje()
{
	if(hp <= 0)
	{
		zyje = false;
	}else
	{
		zyje = true;
	}
	return zyje;
	
}



postaæ::~postaæ(void)
{
}
