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
	void zaladuj();
	bool sprawdzKolizje();
	float zadajObrazenia();
	FloatRect ustawObwiednie();
	
};

