#include "Interpolation.h"
#include <cmath>

Polinom::Polinom() { head = 0; }

Polinom::~Polinom() {
	Delete();
}

Polinom::Polinom(const Polinom& P) {
	if (P.head) {
		Monom* tmp = P.head;
		head = new Monom(tmp->c, tmp->deg);
		Monom* NewM = head;
		tmp = tmp->next;
		while (tmp) {
			NewM->next = new Monom(tmp->c, tmp->deg);
			tmp = tmp->next;
			NewM = NewM->next;
		}
	}
	else head = 0;
}

Polinom Polinom::operator=(const Polinom& P) {
	if (&P != this) {
		Delete();
		if (P.head) {
			Monom* tmp = P.head;
			head = new Monom(tmp->c, tmp->deg);
			Monom* NewM = head;
			tmp = tmp->next;
			while (tmp) {
				NewM->next = new Monom(tmp->c, tmp->deg);
				tmp = tmp->next;
				NewM = NewM->next;
			}
		}
		else head = 0;
	}
	return (*this);
}

void Polinom::Delete() {
	Monom *tmp;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void Polinom::Add(double c, int deg) {	// ins st=3
	if (c) {
		if (head) {
			if (head->deg >= deg)
				if (head->deg == deg) {// 3-5-0
					head->c += c;
					if (head->c == 0) {// 3-5-0 -> 5-0
						Monom *del = head;
						head = head->next;
						delete del;
					}
				}
				else head = new Monom(c, deg, head);// 4-5-0 -> 3-4-5-0
			else {//1-2-...
				Monom *tmp = head;
				while (tmp->next && tmp->next->deg<deg) {
					tmp = tmp->next;
				}
				if (tmp->next && tmp->next->deg == deg) {// -2-3-4-
					tmp->next->c += c;
					if (tmp->next->c == 0) {// -2-3-4- -> -2-4-
						Monom *del = tmp->next;
						tmp->next = tmp->next->next;
						delete del;
					}
				}
				else tmp->next = new Monom(c, deg, tmp->next);// -2-4- -> -2-3-4- / -2-0 -> -2-3-0
			}
		}// 0 ->  3-0
		else head = new Monom(c, deg);
	}
}

Polinom Polinom::operator+(const Polinom& b) {// нерацинально
	Polinom res = (*this);
	Monom *tmp = b.head;
	while (tmp) {
		res.Add(tmp->c, tmp->deg);
		tmp = tmp->next;
	}
	return res;
}

Polinom Polinom::operator*(const Polinom& b) {
	Polinom res;
	if (head && b.head) {
		Monom *tmpA = head, *tmpB;
		while (tmpA) {
			Polinom mid;
			tmpB = b.head;
			while (tmpB) {
				mid.Add(tmpA->c * tmpB->c, tmpA->deg + tmpB->deg);
				tmpB = tmpB->next;
			}
			res = res + mid;
			tmpA = tmpA->next;
		}
	}
	return res;
}

Polinom Polinom::operator*(double k) {
	Polinom res = (*this);
	Monom *tmp = res.head;
	while (tmp) {
		tmp->c *= k;
		tmp = tmp->next;
	}
	return res;
}

/*void Polinom::Print(){
if(head){
Monom *tmp = head->next;
cout<< head->c;
if(head->deg) cout<< "*x^" << head->deg;
while(tmp){
if(tmp->c > 0) cout<<'+';
cout<< tmp->c << "*x^" << tmp->deg;
tmp = tmp->next;
}
cout<<'\n';
}
else cout<<'0'<<'\n';
}*/

Polinom Polinom::Diff() {
	Polinom res;
	if (head) {
		Monom *tmp = (head->deg) ? head : head->next;
		while (tmp) {
			res.Add(tmp->c * tmp->deg, tmp->deg - 1);
			tmp = tmp->next;
		}
	}
	return res;
}

double Polinom::calc(double x)
{
	double res = 0;
	if (head) {
		Monom *tmp = head;
		while (tmp) {
			res += tmp->c*pow(x, tmp->deg);
			tmp = tmp->next;
		}
	}
	return res;
}

int Polinom::size()
{
	int i = 0;
	if (head) {
		Monom *tmp = head;
		while (tmp) {
			tmp = tmp->next;
			i++;
		}
	}
	return i;
}

Polinom Interpolation(int n, double* X, double* Y)
{
	Polinom P;
	for (int i = 0; i<n; i++) {
		Polinom point;
		point.Add(1, 0);
		double c = 1;
		for (int j = 0; j<n; j++) {
			if (i != j) {
				c *= X[i] - X[j];
				Polinom tem;
				tem.Add(1, 1);
				tem.Add(-X[j], 0);
				point = point*tem;
			}
		}
		c = Y[i] / c;
		P = P + point*c;
	}
	return  P;
}

Polinom RightDifferenceOperator(int n, double* X, double* Y)
{
	Polinom res;
	if (n>1) {
		double* newY = new double[n - 1];
		for (int i = 0; i < n - 1; i++) {
			newY[i] = (Y[i + 1] - Y[i]) / (X[i + 1] - X[i]);
		}
		res = Interpolation(n - 1, X, newY);
	}
	return res;
}

Polinom LeftDifferenceOperator(int n, double* X, double* Y)
{
	Polinom res;
	if (n>1) {
		double* newY = new double[n - 1];
		for (int i = 0; i < n - 1; i++) {
			newY[i] = (Y[i + 1] - Y[i]) / (X[i + 1] - X[i]);
		}
		res = Interpolation(n - 1, (X + 1), newY);
	}
	return res;
}

Polinom CenteredDifferenceOperator(int n, double* X, double* Y)
{
	Polinom res;
	if (n>1) {
		double* newY = new double[n - 2];
		for (int i = 1; i < n - 1; i++) {
			newY[i] = (Y[i - 1] - 2 * Y[i] + Y[i + 1]) / (X[i + 1] - X[i]);
		}
		res = Interpolation(n - 2, (X + 1), newY);
	}
	return res;
}