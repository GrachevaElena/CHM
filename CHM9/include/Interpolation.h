struct Monom{
	double c;
	int deg;
	Monom *next;
	Monom(double c_ = 0, int deg_ = 0, Monom *next_ = 0){c = c_; deg = deg_; next = next_;}
};

class Polinom{
private:
	Monom *head;
public:
	Polinom();
	~Polinom();
	Polinom(const Polinom& P);
	void Delete();
	Polinom operator=(const Polinom& P);
	void Add(double c, int st);
	Polinom operator+(const Polinom& b);
	Polinom operator*(const Polinom& b);
	Polinom operator*(double k);
	Polinom Diff();
	double calc(double x);
	int size();
	//void Print();
};

Polinom Interpolation(int n, double* X, double* Y);