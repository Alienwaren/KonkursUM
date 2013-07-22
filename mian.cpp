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
#include "starozytna.h"
#include <ctime>
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
  starozytna strzala;
  /* wywo³anie pierwszych metod obiektów, ³adowanie itd; */
    mapa.zaladuj();
	gracz_glowny.zaladuj();
	waz.wczytaj();
	Wersja.zaladujCzcionke();
	gracz_glowny.zycieGracz = gracz_glowny.czyZyje();
	waz.zycieWaz = waz.czyZyje();
	strzala.zaladuj();
	bool wcisnieta = false; // przeniesc do klasy zaklecia


  RenderWindow Okno(VideoMode(800, 600), "Render", Style::Close); // utworzenie okna i ustawienie limitu FPS
  Okno.setFramerateLimit(60);

  					
	

   Event zdarzenia; // inicjacja zmiennej typu Event do wylapywania zdarzen
 

	  while(Okno.isOpen()) // dopóki okno jest otwarte
	 {
		
		zegarSys.wlaczZegar();
		gracz_glowny.zycieGracz = gracz_glowny.czyZyje();
		waz.zycieWaz = waz.czyZyje();
		//zegarSys.wyswietlCzas();
		gracz_glowny.ustawObwiednie();
	    waz.ustawObwiednie();
		zegarSys.sprawdzCzas(zegarSys.minal1, waz.krok1);
		waz.ruchGora(zegarSys.porownanieCzas); //jesli porownanieCzas bêdzie false to w¹¿ sie nie ruszy, sprawdzana jest zmienna w tym przypadku typu Time krok1 -> patrz enemy.h
		zegarWalki.wlaczZegar();
		zegarWalki.sprawdzCzas(zegarWalki.minal1, systemWalki.przerwa); // sprawdzenie czy cios moze byc zadany, do zmiany bo na sztywno ustawiono
		mapa.ustawObwiednie();
		strzala.ustawObwiednie();
		strzala.pobierzPozycje();
		
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
				if(Keyboard::isKeyPressed(Keyboard::Space) && wcisnieta == false)
				{
					wcisnieta = true;
				}
			/*	if(wcisnieta = true)
				{
					strzala.lot();
				}*/
				if(gracz_glowny.kolizja.intersects(waz.kolizjaWrog)) //Podstawa systemu walki, komentarza pod spodem nie ruszac za chiny ludowe, UNDER CONSTRUCTION!
				{

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
				}
			/*	if(strzala.kolizja.intersects(waz.kolizjaWrog))
				{
					strzala.duchZaklecie.move(400, 590);
				}*/
				
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
	  if(wcisnieta == true)
	  Okno.draw(strzala.duchZaklecie);

	  Okno.display();
			

	  
	  }


	return 0;
 }
	
 