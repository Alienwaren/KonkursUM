#include "enemy.h"

using namespace sf;
using namespace std;
enemy::enemy(void)
{
	
	str = 5;
	agl = 3;
	intel = 2;
	mana = intel * 10;
	hp = str * 10;
	obr = 0,5 * str;
	krok1 = seconds(5);
	przyspieszenie = 0.1f;
	maxSzybkosc = 10;
	ruszylKrok1 = false;
	iloscKrokow = 0;
	pozycja_x = duchWrog.getPosition();
	zyje = true;
}
int enemy::wczytaj()
{
	if(!grafikaWrog.loadFromFile("snake.png"))
	{
		cout << "Nie moge zaladowac pliku weza" << endl;
		return EXIT_FAILURE;
	}else
	{
		grafikaWrog.setSmooth(true);
		duchWrog.setTexture(grafikaWrog);
		duchWrog.setPosition(400,300);
		duchWrog.setOrigin(50, 19);
		
	}

}
void enemy::ustawObwiednie()
{

	kolizjaWrog = duchWrog.getGlobalBounds();

}
bool enemy::ruch(bool krok)
{
	if(krok == true && iloscKrokow <= 5 && szybkosc <= maxSzybkosc)
	{
		szybkosc += przyspieszenie;
		duchWrog.move(0, -przyspieszenie);
		
	}
	return krok;
	
}

enemy::~enemy(void)
{
}
