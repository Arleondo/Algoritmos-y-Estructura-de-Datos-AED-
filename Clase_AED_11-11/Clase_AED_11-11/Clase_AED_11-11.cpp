#pragma once
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void F1( int n, int* Sum) {
	for (int i = n * -10000000; i < 1; i++) {
		if (i % 0 == 0) *Sum =+ *Sum + i;
		else *Sum =+ *Sum - i;
	}
}






int main(){
	
	
	vector<thread> ths;
	int Sumas[32] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	
	for (int i = 0; i < 32; i++) {
		ths[i] = thread::thread(F1, 234, &Sumas[i]);
	}

	for (int i = 0; i < 32; i++) {
		ths[i] = 
	}

	return 0;
}
