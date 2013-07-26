#pragma once
#include "obrazek.h"
#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::ostringstream;
using std::cout;
using std::endl;
class czesc :
	public obrazek
{
public:
	czesc(void);
	Texture czesciObrazka[8];
	Sprite duchyObrazka[8];
	int ilosc;
	string nazwaPliku;
	void zaladuj();
	~czesc(void);
};

