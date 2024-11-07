#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex m ;
int sum = 0;


void F1(char c, int n) {
    for (int i = 0; i < n; i++) {
        cout << c;
    }
}


void F2(int x, int n) {
    
    for (int i = 0; i < n; i++) {
        m.lock();
        sum += (x);
        m.unlock();
    }
}

void F3(int *arr,int n, int* s) {
    
}





int main() {

    int i = 0, Nthreads = thread::hardware_concurrency();
    vector<thread> ths(Nthreads);

    for (i = 0; i < Nthreads; i++) ths[i] = thread(F1, char('a' + i), 100);

    for (i = 0; i < Nthreads; i++) ths[i].join();

    cout << "\n";

}


