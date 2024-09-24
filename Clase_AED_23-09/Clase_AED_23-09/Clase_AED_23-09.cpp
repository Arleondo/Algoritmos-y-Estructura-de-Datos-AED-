#pragma once
#include <iostream>

using namespace std;

struct Nodo {
    int v;
    Nodo* next;
    explicit Nodo(int valor, Nodo* n = nullptr) :v(valor), next(n) {};
};

class LE {

    Nodo* head;

public:

    explicit LE(Nodo* cabeza = nullptr) :head(cabeza) {};
    ~LE() { delete[] head; }

    bool find(int x, Nodo**& p);
    void Ins(int x);
    void Rem(int x);

};

bool LE::find(int x, Nodo**& p) {
    for (p = &head; *p && (*p)->v < x; p = &((*p)->next)) {}
    return *p && (*p)->v == x;
}

void LE::Ins(int x) {
    Nodo** ptr = nullptr;
    if (!(find(x, ptr))) {
        Nodo* N_ins = new Nodo(x, *ptr);
        (*ptr) = N_ins;
    }
}

void LE::Rem(int x) {
    Nodo** ptr = nullptr;
    if ((find(x, ptr))) {
        Nodo* temp = *ptr;
        *ptr = (*ptr)->next;
        delete temp;
    }
}


int main() {
    LE lista;
    lista.Ins(1);
    lista.Ins(1);
    lista.Ins(5);
    lista.Ins(7);
    lista.Ins(8);
    lista.Rem(1);
    lista.Rem(8);

}
