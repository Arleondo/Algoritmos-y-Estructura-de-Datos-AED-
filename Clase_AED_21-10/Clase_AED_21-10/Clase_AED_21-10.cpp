#pragma once
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void F1(char c, int n) {
	for (int i = 0; i < n; i++) {
		cout << c;
	}
}


void prueba1() {
	thread t(F1, 'c', 1000);

	thread y(F1, 'a', 1000);

	t.join();
	y.join();

	cout << "\n";
}


int main() {

	int nThreads = thread::hardware_concurrency();
	vector <thread> ths(nThreads);
	cout << nThreads << "\n";

	for (int i = 0; i < nThreads; i++) {ths[i] = thread(F1, char('a' + 1), 100);}

	for (int i = 0; i < nThreads; i++) {ths[i].join();}

}


