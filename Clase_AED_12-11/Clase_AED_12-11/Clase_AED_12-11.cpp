#pragma once

#include <vector>
#include <iostream>

using namespace std;

struct Nodo_Spars {
	int valor;
	int coords[2] = {};
	Nodo_Spars* next[2] = {};
};

struct ObjectK {
	int x, y;
	Nodo_Spars* Pos;

public:

	ObjectK(int Cx, int Cy, Nodo_Spars* P = nullptr) :x(Cx), y(Cy), Pos(P) {};

	int operator = (int v) {
		
	}

};

class Sparse_Matrix {
	int Filas, Columnas;
	Nodo_Spars** EjeX, ** EjeY;

public:
	Sparse_Matrix(int F, int C) : Filas(F), Columnas(C) {
		EjeX = new Nodo_Spars * [Filas];
		EjeY = new Nodo_Spars * [Columnas];
		for (int i = 0; i < Filas; ++i) {EjeX[i] = nullptr;}
		for (int i = 0; i < Columnas; ++i) {EjeY[i] = nullptr;}
	}
	~Sparse_Matrix() {
		for (int i = 0; i < Filas; ++i) { delete EjeX[i]; }
		for (int i = 0; i < Columnas; ++i) { delete EjeY[i]; }
		delete[] EjeX;
		delete[] EjeY;
	}


	

	//Para acceder y asignar
	ObjectK operator() (int x, int y) { return Objectk(x,y,Nodo_Spars Posicion) }

};










int main(){


}
