// El_insano_clase_1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
using namespace std;

int main(){
    
    int y = 7, x = 3;
    int ar[4] = { 3,7,2,4 };
    int* p;
    char* C;
    p = &x;
    *p = 5;
    p = &ar[2];
    *p = 8;
    p = &ar[0];
    *p = 6;
    p = ar;
    cout << *p;
    C = reinterpret_cast<char*>(p - 1);
    for (int v = 0; v < 20; v) {
        cout << C << endl;
        *C = 0;
        C++;
    }
    cout << *p;

}
