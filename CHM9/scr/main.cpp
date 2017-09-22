#include "schet.h"
#include <iostream>

using namespace std;

void main()
{
	double x = 1;
	double y = 1;
	double h = 0.01;

	cout << "Euler\n(x,y) = (" << x << ';' << y << ")\n";
	for (int i = 0; i<10; i++)
	{
		y = Euler(f, h, x, y);
		x += h;
		cout << i << ": " << x << ' ' << y << '\n';
	}

	x = 1;
	y = 1;
	cout << "RK2\n(x,y) = (" << x << ';' << y << ")\n";
	for (int i = 0; i<10; i++)
	{
		y = RK2(f, h, x, y);
		x += h;
		cout << i << ": " << x << ' ' << y << '\n';
	}

	x = 1;
	y = 1;
	double e;
	cout << "DoubleCount\n(x,y) = (" << x << ';' << y << ")\n";
	for (int i = 0; i<10; i++)
	{
		y = DoubleCount(f, h, x, y, e);
		x += h;
		cout << i << ": " << x << ' ' << y << ' ' << h << ' ' << e << '\n';
	}
	char c;
	cin >> c;
}