#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	const int size = 100;
	int a[size][size], b[size][size], c[size][size];
	int sum = 0;
	int m, n, k;
	cin >> m >> n >> k;
	//ввод матриц двумя сопсобами
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			c[i][j] = 0;
			for (int l = 0; l < n; ++l)
			{
				c[i][j] = a[i][j] * b[i][j];
			}
		}
	}
}
/////////////////////////////////////////////
double integral(double (*func)(double),  double a, double b, double ebs) //только для передачи парметра *func(double)
{
	double k = 1.0;
	if (a == b)
	{
		return 0.0;
	}
	else
	{
		if (a > b)
		{
			swap(a, b);
			k = -1.0;
		}
	}
	int n = 1;
	double h = (b - a) / n;
	double pribl2 = h * ((func(a) + func(b))*0.5);
	double pribl1 = 0.0;
	do
	{
		pribl1 = pribl2;
		n *= 2;
		for (int i = 1; i < n; ++i)
		{
			pribl2 += func(a - h * i);
			pribl2 = h * (((func(a)) + func(b))*0.5 + pribl2);
		}
		while (abs(pribl2 - pribl1) > ebs); 
		return (pribl2*k);
	}
}
////////////////////
double square_x(double x)
{
	return (x*x);
}
double sinus_func(double x)
{
	return (sin(x)*sin(x));
}
//summa
double y = integral(square_x, 5.0, 1.0, 0.00001) + integral(sinus_func, 1.5, 0.0, 0.00001) + (cos, 3.14, 0.5, 0.00001);
