#pragma once;
#include <iostream>
#include <vector>

using namespace std;

template <class T,class O>
class Heap {
    vector <T> heap(15);

    T max(){return heap[0];}
    
    void push(T x)
    
    
    T pop()
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



int main(){
    
    vector<int> prueba;

    cout << prueba.size() << "\n";

    cout << prueba.max_size() << "\n";

}
