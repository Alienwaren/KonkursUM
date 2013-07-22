#pragma once
#ifndef _H_JEDNOSTKA_
#define _H_JEDNOSTKA_
#include <SFML\Graphics.hpp>
using namespace sf;
class jednostka
{
public:
	jednostka(void);
	~jednostka(void);
	float pozycja_x;
	float pozycja_y;
	int zasiegWzroku;
	int ustawZasieg();
};

#endif _H_JEDNOSTKA_