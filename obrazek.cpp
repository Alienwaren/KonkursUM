#include "obrazek.h"


obrazek::obrazek(void)
{
}
void obrazek::stworz()
{
}
void obrazek::nadajKolor()
{

}
void obrazek::zmienPozycje(float x, float y)
{
	duchObrazek.setPosition(x,y);
}
int obrazek::zaladuj()
{
	if(!teksturaObrazka.loadFromFile("01.png"))
	{
		return EXIT_FAILURE;
	}else
	{
		duchObrazek.setTexture(teksturaObrazka);
		duchObrazek.setOrigin(400,300);
		duchObrazek.setPosition(512, 393);
		duchObrazek.setColor(Color::Yellow);
		return EXIT_SUCCESS;
	}
}
void obrazek::ustawPozycje(float x, float y)
{
	duchObrazek.setPosition(x,y);
}
obrazek::~obrazek(void)
{
}
