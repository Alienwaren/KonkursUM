#include "przeciwnik.h"
#include <ctime>
using namespace std;
przeciwnik::przeciwnik(void)
{
}
int przeciwnik::zadajObrazenia()
{
	srand(time(NULL));
	obr_bz = (rand() % 10) + 1;
	return obr_bz;
}
int przeciwnik::zaladuj()
{
	if(!grafikaPrzeciwnik.loadFromFile("snake.png"))
	{
		cout << "Nie moge zaladowac pliku przeciwnika" << endl;
		return EXIT_FAILURE;

	}else
	{
		grafikaPrzeciwnik.setSmooth(true);
		duchPrzeciwnik.setTexture(grafikaPrzeciwnik);

	}
	duchPrzeciwnik.move(56, 100);
}
przeciwnik::~przeciwnik(void)
{
}
