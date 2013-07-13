/*
	TODO: dodaj UI
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "plansza.h"
#include "posta�.h"
#include "Czcionka.h"
#include "enemy.h"
#include "walka.h"
#include "zegar.h"
#include <ctime>
using std::cout;
using namespace sf;



int main()
{
	srand(time(NULL)); // maszyna losuj�ca do ruchu, patrz enemy.h, zmienna ruchy[4];
  /* utworzenie obiekt�w */
  plansza mapa;
  posta� gracz_glowny;
  Czcionka Wersja;
  enemy waz;
  walka systemWalki;
  zegar zegarSys;
  zegar zegarWalki;
  /* wywo�anie pierwszych metod obiekt�w, �adowanie itd; */
    mapa.zaladuj();
	gracz_glowny.zaladuj();
	waz.wczytaj();
	Wersja.zaladujCzcionke();
	gracz_glowny.zycieGracz = gracz_glowny.czyZyje();
	waz.zycieWaz = waz.czyZyje();

  RenderWindow Okno(VideoMode(800, 600), "Render", Style::Close);
  Okno.setFramerateLimit(60);

  					
	

   Event zdarzenia; // inicjacja zmiennej typu Event do wylapywania zdarzen
 

	  while(Okno.isOpen()) // dop�ki okno jest otwarte
	 {
		int aktualnyRuch = (rand()% 4 ) + 1; //
		zegarSys.wlaczZegar();
		gracz_glowny.zycieGracz = gracz_glowny.czyZyje();
		waz.zycieWaz = waz.czyZyje();
		//zegarSys.wyswietlCzas();
		gracz_glowny.ustawObwiednie();
	    waz.ustawObwiednie();
		zegarSys.sprawdzCzas(zegarSys.minal1, waz.krok1);
		//waz.ruchGora(zegarSys.porownanieCzas); //jesli porownanieCzas b�dzie false to w�� sie nie ruszy, sprawdzana jest zmienna w tym przypadku typu Time krok1 -> patrz enemy.h
		zegarWalki.wlaczZegar();
		zegarWalki.sprawdzCzas(zegarWalki.minal1, systemWalki.przerwa);
		/*
			Ten switch ustala na podstawie zmiennej aktualnyRuch, w kt�r� stron� ma si� przeciwnik poruszy�
			(na razie jeden, potem wi�cej), na razie nie dzia�a, do naprawy
		*/
		switch (aktualnyRuch)
		{
		case 1:
			waz.ruchGora(zegarSys.porownanieCzas);
			break;
		case 2:
			waz.ruchDol(zegarSys.porownanieCzas);
			break;
		case 3:
			waz.ruchLewo(zegarSys.porownanieCzas);
			break;
		case 4:
			waz.ruchPrawo(zegarSys.porownanieCzas);
			break;
		default:
			break;
		}
		
			while (Okno.pollEvent(zdarzenia)) // petla zdarzen
			{
				
			
				 if(zdarzenia.type == Event::Closed) // zdarzenie reaguj�ce na zamkni�cie okna
				 {
					

							Okno.close();
							return 0;
											

				 }
				 if(Keyboard::isKeyPressed(Keyboard::W) && (Keyboard::isKeyPressed(Keyboard::LControl))) // reakcja na wcisniecie skr�tu ctrl + w
				{
				
							Okno.close();
								return 0;
										
										


				}
				if(Keyboard::isKeyPressed(Keyboard::W)) // ruch postaci, ujemne do g�ry lub w lewo
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
	  