#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "obrazek.h"
#include "mysz.h"
#include "czcionki.h"
#include "czesc.h"
using namespace sf;
int main()
{
    RenderWindow oknoGry(VideoMode(1024, 768), "Okno Glowne", Style::Close);
	obrazek obrazekJeden;
	mysz myszGry;
	czesc puzleJeden;
	czcionki napisWersji;
	obrazekJeden.zaladuj();
	napisWersji.zaladuj();
	puzleJeden.zaladuj();
	Event Zdarzenia;
	while(oknoGry.isOpen())
	{
	myszGry.pobierzPozycjeMyszy();
	
		while(oknoGry.pollEvent(Zdarzenia))
		{
			if(Zdarzenia.type == Event::Closed)
			{
				oknoGry.close();
				return 0;
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left))
			{
			}
		}
		
		oknoGry.clear();
		oknoGry.draw(obrazekJeden.duchObrazek);
		oknoGry.draw(napisWersji.wypisz);
	//	oknoGry.draw(puzleJeden.
		oknoGry.display();
	}
    return 0;
}