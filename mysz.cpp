#include "mysz.h"


mysz::mysz(void)
{
	
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

mysz::~mysz(void)
{
}
