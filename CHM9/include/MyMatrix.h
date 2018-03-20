#pragma once
#include <iostream>
#include <vector>

const int Size = 16;
const int arrIndexes[Size][2] = 
{ { 1,1 },{ 2,1 },{ 3,1 },{ 4,1 },{ 5,1 },
{ 1,2 },{ 5,2 },
{ 1,3 },{ 5,3 },
{ 1,4 },{ 5,4 },
{ 1,5 },{ 2,5 },{ 3,5 },{ 4,5 },{ 5,5 } };

struct Node {
    double value;
    bool isBorder;
    bool exists;
    int num;

    Node() {
        value = 0;
        isBorder = 0;
        exists = 1;
        num = -1;
    }

    Node(double _value) { value = _value; }

    operator double() {
        return value;
    }

    Node& operator=(double v) {
        value = v;
        return *this;
    }
    Node& operator+=(double v) {
        value += v;
        return *this;
    }
    Node& operator-=(double v) {
        value -= v;
        return *this;
    }
    Node& operator*=(double v) {
        value *= v;
        return *this;
    }
    Node& operator/=(double v) {
        value /= v;
        return *this;
    }

};

class MyMatrix
{
	std::vector<Node> data;
	const int N=7;
	const int M=7;
public:
	MyMatrix() : data(7*7) {
		Initialize();
	}
	MyMatrix(const MyMatrix& m): data(m.M*m.N) {
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				data[i*N + j] = m.data[i*N + j];
	}
	~MyMatrix() {}

	Node& operator()(int i, int j) {
		return data[i*N + j];
	}
    Node& operator()(int index) {
        return data[index];
    }


	void Initialize() {
        Node* tmp = 0;
        int ch = 0;
		for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                if (i == 3 && j == 3) {
                    data[i*N + j].exists = 0;
                    continue;
                }
                else data[i*N + j].exists = 1;

                data[i*N + j].value = 0;

                if (i == 0 || i == 6 || j == 0 || j == 6) data[i*N + j].isBorder = 1;
                else if (i == 1 || i == 5 || j == 1 || j == 5) {
                    data[i*N + j].isBorder = 0;
                    data[i*N + j].num = ch++;
                    
                }
                else data[i*N + j].isBorder = 1;
            }
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
				(*this).data[i*N+j] = matr.data[i*N+ j];
		return *this;
	}
};

