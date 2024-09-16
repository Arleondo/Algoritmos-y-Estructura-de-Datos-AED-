// stack = pila;
// queue = Fila;

#pragma once

#include <iostream>

using namespace std;

template <class T, class Es>
class Stack {
protected:
	
	Es* Op;
	
public:
	
	Stack(): {};

	inline void pop() {
		Op.pop_back;
	};
	inline void push(T valor) {
		Op.push_back(valor);
	};
	inline T top(){
		return Op.back();
	}
	
};














template <class T>
class Svector {

public:
	Svector(T a) :Back(new T[a]), Bottom(Back[a-1]) {};


	void push(T a) {
		
	}
	void pop() {}
};


int main() {


	return;
}
