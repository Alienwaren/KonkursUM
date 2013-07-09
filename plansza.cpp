#include "plansza.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
plansza::plansza(void)
{
}

int plansza::zaladuj()
{
	if(!Tlo.loadFromFile("traffka2.png"))
	{
		cout << "Nie udalo zaladowac do pamieci pliku tekstury, aplikacja wyjdzie" << endl;
		return EXIT_FAILURE;
	}else
	{
	Tlo.setSmooth(true);
	Tlo.setRepeated(true);
	Mapa.setTexture(Tlo);
	}
}


	


plansza::~plansza(void)
{
}
