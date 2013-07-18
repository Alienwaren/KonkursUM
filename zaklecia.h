#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using std::string;
using namespace sf;
class zaklecia
{
public:
	zaklecia(void);
	~zaklecia(void);
	float obrazenia;
	Time czasLotu;
	FloatRect czyUderzyl;
	string nazwaZaklecia;
	Texture teksturaZaklecia;
	Sprite duchZaklecie;

};

