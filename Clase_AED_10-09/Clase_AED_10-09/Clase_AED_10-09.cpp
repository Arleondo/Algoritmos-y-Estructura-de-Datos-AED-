#include <"Clase_AED_10-09.h">

using namespace std;

class CDeque {

    int tamVec;
    int tamMap;

    int** Map = new int* [tamMap];

    int** Map_Ini = Map + (tamVec/2);
    int** Map_fin  = Map + (tamVec/2);

    int* ini = nullptr;
    int* fin = nullptr;

public:

    CDeque(int a, int b) :tamVec(a), tamMap(b) {};

    void push_back(int num) {}
    void push_front(int num) {}
    void pop_back(int num) {}
    void pop_front(int num) {}
    int& operator[](int num) {}

};

void CDeque::push_back(int num) {

}

void CDeque::push_front(int num) {

}

void CDeque::pop_back(int num) {

}

void CDeque::pop_front(int num) {

}

int& CDeque::operator[](int num) {

}

int main() {

    float a = 2.5;
    cout << int(a) << endl;

}
