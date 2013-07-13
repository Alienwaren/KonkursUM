#pragma once
#include <SFML\System.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class zegar
{
public:
	zegar(void);
	Time wlaczZegar();
	 Clock zegar1;  
	 bool sprawdzCzas(Time porownywana, Time porownanie);
	 Time wyswietlCzas();
	 Time minal1;
	 Time krok1;
	 bool porownanieCzas;
	 void restartZegar();
	~zegar(void);
};

