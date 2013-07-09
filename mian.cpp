/*
	TODO: dodaj UI
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "plansza.h"
#include "postaæ.h"
#include "Czcionka.h"
#include "enemy.h"
#include "walka.h"
#include "zegar.h"
using namespace std;
using namespace sf;



int main()
{
  plansza mapa;
  postaæ gracz_glowny;
  Czcionka Wersja;
  enemy waz;
  walka systemWalki;
  zegar zegarSys;

    mapa.zaladuj();
	gracz_glowny.zaladuj();
	waz.wczytaj();
	Wersja.zaladujCzcionke();
	 bool zycieGracz = gracz_glowny.czyZyje();
	 bool zycieWaz = waz.czyZyje();

  RenderWindow Okno(VideoMode(800, 600), "Render", Style::Close);
  Okno.setFramerateLimit(60);

  					
	

   Event zdarzenia; // inicjacja zmiennej typu Event do wylapywania zdarzen
 

	  while(Okno.isOpen()) // petla czasu
	 {
		zegarSys.wlacz_zegar();
		zycieGracz = gracz_glowny.czyZyje();
		zycieWaz = waz.czyZyje();
		

	  
			while (Okno.pollEvent(zdarzenia)) // petla zdarzen
			{
				zegarSys.wyswietlCzas();
				gracz_glowny.ustawObwiednie();
	        	waz.ustawObwiednie();
				zegarSys.sprawdzCzas(zegarSys.minal1, waz.krok1);
				waz.ruch(zegarSys.porownanieCzas);
			
				 if(zdarzenia.type == Event::Closed) // zdarzenie reaguj¹ce na zamkniêcie okna
				 {
					

							Okno.close();
							return 0;
											

				 }
				 if(Keyboard::isKeyPressed(Keyboard::W) && (Keyboard::isKeyPressed(Keyboard::LControl))) // reakcja na wcisniecie skrótu ctrl + w
				{
				
							Okno.close();
								return 0;
										
										


				}
				if(Keyboard::isKeyPressed(Keyboard::W)) // ruch postaci, ujemne do góry lub w lewo
				{
					gracz_glowny.duchPostaci.move(0, -5);
				
				}
				if(Keyboard::isKeyPressed(Keyboard::S))
				{
					gracz_glowny.duchPostaci.move(0, 5);
						
				}
				if(Keyboard::isKeyPressed(Keyboard::A))
				{
					gracz_glowny.duchPostaci.move(-5, 0);
						
				}
				if(Keyboard::isKeyPressed(Keyboard::D))
				{
					gracz_glowny.duchPostaci.move(5, 0);
					
				}
				if(Keyboard::isKeyPressed(Keyboard::R))
				{
					zegarSys.zegar1.restart();
				}
				if(gracz_glowny.kolizja.intersects(waz.kolizjaWrog))
				{
						cout << "wykryto kolizje" << endl;
						
		
				}
				
			}


	  Okno.clear(Color::Black);
	  Okno.draw(mapa.Mapa);
	  if(zycieGracz == true)
	  {
		 
		  
		  Okno.draw(gracz_glowny.duchPostaci);
		  	
	  }
	  if(zycieWaz == true)
	  {

		  Okno.draw(waz.duchWrog);
	  }
	
	  Okno.draw(Wersja.Napis);

	  Okno.display();
			
	  
  }
	  
		
			return 0;

}
	  