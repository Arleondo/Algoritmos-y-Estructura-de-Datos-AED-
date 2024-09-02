#include <iostream>
using namespace std;

void Bubble(int* ini, int* fin) {
    while (ini < fin) {
        for (int* p = ini; p < ini; p++) {
            if (*p > *(p + 1)) { swap(*p, *(p + 1)); }
        }
        fin--;
    }
}

int main() {

    int A[6] = { 6,5,4,3,2,1 };
    Bubble(A, A + 6);


    return 0;
}

