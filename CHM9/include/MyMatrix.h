#pragma once
#include <iostream>
#include <vector>
class MyMatrix
{
	std::vector<double> data;
	int N;
	int M;
public:
	MyMatrix() {}
	MyMatrix(int _M, int _N) : data(_M*_N) {
		M = _M;
		N = _N;
		Initialize();
	}
	MyMatrix(const MyMatrix& m): data(m.M*m.N) {
		M = m.M;
		N = m.N;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				data[i*N + j] = m.data[i*N + j];
	}
	~MyMatrix() {}

	double& operator()(int i, int j) {
		return data[i*N + j];
	}

	friend std::ostream& operator<<(std::ostream& outs, MyMatrix& m) {
		for (int i = 0; i < m.M; i++) {
			for (int j = 0; j < m.N; j++)
				outs << m(i, j) << " ";
			outs << std::endl;
		}
		return outs;
	}

	void Initialize() {
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				data[i*N + j] = 0;
	}

	int GetM() { return M; }
	int GetN() { return N; }

	std::vector<double> operator*(std::vector<double>& v) {
		std::vector<double> res(N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				res[i] += data[i*N + j] * v[j];
		return res;
	}

	MyMatrix& operator=(const MyMatrix& matr) {
		if (&matr == this) return *this;
		if (M != matr.M || N != matr.N) return *this;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				(*this)(i, j) = matr.data[i*N+ j];
		return *this;
	}
};

