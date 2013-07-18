#include "starozytna.h"


starozytna::starozytna(void)
{
	czasLotu = milliseconds(500);
	nazwaZaklecia = "Staro¿ytna Strza³a";
	
}
void starozytna::zaladuj()
{
		if(!teksturaZaklecia.loadFromFile(NULL))
		{
			//narysowac teksture zaklec
		}
}


starozytna::~starozytna(void)
{
}
