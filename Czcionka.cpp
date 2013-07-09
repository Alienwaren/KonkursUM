#include "Czcionka.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace sf;
using namespace std;
Czcionka::Czcionka(void)
{
}
int Czcionka::zaladujCzcionke()
{
	if(!Arial.loadFromFile("Arial.ttf"))
	{
		cout << "Nie moge zaladowac pliku czcionki" << endl;
		return EXIT_FAILURE;
	}else
	{
	Napis.setFont(Arial);
	Napis.setString("Beta Prealphy 0.0.0.1");
	Napis.setCharacterSize(20);
	Napis.setColor(Color::White);
	Napis.setStyle(Text::Bold);
	}
}

Czcionka::~Czcionka(void)
{
}
