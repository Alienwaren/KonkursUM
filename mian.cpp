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
using std::cout;
using namespace sf;



int main()
{
	/* utworzenie obiektów */
  plansza mapa;
  postaæ gracz_glowny;
  Czcionka Wersja;
  enemy waz;
  walka systemWalki;
  zegar zegarSys;
  zegar zegarWalki;

    mapa.zaladuj();
	gracz_glowny.zaladuj();
	waz.wczytaj();
	Wersja.zaladujCzcionke();
	 gracz_glowny.zycieGracz = gracz_glowny.czyZyje();
	 waz.zycieWaz = waz.czyZyje();

  RenderWindow Okno(VideoMode(800, 600), "Render", Style::Close);
  Okno.setFramerateLimit(60);

  					
	

   Event zdarzenia; // inicjacja zmiennej typu Event do wylapywania zdarzen
 

	  while(Okno.isOpen()) // petla czasu
	 {
		zegarSys.wlaczZegar();
		gracz_glowny.zycieGracz = gracz_glowny.czyZyje();
		waz.zycieWaz = waz.czyZyje();
		//zegarSys.wyswietlCzas();
		gracz_glowny.ustawObwiednie();
	    waz.ustawObwiednie();
		zegarSys.sprawdzCzas(zegarSys.minal1, waz.krok1);
		waz.ruch(zegarSys.porownanieCzas); //jesli porownanieCzas bêdzie false to w¹¿ sie nie ruszy, sprawdzana jest zmienna w tym przypadku typu Time krok1 -> patrz enemy.h
		zegarWalki.wlaczZegar();
		zegarWalki.sprawdzCzas(zegarWalki.minal1, systemWalki.przerwa);
		
			while (Okno.pollEvent(zdarzenia)) // petla zdarzen
			{
				
			
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
					gracz_glowny.ruchGora();
				
				}
				if(Keyboard::isKeyPressed(Keyboard::S))
				{
					gracz_glowny.ruchDol();
						
				}
				if(Keyboard::isKeyPressed(Keyboard::A))
				{
					gracz_glowny.ruchLewo();
						
				}
				if(Keyboard::isKeyPressed(Keyboard::D))
				{
					gracz_glowny.ruchPrawo();
					
				}
				if(Keyboard::isKeyPressed(Keyboard::R)) // DO WYWALENIA, TYLKO DO DEWELOPERKI!
				{
					zegarSys.zegar1.restart();
				}
				if(gracz_glowny.kolizja.intersects(waz.kolizjaWrog)) //Podstawa systemu walki, komentarza pod spodem nie ruszac za chiny ludowe, UNDER CONSTRUCTION!
				{
					/*	bool kolizja = true;
						systemWalki.rozpocznijWalke(kolizja);*/
					systemWalki.rozpoczeta = true;
						if(systemWalki.rozpoczeta == true && zegarSys.minal1 >= systemWalki.przerwa)
						{
							systemWalki.walcz(gracz_glowny.hp, gracz_glowny.obr, waz.hp, waz.obr);
							gracz_glowny.hp = systemWalki.graczHP;
							waz.hp = systemWalki.przeciwnikHP;
							if(systemWalki.graczHP <= 0 || systemWalki.przeciwnikHP <= 0)
							{
								systemWalki.rozpoczeta = false;
							}
						}
						/*systemWalki.walcz(gracz_glowny.hp, gracz_glowny.obr, waz.hp, waz.obr);
						waz.hp = systemWalki.przeciwnikHP;
						gracz_glowny.hp = systemWalki.graczHP;
						gracz_glowny.zyje = gracz_glowny.czyZyje();
						waz.zyje = waz.czyZyje();
						zegarWalki.restartZegar();*/
				}else
				{
					bool kolizja = false;
					systemWalki.rozpocznijWalke(kolizja);
				}
				
			}


	  Okno.clear(Color::Black);
	  Okno.draw(mapa.Mapa);
	  if(gracz_glowny.zycieGracz == true)
	  {
		 
		  
		  Okno.draw(gracz_glowny.duchPostaci);
		  	
	  }
	  if(waz.zycieWaz == true)
	  {

		  Okno.draw(waz.duchWrog);
	  }
	
	  Okno.draw(Wersja.Napis);

	  Okno.display();
			
	  
  }
	  
		
			return 0;

}
	  