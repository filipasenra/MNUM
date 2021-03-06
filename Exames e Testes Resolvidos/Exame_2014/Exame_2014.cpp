// Exame_2014.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double dT(double T)
{
	return -0.25*(T - 37);
}

void euler(double t, double T, double h)
{
	for (unsigned int n = 0; n < 2; n++)
	{
		T += h * dT(T);
		t += h;
		cout << n + 1 << " t " << t << " T " << T << endl;
	}
}

int main()
{
	euler(5, 3, 0.4);
	return 0;
}