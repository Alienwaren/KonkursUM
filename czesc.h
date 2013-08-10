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
	Texture czesciObrazka[9];
	Sprite duchyObrazka[9];
	float dodajKoordynaty();
	void ruch();
	float x,y, pozycjaX[9], pozycjaY[9];
	void zaladuj();
	void pobierzPozycje();
	void ustawPozycje(); // setPosition
	int ilosc;
	~czesc(void);
protected:
	string nazwaPliku;
	string png;
	int odleglascPomiedy;

};


