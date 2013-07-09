#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "jednostka.h"
#ifndef _H_postac_
#define _H_postac_
using namespace sf;
class postaæ :
	public jednostka
{
public:
	postaæ(void);
	int zaladuj();
	bool czyZyje();
	~postaæ(void);
	Sprite duchPostaci;
	FloatRect kolizja;
	bool sprawdzKolizje();
	void ustawObwiednie();
protected:
	int str;
	int intel;
	int agl;
	int AC;
	int hp;
	int mana;
	int lvl;
	int exp;
	int obr;
	int iloscKrokow;
	bool zyje;
	float przyspieszenie;
	float szybkosc;
	float maxSzybkosc;
	Texture grafikaPostaci;
	
	
};

#endif _H_postac_