#pragma once
#include <iostream>

using namespace std;

struct Node {
	int valor; // Node* nodo[2];
	Node* nodos[2];
	Node(int v, Node* sgte = nullptr, Node* ante = nullptr) {
		valor = v;
		nodos[0] = ante;
		nodos[1] = sgte;
	}
	~Node() { delete[]nodos; };
};

class Tree {
	Node* Root = nullptr;
public:
	Tree(Node* raiz) :Root(raiz) {};
	~Tree() { delete[]Root; };
	void Add(int v);
	void Del(int v);
	bool Find(Node**& Linea, int v);
};

bool Tree::Find(Node**& Linea, int v) {
	// for (Linea = &Root; *Linea && (*Linea)->valor != v; Linea = &((*Linea)->nodos[(*Linea)->valor < v]));
	Linea = &Root;
	while (*Linea && (*Linea)->valor!= v) {
		Linea = &( (*Linea)->nodos[(*Linea)->valor < v] );}
	return *Linea!=nullptr;
}

void Tree::Del(int v) {
	Node** p;
	if (!Find(p, v)) { return; }
	//caso2
	if ((*p)->nodos [0] && (*p)->nodos[1] ) {
		Node** q = Rep(p,v);
		(*p)->valor = (*q)->valor;
		p = q;}
	//caso 1 y caso 0
	Node* temp = *p;
	*p = (*p)->nodos[(*p)->nodos[1] != nullptr];
	delete temp;
}

void Tree::Add(int v) {
	Node** p;
	if (Find(p, v)) { return; }
	*p = new Node(v);
}

Node** Rep(Node** Linea,int v) {
	
}

int main() {

}
