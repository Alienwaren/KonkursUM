#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using namespace sf;
class zaklecia
{
public:
	zaklecia(void);
	void lot();
	~zaklecia(void);
	float obrazenia;
	float szybkoscLotu;
	float szybkosc;
	float maxSzybkosc;
	float koszt;
	Time czasLotu;
	FloatRect czyUderzyl;
	string nazwaZaklecia;
	Texture teksturaZaklecia;
	Sprite duchZaklecie;
	Vector2f pozycja;
	Vector2f pobierzPozycje();
};

