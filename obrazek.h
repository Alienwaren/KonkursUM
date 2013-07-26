#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

class obrazek
{
public:
	obrazek(void);
	void stworz();
	void nadajKolor();
	void zmienPozycje(float x, float y);
	void ustawPozycje(float x, float y);
	int zaladuj();
	~obrazek(void);
	Texture teksturaObrazka;
	Sprite duchObrazek;
};
