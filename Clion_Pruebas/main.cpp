// Clase_AED_31-08.cpp: define el punto de entrada de la aplicación.
// int A[6]={6,5,4,3,2,1}
// bubble (A,A+5,Asc())
// bubble (A,A+5,desc())
#pragma once

#include <iostream>
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
            cout << *p << endl;
        }
    }
};


int main()
{
    int A[6] = { 6,5,4,3,2,1};
    Bubble<int, Asc<int> > b;
    b(A, A + 5);
    int Y[6] = { 1,2,3,4,5,6 };
    Bubble<int,Desc<int> > X;
    
    imprime<int> p;
    p(A, A + 5);
    X(A, A + 5);
    p(A, A + 5);

    return 0;
}
