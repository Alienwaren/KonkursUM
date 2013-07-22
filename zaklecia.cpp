#include "zaklecia.h"


zaklecia::zaklecia(void)
{
}
Vector2f zaklecia::pobierzPozycje()
{
	pozycja = duchZaklecie.getPosition();
	return pozycja;
}

zaklecia::~zaklecia(void)
{
}
