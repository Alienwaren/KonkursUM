#include "czcionki.h"


czcionki::czcionki(void)
{
}
int czcionki::zaladuj()
{
	if(!napis.loadFromFile("czcionka1.ttf"))
	{
		cout << "Nie udalo sie zaladowac czcionki" << endl;
		return EXIT_FAILURE;
	}
	
		wypisz.setFont(napis);
		wypisz.setCharacterSize(30);
		wypisz.setString("Puzzle inDev 0.0.0.2 kawa�ki");
		wypisz.setColor(Color::White);
		return EXIT_SUCCESS;
	
}

czcionki::~czcionki(void)
{
}
