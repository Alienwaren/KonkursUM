#pragma once
#include "zaklecia.h"
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;
using std::string;
class starozytna :
	public zaklecia
{
public:
	starozytna(void);
	~starozytna(void);
	void lot(); // okreslenie czy spacja jest wcisnieta, patrz main
	int zaladuj();
	bool sprawdzKolizje();
	float zadajObrazenia();
	FloatRect kolizja;
	void ustawObwiednie();
	Texture teksturaZaklecia;
	Sprite duchZaklecie;
	
};

