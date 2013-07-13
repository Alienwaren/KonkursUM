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
	//#zacz¹tki AI przeciwnika;
	bool ruchDol(bool krok);
	bool ruchGora(bool krok);
	bool ruchLewo(bool krok);
	bool ruchPrawo(bool krok);
	int ruchy[4];
	//~#zacz¹tki AI przeciwnika;
	void ustawObwiednie();
	~enemy(void);
	Sprite duchWrog;
	FloatRect kolizjaWrog;
	Time krok1;
	Time krok2;
	bool zycieWaz;
protected:
	Texture grafikaWrog;
	bool ruszylKrok1;
	
};

