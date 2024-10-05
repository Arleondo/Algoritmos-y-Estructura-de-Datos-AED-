#pragma once;
#include <iostream>

using namespace std;

template <class T>
struct nodo {
	T valor;
	nodo<T>* next;
	nodo(T v, nodo<T>* siguiente = nullptr) :valor(v), next(siguiente) {}
};


template <class T>
class pila {
	nodo<T>* Top = nullptr;
public:
	pila() {};

	void push(T valor) {
		nodo<T>* aux = Top;
		Top = new nodo<T>(valor, aux);
	};

	bool pop(T& valor) {

		if (Top != nullptr) {
			nodo<T>* aux = Top;
			Top = Top->next;
			delete aux;
			return true;
		}

		return false;
	};

	void print() {
		cout << "Top->";
		for (nodo<T>* print = Top; print != nullptr; print = print->next) {
			cout << print->valor << "->";
		}
		cout << "nullprt" << endl;
	};

};

int main() {
	int a = 1;
	pila <int> Pila_enteros;
	Pila_enteros.print();
	Pila_enteros.push(1);
	Pila_enteros.push(2);
	Pila_enteros.push(3);
	Pila_enteros.push(4);
	Pila_enteros.push(5);
	Pila_enteros.push(6);
	Pila_enteros.push(7);
	Pila_enteros.push(8);
	Pila_enteros.print();
	if (Pila_enteros.pop(a)) {}
	else {
		for (int uno = 0; uno < 5; uno++) {
			Pila_enteros.pop(a);
		}
	}
	Pila_enteros.print();
}
