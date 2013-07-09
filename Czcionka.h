#pragma once
#include <SFML/Graphics.hpp>
#ifndef _H_CZCIONKA_
#define _H_CZCIONKA_
using namespace sf;
class Czcionka
{
public:
	Czcionka(void);
	int zaladujCzcionke();
	~Czcionka(void);
	Text Napis;
protected:
	Font Arial;
	
};

#endif //_H_CZCIONKA_