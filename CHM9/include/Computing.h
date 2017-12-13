#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "MyMatrix.h"

typedef double(*Func)(double, double);

inline double f(double x, double y) {
	return 6 * x + 8 * y;
}

inline double true_solution(double x, double y) {
	return -(x*x*x+y*y*y+x*x*y);
}

class Reference {
public:
	std::string str_equat;
	std::string str_trueFunc;
	std::string str_nu1;
	std::string str_nu2;
	std::string str_nu3;
	std::string str_nu4;

	MyMatrix trueSolution;
	MyMatrix numericSolution;

	int m;
	int n;
	double ax, bx, ay, by;
	double h, k;

	double epsZaidel;

	double generalError=0;
	double eps = 0;
	double rs = 0;

	void Show(char f) {
		std::cout << std::endl;

		std::cout << "Исходное уравнение:" << std::endl;
		std::cout << str_equat << std::endl;
		std::cout << ax << "<=x<=" << bx << std::endl;
		std::cout << ay << "<=y<=" << by << std::endl;

		std::cout << "Граничные условия:" << std::endl;
		std::cout << "u(" << ax << ",y)=" << str_nu1 << std::endl;
		std::cout << "u(" << bx << ",y)=" << str_nu2 << std::endl;
		std::cout << "u(x," << ay << ")=" << str_nu3 << std::endl;
		std::cout << "u(x," << by << ")=" << str_nu4 << std::endl;

		std::cout << "Истинное решение:" << std::endl;
		std::cout << str_trueFunc << std::endl;

		std::cout << "Размерность сетки: " << n << "x" << m << std::endl;

		if (f == 'y') {
			std::cout << "Значения истинного решения в узлах сетки:" << std::endl;
			std::cout << trueSolution << std::endl;
			std::cout << "Значения полученного численого решения в узлах сетки:" << std::endl;
			std::cout << numericSolution << std::endl;
		}

		std::cout << "Общая погрешность схемы max|u(xi, yj)-v(xi, yj)|: " << generalError << std::endl;
		std::cout << "Параметр контроля погрешности при решении СЛАУ методом Зейделя: " << epsZaidel << std::endl;
		std::cout << "Итоговая точность при решении СЛАУ: " << eps << std::endl;
		std::cout << "Итоговая невязка: " << rs << std::endl;


	}

	Reference(int _n, int _m, double eps) : ax(0), bx(2), ay(0), by(1), m(_m), n(_n), 
		epsZaidel(eps), trueSolution(_n+1,_m+1), numericSolution(_n+1,_m+1) {
		//steps
		h = (bx - ax) / n;
		k = (by - ay) / m;

		//for cout
		str_equat = "d2u/dx2+d2u/dy2=-(6x+8y)";
		str_trueFunc = "u=-(x^3+y^3+x^2y)";
		str_nu1 = "-y^3";
		str_nu2 = "-(y^3+4y+8)";
		str_nu3 = "-x^3";
		str_nu4 = "-(x^3+x^2+1)";

		//border for numSol
		for (int j = 0; j <= m; j++) {
			numericSolution(0,j) = true_solution(GetX(0),GetY(j));
			numericSolution(n, j) = true_solution(GetX(n), GetY(j));
		}
		for (int i = 0; i <= n; i++) {
			numericSolution(i, 0) = true_solution(GetX(i), GetY(0));
			numericSolution(i, m) = true_solution(GetX(i), GetY(m));
		}

		//trueSol
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				trueSolution(i, j) = true_solution(GetX(i), GetY(j));
	}

	double GetX(int i) {
		return ax + h*i;
	}

	double GetY(int j) {
		return ay + k*j;
	}

	void Compute();

private:
	bool OneBlock(int i, int j) {
		return (i / (n - 1) == j / (n - 1));
	}

	std::vector<double> CreateB();

	double GetA(int i, int j) {
		if (i == j) return -2 * (1 / (k*k) + 1 / (h*h));
		if ((i + 1 == j || i - 1 == j) && OneBlock(i,j)) return 1 / (h*h);
		if (i + (n - 1) == j || i - (n - 1) == j) return 1 / (k*k);
		return 0;
	}
	//по двойному индексу одинарный
	int GetIndex(int i, int j) {
		return (j - 1)*(n - 1) + (i - 1);
	}
	//по одинарному индексу двойной
	int GetIndexX(int i) {
		return i % (n - 1) + 1;
	}
	int GetIndexY(int i) {
		return i / (n - 1) + 1;
	}

	void ZaidelMethod(std::vector<double>& b);

	void FindRs(std::vector<double> b);
	void FindGeneralError();
};

