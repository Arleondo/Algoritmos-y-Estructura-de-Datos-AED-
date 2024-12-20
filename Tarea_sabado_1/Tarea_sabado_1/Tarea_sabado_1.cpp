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
    bool find(T v, nodo<T>*& pos);
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
bool LE<T, U>::find(T v, nodo<T>*& pos) {
    pos = head;
    for (nodo<T>* p = pos->next; p; p = p->next) {
        if (p) {
            if (op(v, p->valor) || v == p->valor) {
                return true;
            }
            pos = p;
        }
    }
    
    if (v == pos->valor) {
        return true;
    }

    return false;
}

template<class T, class U>
void LE<T, U>::del(T v) {

    nodo<T>* it = nullptr;
    if (find(v, it)) {
        
        if (it->next->valor != v) { return; }

        if (it->next->next) {
            if (it == head) {
                head = it->next;
                delete it;
                return;
            }
            auto* it_2 = it->next;
            it->next = it->next->next;
            delete it_2;
            return;
        }
        if (it == head) {
            head = it->next;
            delete it;
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
    
    if (head == nullptr) {
        head = AddNodo;
        return;
    }

    if (op(v, head->valor)) {
        AddNodo->next = head;
        head = AddNodo;
    }

    else {
        nodo<T>* it = nullptr;
        find(v, it);
        if (*it == v) { return; }
        AddNodo->next = it->next;
        it->next = AddNodo;
    }
}


template<class T>
class Asc {
public:
    bool operator()(T a, T b) {
        return a < b;
    }
};
#pragma once
template<class T>
class Desc {
public:
    bool operator()(T a, T b) {
        return a > b;
    }
};

int main() {
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
    Lista2.del('A');
    Lista2.del('K');
    Lista2.print();

}

