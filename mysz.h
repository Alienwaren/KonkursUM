#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using sf::Mouse;
using sf::Vector2i;
using sf::Vector2f;
class mysz
{
public:
	mysz(void);
	Vector2i pozycjaMyszy;
	Vector2i pobierzPozycjeMyszy();
	Vector2f pozycjaFloat;
	void ustawPozycje();
	~mysz(void);
};

