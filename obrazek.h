#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using sf::Color;
using sf::Texture;
using sf::Sprite;
using sf::FloatRect;

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
