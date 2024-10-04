#pragma once
#include <iostream>

using namespace std;

struct Node {
	int valor; // Node* nodo[2];
	Node* right; 
	Node* left;
	Node(int v, Node* sgte = nullptr, Node* ante = nullptr) {
		valor = v;
		right = sgte;
		left = ante;}
	~Node() { delete[]right; delete[]left; };
};

class Tree {
	int control = 1;
	Node* Root = nullptr;
public:
	Tree(Node* raiz) :Root(raiz) {};
	~Tree() { delete[]Root; };
	void Add(int v);
	void Del(int v);
	bool Find(Node** Linea, int v);
};

bool Tree::Find(Node** Linea, int v) {
	Linea = &Root;
	while (*Linea) {
		if ((*Linea)->valor == v) { return true; }
		
	}
	return false;
}

void Tree::Del(int v) {
	Node** p;
	
	//caso2
	if ((*p)->right && (*p)->left) {
		Node** q= &Root;
		if (control) {
			q = &((*q)->left);
			for (; (*q)->right ; {
				
			}
		}
		else {
			
		}
		p = q;
	}
	//caso 1 o tmb *p= (*p)->node[(*p)->node[1]!=0]
	Node* temp = *p;
	if ((*p)->right) { *p = (*p)->right; }
	else { *p = (*p)->left; }
	//caso 0
	delete temp;
}

void Tree::Add(int v) {
	Node* Nuevo = new Node();
}

int main(){
	
}
