#pragma once
#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo* next;
    explicit nodo(int v, nodo* n = nullptr) {
        valor = v;
        next = n;
    }
};

struct Lista_E {
    nodo* head = nullptr;

    void push_back(int v) {
        if (head == nullptr) {
            head = new nodo(v);
            return;
        }
        if (head->next == nullptr) {
            head->next = new nodo(v);
            return;
        }

        nodo* it = head;
        while (it) {
            if (it->next == nullptr) {
                it->next = new nodo(v);
                break;
            }
            it = it->next;
        }
    };

    void push_front(int v) {
        auto* Addnodo = new nodo(v);
        nodo* temp = head;
        head = Addnodo;
        Addnodo->next = temp;
    };

    void pop_back() const {
        nodo* it = head;
        while (it) {
            if (it->next->next == nullptr) {
                nodo* temp = it->next;
                it->next = nullptr;
                delete temp;
                break;
            }
            it = it->next;
        }
    };

    void pop_front() {
        nodo* Del = head;
        head = head->next;
        delete Del;
    };

    void print() const {
        cout << "Head" << "->";
        for (nodo* it = head; it; it = it->next) {
            cout << it->valor << "->";
        }
        cout << "nullptr " << endl;
    }

    int operator[](int v) const {
        nodo* it = head;
        for (int x = 0; x < v; it = it->next, x++) {}
        return it->valor;
    };

};




int main() {
    Lista_E lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_front(4);
    lista.print();
    lista.pop_back();
    lista.pop_front();
    lista.print();

    cout << lista[1];
}
