#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class walka
{
public:
	walka(void);
	int sprawdzKolizje(FloatRect zrodlo, FloatRect cel);
	~walka(void);
	bool wystapila;
};

