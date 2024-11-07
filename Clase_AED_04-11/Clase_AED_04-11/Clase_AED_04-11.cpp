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
	~Node() { };
};

class Tree {
	Node* Root;
public:
	Tree(Node* raiz = nullptr) :Root(raiz) {};
	~Tree() { delete[]Root; };
	void Add(int v);
	void Del(int v);
	bool Find(Node**& Linea, int v);
	Node** Rep(Node** Linea);
	void Inorder(Node* n);
	void Preorder(Node* n);
	void Postorder(Node* n);
	void Print();
};

bool Tree::Find(Node**& Linea, int v) {
	// for (Linea = &Root; *Linea && (*Linea)->valor != v; Linea = &((*Linea)->nodos[(*Linea)->valor < v]));
	Linea = &Root;
	while (*Linea && (*Linea)->valor != v) {
		Linea = &((*Linea)->nodos[(*Linea)->valor < v]);
	}
	return *Linea != nullptr;
}

void Tree::Del(int v) {
	Node** p;
	if (!Find(p, v)) { return; }
	//caso2
	if ((*p)->nodos[0] && (*p)->nodos[1]) {
		Node** q = Rep(p);
		(*p)->valor = (*q)->valor;
		p = q;
	}
	//caso 1 y caso 0
	Node* temp = *p;
	*p = (*p)->nodos[(*p)->nodos[1] != nullptr];
	delete temp;
}

Node** Tree::Rep(Node** Linea) {
	Linea = &(*Linea)->nodos[0];
	for (; (*Linea)->nodos[1]; Linea = &(*Linea)->nodos[1]);
	return Linea;
}

void Tree::Add(int v) {
	Node** p;
	if (Find(p, v)) { return; }
	*p = new Node(v);
}

void Tree::Inorder(Node* n) {
	if (n) {
		Inorder(n->nodos[0]);
		cout <<"\t" << n->valor;
		Inorder(n->nodos[1]);
	} return;
}

void Tree::Preorder(Node* n) {
	if (n) {
		cout << n->valor;
		Inorder(n->nodos[0]);
		Inorder(n->nodos[1]);
	} return;
}

void Tree::Postorder(Node* n) {
	if (n) {
		Inorder(n->nodos[0]);
		Inorder(n->nodos[1]);
		cout << n->valor;
	} return;
}

void Tree::Print() {
	Inorder(Root);
}

int main() {
	Tree Arbol;
	Arbol.Add(1);
	Arbol.Add(2);
	Arbol.Add(3);
	Arbol.Add(4);
	Arbol.Add(5);
	Arbol.Add(6);
	Arbol.Add(7);
	Arbol.Add(8);
	Arbol.Add(9);
	Arbol.Add(10);
	Arbol.Add(11);
	Arbol.Add(12);
	Arbol.Add(13);
	Arbol.Add(14);
	Arbol.Add(15);

	Arbol.Del(15);
	Arbol.Del(1);
	Arbol.Del(6);


	Arbol.Print();

	return 0;
}

