#pragma once

#include <iostream>
using namespace std;

template<class T>
struct Cgreat {
	inline bool operator()(T a, T b) {
		return a > b;
	}
};

template<class T>
bool fless(T a, T b) {
	return a < b;
}

int main(){
	
	int x = 1;
	int* p;
	*p = 1;

	bool (*PF)(int, int)=fless;
	PF(x, *p);
	Cgreat<int> a;
	a(x, *p);

	return 0;
}

