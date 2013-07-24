#include "mysz.h"


mysz::mysz(void)
{
}
Vector2i mysz::pobierzPozycjeMyszy()
{
	pozycjaMyszy = Mouse::getPosition();
	pozycjaFloat = static_cast<Vector2f>(pozycjaMyszy); // zmiana typu z Vector2i na Vector2f :D
	return pozycjaMyszy;
}

mysz::~mysz(void)
{
}
