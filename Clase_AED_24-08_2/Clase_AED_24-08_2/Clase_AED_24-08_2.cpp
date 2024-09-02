#include <iostream>
using namespace std;

template<class T>
class Funtor {
    T _x;
public:
    Funtor(T x) : _x(x) {}

    T operator()(T a) const {
        return _x + a;
    }
};

template <class J>
void Tabla(J fu) {
    for (int x = 0; x < 10; x++) {
        cout << fu(x) << endl;
    }
}


int main() {

    Funtor<int> A(10);
    cout << A(5) << endl;
    cout << A(3) << endl;

    Tabla(A);

    return 0;
}
