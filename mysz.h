#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
using sf::Mouse;
using sf::Vector2i;
using sf::Vector2f;
using sf::RectangleShape;
using sf::Color;
using sf::FloatRect;
using std::cout;
using std::endl;
class mysz
{
public:
	mysz(void);
	Vector2i pozycjaMyszy;
	Vector2i pobierzPozycjeMyszy();
	Vector2f pozycjaFloat;
	RectangleShape kwadratMysz;
	FloatRect kolizjaKwadratMysz;
	bool wystapilyKolizje[9];
	void ustawParametryKwadratu();
	void ustawPozycje();
	void sprawdzKolizje(FloatRect porownywana, int krokPetli); // patrz main, all bêdzie w pêtli for 
	~mysz(void);

};

