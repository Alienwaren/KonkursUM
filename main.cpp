#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "obrazek.h"
#include "mysz.h"
#include "czcionki.h"
#include "czesc.h"
#include "kwadrat.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace sf;

int main()
{
	int i = 1;
    RenderWindow oknoGry(VideoMode(1024, 768), "Okno Glowne", Style::Close);
	obrazek obrazekJeden;
	mysz myszGry;
	czesc puzleJeden;
	czcionki napisWersji;
	obrazekJeden.zaladuj();
	napisWersji.zaladuj();
	puzleJeden.zaladuj();
	Event Zdarzenia;
	kwadrat kwadratMain;
	puzleJeden.ustawPozycje();
	oknoGry.setFramerateLimit(60);
	while(oknoGry.isOpen())
	{	
	// #TODO: Do zrobienia jako funkcja w mysz.cpp
	myszGry.pozycjaMyszy = Mouse::getPosition(oknoGry);
	myszGry.pozycjaFloat = static_cast<Vector2f>(myszGry.pozycjaMyszy);  // zmiana typu z Vector2i na Vector2f
	// #ENDTODO
	
	puzleJeden.pobierzPozycje();
	

		while(oknoGry.pollEvent(Zdarzenia))
		{
			if(Zdarzenia.type == Event::Closed)
			{
				oknoGry.close();
				return 0;
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left) && Keyboard::isKeyPressed(Keyboard::Num1))
			{
				puzleJeden.duchyObrazka[1].setPosition(myszGry.pozycjaFloat.x,myszGry.pozycjaFloat.y);
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left) && Keyboard::isKeyPressed(Keyboard::Num2))
			{
				puzleJeden.duchyObrazka[2].setPosition(myszGry.pozycjaFloat.x,myszGry.pozycjaFloat.y);
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left) && Keyboard::isKeyPressed(Keyboard::Num3))
			{
				puzleJeden.duchyObrazka[3].setPosition(myszGry.pozycjaFloat.x,myszGry.pozycjaFloat.y);
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left) && Keyboard::isKeyPressed(Keyboard::Num4))
			{
				puzleJeden.duchyObrazka[4].setPosition(myszGry.pozycjaFloat.x,myszGry.pozycjaFloat.y);
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left) && Keyboard::isKeyPressed(Keyboard::Num5))
			{
				puzleJeden.duchyObrazka[5].setPosition(myszGry.pozycjaFloat.x,myszGry.pozycjaFloat.y);
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left) && Keyboard::isKeyPressed(Keyboard::Num6))
			{
				puzleJeden.duchyObrazka[6].setPosition(myszGry.pozycjaFloat.x,myszGry.pozycjaFloat.y);
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left) && Keyboard::isKeyPressed(Keyboard::Num7))
			{
				puzleJeden.duchyObrazka[7].setPosition(myszGry.pozycjaFloat.x,myszGry.pozycjaFloat.y);
			}
			if(Mouse::isButtonPressed(Mouse::Button::Left) && Keyboard::isKeyPressed(Keyboard::Num8))
			{
				puzleJeden.duchyObrazka[8].setPosition(myszGry.pozycjaFloat.x,myszGry.pozycjaFloat.y);
			}
			
		 }
		
		oknoGry.clear();
		oknoGry.draw(obrazekJeden.duchObrazek);
		
		for(i = 1; i <= puzleJeden.ilosc; i++)
		{
			oknoGry.draw(puzleJeden.duchyObrazka[i]);
		}
		
		oknoGry.draw(napisWersji.wypisz);
		oknoGry.draw(kwadratMain.kwadratMyszy);
		oknoGry.display();
	}
    return 0;
}