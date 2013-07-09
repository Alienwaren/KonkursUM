#pragma once
#ifndef _H_JEDNOSTKA_
#define _H_JEDNOSTKA_
class jednostka
{
public:
	jednostka(void);
	~jednostka(void);
	Vector2f pozycja_x;
	int zasiegWzroku;
	int ustawZasieg();
};

#endif _H_JEDNOSTKA_