#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;
class mysz
{
public:
	mysz(void);
	Vector2i pozycjaMyszy;
	Vector2i pobierzPozycjeMyszy();
	Vector2f pozycjaFloat;
	~mysz(void);
};

