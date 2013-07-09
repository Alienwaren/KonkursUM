#pragma once
#include "postaæ.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#ifndef _H_PRZECIWNIK_
#define _H_PRZECIWNIK_
class przeciwnik 
{
public:
	przeciwnik(void);
	int zadajObrazenia();
	~przeciwnik(void);
	int zaladuj();
	int obr_bz;
	Sprite duchPrzeciwnik;
protected:
	Texture grafikaPrzeciwnik; // NAPISAC KOLEJNE KLASY WROGA
};

#endif //PRZECIWNIK