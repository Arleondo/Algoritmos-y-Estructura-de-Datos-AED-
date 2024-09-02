// Clase_AED_31-08.cpp: define el punto de entrada de la aplicación.
// int A[6]={6,5,4,3,2,1}
// bubble (A,A+5,Asc())
// bubble (A,A+5,desc())
#pragma once
#define Ascen(a,b) (a>b)
#include <iostream><
using namespace std;

template<class T,class O>
class Bubble {
    O op;
public:

    void operator() (T* ini, T* fin) {
        bool sigue = true;
        while ((ini < fin) && sigue) {
            sigue = false;
            for (T* p = ini; p<fin ; p++) {
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
    void operator()(T* ini, T* fin) {
        for (T* p = ini ; p <= fin; p++) {
            cout << *p << "\t";
        }
        cout << endl;
    }
};


int main()
{
    int A[6] = { 6,5,4,3,2,1};
    Bubble<int, Asc<int> > b;
    b(A, A + 5);
    float Y[6] = { 1,2,3,4,5,6 };
    Bubble<float,Desc<float> > X;

    imprime<int> p;
    imprime<float> p1;
    p(A, A + 5);
    X(Y, Y + 5);
    p1(Y, Y + 5);

    return 0;
}
