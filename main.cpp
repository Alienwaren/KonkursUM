#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "obrazek.h"
#include "mysz.h"
using namespace sf;
int main()
{
    RenderWindow oknoGry(VideoMode(1024, 768), "Okno Glowne", Style::Close);
	while(oknoGry.isOpen())
	{
		obrazek obrazekJeden;
		mysz myszGry;
		myszGry.pobierzPozycjeMyszy();
		obrazekJeden.zaladuj();
		Event Zdarzenia;
		//obrazekJeden.zmienPozycje(myszGry.pozycjaFloat.x, myszGry.pozycjaFloat.y);
		while(oknoGry.pollEvent(Zdarzenia))
		{
			if(Zdarzenia.type == Event::Closed)
			{
				oknoGry.close();
				return 0;
			}
			
		}

		oknoGry.clear();
		oknoGry.draw(obrazekJeden.duchObrazek);
		oknoGry.display();
	}
    return 0;
}