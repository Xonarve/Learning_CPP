// task9.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "golf.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	Golf g1("Peter Pit", 54);
	Golf g2("Victor Ez", 92);

	g1.showgolf();
	g2.showgolf();

	g1.setgolf();
	g1.showgolf();
	g2.setHandicap(888);
	g2.showgolf();

	Golf g[3] = {
		{ "heyf", 11 },
		{ "heys", 12 },
		{ "heyth", 13 }
	};
	for (int i = 0; i < 3; i++)
		g[i].showgolf();

	return 0;
}

