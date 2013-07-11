#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "jednostka.h"
#ifndef _H_postac_
#define _H_postac_
using namespace sf;
class posta� :
	public jednostka
{
public:
	posta�(void);
	float zaladuj();
	bool czyZyje();
	void ruchDol();
	void ruchGora();
	void ruchLewo();
	void ruchPrawo();
	~posta�(void);
	Sprite duchPostaci;
	FloatRect kolizja;
	bool sprawdzKolizje();
	void ustawObwiednie();
	float obr;
	float hp;
	float cryt;
protected:
	float str;
	float intel;
	float agl;
	float AC;
	float mana;
	float lvl;
	float exp;
	float iloscKrokow;
	bool zyje;
	float przyspieszenie;
	float szybkosc;
	float maxSzybkosc;
	Texture grafikaPostaci;
	
	
};

#endif _H_postac_