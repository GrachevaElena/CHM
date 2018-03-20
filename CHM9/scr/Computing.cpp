#include "Computing.h"
using namespace std;

double FindEps(MyMatrix& v, MyMatrix& v1) {
	double max=0;
	for (int i = 1; i < v.GetM()-1; i++)
		for (int j = 1; j < v.GetN()-1; j++)
			if (max < abs(v(i,j)-v1(i,j))) max = abs(v(i, j) - v1(i, j));
	return max;
}

double Abs(std::vector<double> & s) {
	double max = 0;
	for (int i = 0; i < s.size(); i++)
			if (max < abs(s[i])) max = abs(s[i]);
	return max;
}


//Zaidel's method
void Reference::ZaidelMethod(std::vector<double>& b)
{
	eps = 10000;
	int s = 0;
	while (eps > epsZaidel) {
		MyMatrix xs_1 = numericSolution;
		s++;

		for (int k = 0; k < Size; k++) {
			int i = GetIndexX(k);
			int j = GetIndexY(k);

			numericSolution(i, j) = b[k];
			for (int l = 0; l < k; l++)
				numericSolution(i, j).value -= GetA(k, l)*numericSolution(GetIndexX(l), GetIndexY(l)).value;
			for (int l = k + 1; l < Size; l++)
				numericSolution(i, j).value -= GetA(k, l)*numericSolution(GetIndexX(l), GetIndexY(l)).value;

			numericSolution(i, j).value /= GetA(k, k);
		}

		eps = FindEps(numericSolution, xs_1);

		//std::cout << std::endl << "s=" <<s<< std::endl;
		//std::cout << numericSolution << std::endl;

	}
}

void Reference::FindRs(std::vector<double> b)
{
    std::vector<double>s(Size);

	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++)
			s[i] += GetA(i, j)*numericSolution(GetIndexX(j), GetIndexY(j));
		s[i] -= b[i];
	}

	rs = Abs(s);
}

void Reference::FindGeneralError()
{
	generalError = FindEps(trueSolution, numericSolution);
}

void Reference::Compute(){
	vector<double> b = CreateB();
	ZaidelMethod(b);
	FindRs(b);
	FindGeneralError();
}

std::vector<double> Reference::CreateB()
{
	std::vector<double>b(Size);

    for (int i = 0; i < Size; i++)
        b[i] = -f(GetX(GetIndexX(i)), GetY(GetIndexY(i)));

    for (int j = 1; j <= 5; j++) {
        b[GetIndex(1, j)] += -1 / (h*h)*numericSolution(0, j);
        b[GetIndex(5, j)] += -1 / (h*h)*numericSolution(6, j);
    }

    for (int i = 1; i <= 5; i++) {
        b[GetIndex(i, 1)] += -1 / (k*k)*numericSolution(i, 0);
        b[GetIndex(i, 5)] += -1 / (k*k)*numericSolution(i, 6);
    }

    for (int i = 2; i <= 4; i++) {
        b[GetIndex(i, 1)] += -1 / (k*k)*numericSolution(i, 2);
        b[GetIndex(i, 5)] += -1 / (k*k)*numericSolution(i, 4);
    }

    for (int j = 2; j <= 4; j++) {
        b[GetIndex(1, j)] += -1 / (h*h)*numericSolution(2, j);
        b[GetIndex(5, j)] += -1 / (h*h)*numericSolution(4, j);
    }

	return b;

}


