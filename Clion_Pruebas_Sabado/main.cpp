#pragma once

#include <iostream>

using namespace std;

template <class T>
struct nodo {
    T valor;
    nodo<T>* next;
    nodo(T v, nodo<T>* n = nullptr) {
        valor = v;
        next = n;
    }
};

template <class T, class U>
struct LE {
    U op;
    nodo<T>* head = nullptr;

    void add(T v);
    void del(T v);
    bool find(T v, nodo<T>**& pos);
    void print();
};

template<class T, class U>
void LE<T, U>::print() {
    cout << "Head" << "->";
    for (nodo<T>* it = head; it; it = it->next) {
        cout << it->valor << "->";
    }
    cout << "nullptr " << endl;
}

template<class T, class U>
bool LE<T, U>::find(T v, nodo<T>**& pos) {
    for (pos = &head; *pos && op((*pos)->valor,v) ; pos= &((*pos)->next) ){
        if ((*pos)->valor==v){return true; }} return false;
}

template<class T, class U>
void LE<T, U>::del(T v) {

    nodo<T>* it = nullptr;
    if (find(v, it)) {
        if (it->next->next) {
            auto* it_2 = it->next;
            it->next = it->next->next;
            delete it_2;
            return;
        }
        delete it->next;
        it->next = nullptr;
        return;
    }
}

template<class T, class U>
void LE<T, U>::add(T v) {
    auto* AddNodo = new nodo<T>(v);
    nodo<T>** it;
    if ( !find(v, it) ){
        auto* Ntemp= (*it)->next;
        (*it)->next=AddNodo;
        AddNodo->next=Ntemp;
    }
}


template<class T>
class Asc {
public:
    bool operator()(T a, T b) {
        return a < b;
    }
};

template<class T>
class Desc {
public:
    bool operator()(T a, T b) {
        return a > b;
    }
};


int main(){
    LE <int, Desc<int>> Lista;

    Lista.add(1);
    Lista.add(8);
    Lista.add(5);
    Lista.add(2);
    Lista.print();
    Lista.del(1);
    Lista.del(5);
    Lista.print();

    LE <char, Asc<char>> Lista2;

    Lista2.add('K');
    Lista2.add('B');
    Lista2.add('A');
    Lista2.add('J');
    Lista2.print();
    Lista2.del('J');
    Lista2.del('K');
    Lista2.print();
}
