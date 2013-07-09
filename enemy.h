#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include "postaæ.h"
using namespace sf;
class enemy 
	: public postaæ
{
public:
	enemy(void);
	int wczytaj();
	//zacz¹tki AI przeciwnika;
	bool ruch(bool krok);
	void ustawObwiednie();
	~enemy(void);
	Sprite duchWrog;
	FloatRect kolizjaWrog;
	Time krok1;
protected:
	Texture grafikaWrog;
	bool ruszylKrok1;
	
};

