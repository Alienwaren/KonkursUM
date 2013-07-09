#include "walka.h"

walka::walka(void)
{
	wystapila = false;
}
int walka::sprawdzKolizje(FloatRect zrodlo, FloatRect cel)
{
	if(zrodlo.intersects(cel))
	{
		cout << "Znaleziono kolizje!" << endl;
		wystapila = true;
	}
	return wystapila; 
}

walka::~walka(void)
{
}
