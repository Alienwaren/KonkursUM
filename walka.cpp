#include "walka.h"

walka::walka(void)
{
	wystapila = false;
	graczHP = 0;
	przeciwnikHP = 0;
	srand(time(NULL));
}
float walka::walcz(float walczacyHP, float walczacyObr, float broniacyHP, float broniacyObr)
{
	walczacyHP = walczacyHP - broniacyObr;
	broniacyHP = broniacyHP - walczacyObr;
	cout << walczacyHP << " " << broniacyHP << endl;
	wystapila = true;
	graczHP = walczacyHP;
	przeciwnikHP = broniacyHP;
	return walczacyHP, broniacyHP;
}
walka::~walka(void)
{
}
