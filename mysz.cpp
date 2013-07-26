#include "mysz.h"


mysz::mysz(void)
{
}
Vector2i mysz::pobierzPozycjeMyszy()
{
	pozycjaMyszy = Mouse::getPosition();
	pozycjaFloat = static_cast<Vector2f>(pozycjaMyszy); 
	poprzedniaPozycjaX = pozycjaFloat.x;
	poprzedniaPozycjaY = pozycjaFloat.y;
	return pozycjaMyszy;
}

mysz::~mysz(void)
{
}
