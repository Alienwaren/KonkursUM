#include "mysz.h"


mysz::mysz(void)
{
	for(int i = 0; i >= 9; i++)
	{
		wystapilyKolizje[i] = false;
	}
}
/*
Pobranie i zamiana koordynat myszy z Vector2f na Vector2i
*/
Vector2i mysz::pobierzPozycjeMyszy() // do zrobienia jako funkcja, patrz main
{
	pozycjaMyszy = Mouse::getPosition();
	pozycjaFloat = static_cast<Vector2f>(pozycjaMyszy);  // zmiana typu z Vector2i na Vector2f
	return pozycjaMyszy;
}
void mysz::ustawParametryKwadratu()
{
	kwadratMysz.setSize(Vector2f (32,32));
	kwadratMysz.setFillColor(Color::White);
	kolizjaKwadratMysz = kwadratMysz.getGlobalBounds();
}
void mysz::sprawdzKolizje(FloatRect porownywana, int krokPetli)
{
	if(kolizjaKwadratMysz.intersects(porownywana))
	{
		wystapilyKolizje[krokPetli] = true;
	}
}
mysz::~mysz(void)
{
}
