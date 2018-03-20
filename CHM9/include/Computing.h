#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include "MyMatrix.h"

typedef double(*Func)(double, double);

inline double f(double x, double y) {
    return -4;
}

inline double True_solution(double x, double y) {
    return (1 - x)*(1 - x) + (1 - y)*(1 - y) + 5;
}

class Reference {
public:


	std::string str_equat;
	std::string str_trueFunc;
	std::string str_nu1;
	std::string str_nu2;
	std::string str_nu3;
	std::string str_nu4;
    std::string str_nu5;
    std::string str_nu6;
    std::string str_nu7;
    std::string str_nu8;

	MyMatrix trueSolution;
	MyMatrix numericSolution;

	int m;
	int n;
	double ax, bx, ay, by, a1x, b1x, a1y, b1y;
	double h, k;

	double epsZaidel;

	double generalError=0;
	double eps = 0;
	double rs = 0;

    void ShowArea() {
        std::cout << " _ _ _ _ _ _" << std::endl;
        std::cout << "|_|_|_|_|_|_|" << std::endl;
        std::cout << "|_|_|_|_|_|_|" << std::endl;
        std::cout << "|_|_|   |_|_|" << std::endl;
        std::cout << "|_|_|_ _|_|_|" << std::endl;
        std::cout << "|_|_|_|_|_|_|" << std::endl;
        std::cout << "|_|_|_|_|_|_|" << std::endl;
    }

	void Show(char f) {
		std::cout << std::endl;

		std::cout << "Исходное уравнение:" << std::endl;
		std::cout << str_equat << std::endl;
		std::cout << ax << "<=x<=" << bx << std::endl;
		std::cout << ay << "<=y<=" << by << std::endl;

		std::cout << "Граничные условия:" << std::endl;
        std::cout << "u(" << ax << ",y)=" << str_nu1 << ", " << ay << "<=y<=" << by << std::endl;
		std::cout << "u(" << bx << ",y)=" << str_nu2 << ", " << ay << "<=y<=" << by << std::endl;
		std::cout << "u(x," << ay << ")=" << str_nu3 << ", " << ax << "<=x<=" << bx << std::endl;
		std::cout << "u(x," << by << ")=" << str_nu4 << ", " << ax << "<=x<=" << bx << std::endl;
        std::cout << "u(" << a1x << ",y)=" << str_nu5 << ", " << a1y << "<=y<=" << b1y << std::endl;
        std::cout << "u(" << b1x << ",y)=" << str_nu6 << ", " << a1y << "<=y<=" << b1y << std::endl;
        std::cout << "u(x," << a1y << ")=" << str_nu7 << ", " << a1x << "<=x<=" << b1x << std::endl;
        std::cout << "u(x," << b1y << ")=" << str_nu8 << ", " << a1x << "<=x<=" << b1x << std::endl;

		std::cout << "Истинное решение:" << std::endl;
		std::cout << str_trueFunc << std::endl;

		std::cout << "Размерность сетки: " << n << "x" << m << std::endl;
        std::cout << "Исходная область: " << std::endl;
        ShowArea();
        std::cout << std::endl;

        if (f == 'y') {
            std::cout << "Значения истинного решения в узлах сетки:" << std::endl;
            PrintMatrix(trueSolution);
            std::cout << "Значения полученного численого решения в узлах сетки:" << std::endl;
            PrintMatrix(numericSolution);
        }

		std::cout << "Общая погрешность схемы max|u(xi, yj)-v(xi, yj)|: " << generalError << std::endl;
		std::cout << "Параметр контроля погрешности при решении СЛАУ методом Зейделя: " << epsZaidel << std::endl;
		std::cout << "Итоговая точность при решении СЛАУ: " << eps << std::endl;
		std::cout << "Итоговая невязка: " << rs << std::endl;


	}

	Reference(double eps) : ax(0), bx(6), ay(0), by(6), a1x(2), b1x(4), a1y(2), b1y(4), m(6), n(6), 
		epsZaidel(eps), trueSolution(), numericSolution() {

		//steps
		h = (bx - ax) / n;
		k = (by - ay) / m;

		//for cout
		str_equat = "d2u/dx2+d2u/dy2=4";
		str_trueFunc = "u=(1-x)^2+(1-y)^2+5";
		str_nu1 = "(1-y)^2+5";
		str_nu2 = "(1-y)^2+30";
		str_nu3 = "(1-x)^2+5";
		str_nu4 = "(1-x)^2+30";
        str_nu5 = "(1-y)^2+6";
        str_nu6 = "(1-y)^2+14";
        str_nu7 = "(1-x)^2+6";
        str_nu8 = "(1-x)^2+14";

		//border for numSol
		for (int j = 0; j <= 6; j++) {
            numericSolution(0, j) = True_solution(GetX(0), GetY(j));
			numericSolution(6, j) = True_solution(GetX(6), GetY(j));
		}
		for (int i = 0; i <= 6; i++) {
			numericSolution(i, 0) = True_solution(GetX(i), GetY(0));
			numericSolution(i, 6) = True_solution(GetX(i), GetY(6));
		}
        for (int j = 2; j <= 4; j++) {
            numericSolution(2, j) = True_solution(GetX(2), GetY(j));
            numericSolution(4, j) = True_solution(GetX(4), GetY(j));
        }
        for (int i = 2; i <= 4; i++) {
            numericSolution(i, 2) = True_solution(GetX(i), GetY(2));
            numericSolution(i, 4) = True_solution(GetX(i), GetY(4));
        }

		//trueSol
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				trueSolution(i, j) = True_solution(GetX(i), GetY(j));
	}

	double GetX(int i) {
		return ax + h*i;
	}

	double GetY(int j) {
		return ay + k*j;
	}

	void Compute();

public:
	std::vector<double> CreateB();

	double GetA(int i, int j) {

        if (i == j) return -2 / (h*h) - 2 / (k*k);
        int ix = GetIndexX(i), iy = GetIndexY(i);
        int jx = GetIndexX(j), jy = GetIndexY(j);
        if (numericSolution(jx, jy).isBorder) return 0;
        if (iy - jy == 0 && (ix - jx == 1 || ix - jx == -1)) return 1 / (h*h);
        if (ix - jx == 0 && (iy - jy == 1 || iy - jy == -1)) return 1 / (k*k);
		return 0;
	}
	//по двойному индексу одинарный
	int GetIndex(int i, int j) {
        return numericSolution(i,j).num;
	}
	//по одинарному индексу двойной
	int GetIndexX(int i) {
        return arrIndexes[i][0];
	}
	int GetIndexY(int i) {
        return arrIndexes[i][1];
	}

	void ZaidelMethod(std::vector<double>& b);

	void FindRs(std::vector<double> b);
	void FindGeneralError();

    void PrintMatrix(MyMatrix matrix) {
        std::cout.setf(std::ios::fixed);
        std::cout<<std::endl;
        for (int i = 0; i <= 6; i++) {
            for (int j = 0; j <= 6; j++) {
                if (i == 3 && j == 3) std::cout << "        " << "  ";
                else std::cout << std::setprecision(5) << (matrix(i, j)+0.0000000002) << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout.unsetf(std::ios::fixed);
    }
};

