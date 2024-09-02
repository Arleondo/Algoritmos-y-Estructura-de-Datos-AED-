#include <iostream>


using namespace std;

template <class T, int N=10>
class Arr {
	T A[N];
};


template <class T>
class Nodo {


public:
	
	T dato;
	nodo <T>* next;

};

template<class T>
class Lista_E {
	
public:

	T * Head;

};


int main()
{
	Arr<int> Waza;
	Arr<string, 20> Wazaa;
	Lista_E<Nodo<int>> Lista;

	return 0;
}

