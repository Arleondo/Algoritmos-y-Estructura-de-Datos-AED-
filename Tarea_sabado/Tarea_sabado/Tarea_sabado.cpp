#pragma once

#include <iostream>
using namespace std;

template<class T, class O>
class Bubble {
	O op;
public:

	void operator() (T* ini, T* fin) {
		bool sigue = true;
		while ((ini < fin) && sigue) {
			sigue = false;
			for (T* p = ini; p < fin; p++) {
				if (op(*p, *(p + 1))) {
					swap(*p, *(p + 1));
					sigue = true;
				}
			}
			fin--;
		}
	}
};

template<class T>
class Asc {
public:
	bool operator()(T a, T b) {
		return a > b;
	}
};

template<class T>
class Desc {
public:
	bool operator()(T a, T b) {
		return a < b;
	}
};

template<class T>
class imprime {
public:
	void operator() (T* ini, T* fin) {
		for (T* p = ini; p <= fin; p++) {
			cout << *p << " ";
		}
		cout << endl;
	}
};


int main()
{
	int A[6] = { 3,5,2,3,6,1 };
	
	Bubble<int, Asc<int> > b;
	b(A, A + 5);

	float Y[6] = { 5,2,6,4,1,3 };
	Bubble<float, Desc<float> > X;

	imprime<int> p_int;
	imprime<float> p_Float;
	
	p_int(A, A + 5);
	X(Y, Y + 5);
	p_Float(Y , Y+5);
	
	return 0;
}
