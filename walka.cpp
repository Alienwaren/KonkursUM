#include "walka.h"

walka::walka(void)
{
	graczHP = 0;
	przeciwnikHP = 0;
	przerwa = seconds(5);
	rozpoczeta = false;
	komunikat = false;
	komunikat2 = false;
	zycieGracz = true;
	zycieWrog = true;
	
}
bool walka::rozpocznijWalke(bool kolizja)
{
	if(kolizja == true)
	{
		rozpoczeta = true;
	
	}else
	{
		rozpoczeta = false;

	}
	return rozpoczeta;
}
float walka::walcz(float walczacyHP, float walczacyObr, float broniacyHP, float broniacyObr)
{
	if(walczacyHP <= 0)
	{
		zycieGracz = false;
		return zycieGracz, walczacyHP, broniacyHP, zycieWrog;
	}
	if(broniacyHP <= 0)
	{
		zycieWrog = false;
		return zycieGracz, walczacyHP, broniacyHP, zycieWrog;
	}
	walczacyHP = walczacyHP - broniacyObr;
	broniacyHP = broniacyHP - walczacyObr;
	cout << walczacyHP << " " << broniacyHP << endl;
	graczHP = walczacyHP;
	przeciwnikHP = broniacyHP;
	
	if(przeciwnikHP <= 0 && komunikat == false) // wyswietlenie komunikatu o stanie graczy
	{
		cout << "Przeciwnik nie zyje" << endl;
		komunikat = true;
	}
	if(graczHP <= 0 && komunikat2 == false)
	{
		cout << "Gracz nie zyje" << endl;
		komunikat2 = true;
	}
	przerwa += seconds(1);
	return graczHP, przeciwnikHP;
}
walka::~walka(void)
{
}
