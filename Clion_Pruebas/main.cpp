#pragma once
#include <iostream>

using namespace std;

class CDeque {

    int tam;
    int** Map = new int* [tam];

    int** Map_Ini = Map[tam/2];
    int** Map_fin = Map[tam/2];

    int* ini = *Map_Ini[2];
    int* fin = *Map_fin[2];

public:

    CDeque(int a,int b){
        tam=a;

    };

    void push_back(int num) {}
    void push_front(int num) {}
    void pop_back(int num) {}
    void pop_front(int num) {}
    int& operator[](int num){}

};




int main() {

    float a = 2.5;
    cout << int(a) << endl;

}
