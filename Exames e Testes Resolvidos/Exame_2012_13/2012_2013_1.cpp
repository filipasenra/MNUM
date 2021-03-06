// 2012_2013_1.cpp
//

#include "pch.h"
#include <iostream>

using namespace std;

//dz = (m * dz/dt + k*x)/c
//z = dx/dt
//dx = z

const double m = 20, c = 1, k = 20;

double dx(double t, double x, double z) { return z; };
double dz(double t, double x, double z)
{
	return (-c*dx(t, x, z) - k * x) / m;
}

void euler(double t, double x, double z, double h)
{
	double tn, xn, zn;

	for (unsigned int n = 0; n < 10; n++)
	{
		tn = t;
		xn = x;
		zn = z;
		t += h;
		x += dx(tn, xn, zn)*h;
		z += dz(tn, xn, zn)*h;
		cout << n + 1 << " t " << t << " x " << x << " z " << z << endl;
	}
}

int main()
{
	euler(0, 1, 0, 0.1);
	return 0;
}
