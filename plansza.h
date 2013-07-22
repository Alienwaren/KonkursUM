#pragma once
#ifndef _H_PLANSZA_
#define _H_PLANSZA_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
class plansza
{
public:
	plansza(void);
	int zaladuj();
	void ustawObwiednie();
	~plansza(void);
	Sprite Mapa;
	FloatRect obwiednia;
protected:
	Texture Tlo;
	
	
};

#endif _H_PLANSZA_