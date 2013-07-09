#include "walka.h"
#include "postaæ.h"
#include "enemy.h"

walka::walka(void)
{
	wystapila = false;
}
void walka::walcz()
{
	cout << "WALKA!" << endl;
	wystapila = true;
}

walka::~walka(void)
{
}
