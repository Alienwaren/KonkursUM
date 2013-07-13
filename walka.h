#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "postaæ.h"
#include "enemy.h"
#include <ctime>
using std::cout;
using std::endl;
using namespace sf;
class walka 
{
public:
	walka(void);
	float walcz(float walczacyHP, float walczacyObr, float broniacyHP, float broniacyObr);
	float graczHP;
	float przeciwnikHP;
	~walka(void);
	bool rozpocznijWalke(bool kolizja);
	bool rozpoczeta;
	bool komunikat;
	bool komunikat2;
	bool zycieGracz;
	bool zycieWrog;
	Time przerwa;
};

