#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using std::cout;
using std::endl;
using std::string;
class czcionki
{
public:
	czcionki(void);
	Font napis;
	Text wypisz;
	int zaladuj();
	~czcionki(void);
};

