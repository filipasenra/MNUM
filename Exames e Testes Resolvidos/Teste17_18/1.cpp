// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double dy(double x, double y, double z)
{
	return z;
}

double dz(double x, double y, double z)
{
	return 2 + x * x + x * z;
}

void rk4(double x0, double y0, double z0, double h)
{
	double xn, yn, zn;

	cout << 0 << " xn " << x0 << " yn " << y0 << " zn " << z0 << endl;

	for (unsigned int i = 0; i < 2; i++)
	{
		double a1 = h * dy(x0, y0, z0);
		double b1 = h * dz(x0, y0, z0);

		double a2 = h * dy(x0 + h * 0.5, y0 + a1 / 2, z0 + b1 / 2);
		double b2 = h * dz(x0 + h * 0.5, y0 + a1 / 2, z0 + b1 / 2);

		double a3 = h * dy(x0 + h * 0.5, y0 + a2 / 2, z0 + b2 / 2);
		double b3 = h * dz(x0 + h * 0.5, y0 + a2 / 2, z0 + b2 / 2);

		double a4 = h * dy(x0 + h, y0 + a3, z0 + b3);
		double b4 = h * dz(x0 + h, y0 + a3, z0 + b3);

		xn = x0 + h;
		yn = y0 + a1/6 + a2/3 + a3/3 + a4/6;
		zn = y0 + b1 / 6 + b2 / 3 + b3 / 3 + b4 / 6;

		x0 = xn;
		y0 = yn;
		z0 = zn;

		cout << i + 1 << " xn " << x0 << " yn " << y0 << " zn " << z0 << endl;
	}
}

void euler(double x0, double y0, double z0, double h)
{
	double xn, yn, zn;

	cout << 0 << " xn " << x0 << " yn " << y0 << " zn " << z0 << endl;

	for (unsigned int i = 0; i < 2; i++)
	{
		xn = x0 + h;
		yn = y0 + h * dy(x0, y0, z0);
		zn = z0 + h * dz(x0, y0, z0);

		x0 = xn;
		y0 = yn;
		z0 = zn;

		cout << i + 1 << " xn " << x0 << " yn " << y0 << " zn " << z0 << endl;
	}
}

int main()
{
	cout << fixed;
	cout.precision(6);

	cout << "Euler\n";

	euler(1, 1, 0, 0.25);

	cout << "RK4\n";

	rk4(1, 1, 0, 0.25);

}
