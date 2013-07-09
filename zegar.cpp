#include "zegar.h"


zegar::zegar(void)
{
	
}
Time zegar::wlacz_zegar()
{
	
 
  minal1 = zegar1.getElapsedTime(); // odczytanie czasu z zegara
  return minal1;
}
Time zegar::wyswietlCzas()
{
  cout << minal1.asSeconds() << "\r"; // wyswietlenie czasu jako sekundy
  minal1 = zegar1.getElapsedTime();
  return minal1;

}
bool zegar::sprawdzCzas(Time porownywana, Time porownanie) // porownanie czy ruch moze zostac wykonany, patrz main i zegar.h
{
	porownanieCzas = (porownywana >= porownanie);
	return porownanieCzas;
}

zegar::~zegar(void)
{
}
