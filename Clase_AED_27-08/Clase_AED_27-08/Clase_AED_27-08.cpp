#pragma once
#include <iostream>

using namespace std;

bool mayor_menor(int* ar, int x) {
	if (x == 0) {
		return *ar < *(ar + 1);
	}
	if (x == 1) {
		return *ar > *(ar + 1);
	}
}

class Sort {

	int* array;
	int array_length;

public:

	Sort(int* a, int x) : array(a), array_length(x) {};

	virtual bool cmp(int* r) = 0;
	
	

};

class Mayor_menor : public Sort {

public:

	bool cmp (int* r) override {
		return *r < *(r + 1);
	}


};


int main(){








	return 0;
}
