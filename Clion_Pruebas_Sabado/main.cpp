#include <iostream>

using namespace std;

template <class T>
struct nodo {
    T* Array= new T[5];
    nodo<T>* next;
    nodo(nodo<T>* n = nullptr) {
        next = n;
    }
};

template <class T, class U>
struct LE {
    U op;
    nodo<T>* head = nullptr;
    T* tail = nullptr;

    void add(T v);
    void del(T v);
    bool find(nodo<T>*& Node_pos ,T*& Array_pos, T v);
    void print();
};

template<class T, class U>
void LE<T, U>::print() {
    cout << "Head" << "->";
    for (nodo<T>* it = head; it; it = it->next) {
        for (T* it_2 = it->Array; it_2 != &it->Array[4] ; ++it_2) {
            cout << *it_2 << "->";
        }
    }
    cout << "nullptr " << endl;
}

template<class T, class U>
bool LE<T, U>::find(nodo<T>*& Node_pos ,T*& Array_pos, T v) {
    Node_pos = head;
    for (;Node_pos;Node_pos = Node_pos->next) {
        for (Array_pos = Node_pos->Array; Array_pos != &Node_pos->Array[4] && Array_pos++ ; Array_pos++) {
            if (op(v, *Array_pos) || v == *Array_pos) {
                return true;
            }
        }
    }
    return false;
}
template<class T, class U>
void LE<T, U>::del(T v) {
    nodo<T>* Nodo_actual = nullptr; T* Array_actual = nullptr;
    if (find(Nodo_actual, Array_actual, v)) {
        T temp_valor=*(Array_actual++);
        if (*Array_actual!= v){ return;}

        for (;Array_actual!=Array_actual; Array_actual++)
        delete Array_actual;
        swap(*Array_actual,*(Array_actual++));


    }




    if (find (Nodo_actual,Array_actual,*tail)){
        if (Nodo_actual->next){
            delete[] Nodo_actual->next;
            Nodo_actual->next = nullptr;
        }
    }
    if (tail==head->Array){
        tail= nullptr;
        delete[] head;
        head= nullptr;
    }
}

template<class T, class U>
void LE<T, U>::add(T v) {

    if (head==nullptr) {
        head = new nodo<T>;
        head->Array[0] = v;
        tail = head->Array;
        return;
    }

    nodo<T>* Nodo_actual = head; T* Array_actual = nullptr;
    find (Nodo_actual, Array_actual, v);

    if (*Array_actual == v) {return;}
    T Temp_dato=*Array_actual;

    if (tail==Array_actual){
        if (tail==Nodo_actual->Array+4) {
            Nodo_actual->next = new nodo<T>;
            tail=Nodo_actual->next->Array;
            *tail=*Array_actual;
            *Array_actual=Temp_dato;
            return;
        }
        *tail=v; tail++; *tail=Temp_dato;
        return;
    }

    *Array_actual = v;

    for (;Nodo_actual;Nodo_actual = Nodo_actual->next) {

        if (tail==Nodo_actual->Array+4) {
            Nodo_actual->next = new nodo<T>;
            tail=Nodo_actual->next->Array;
        }

        for (; Array_actual<Nodo_actual->Array+5  && Array_actual ;++Array_actual) {
            swap(Temp_dato, *Array_actual);
            if (Array_actual==Nodo_actual->Array+4){
                swap(Temp_dato,*(Nodo_actual->next->Array));
            }
        }
    }


}


template<class T>
class Asc {
public:
    bool operator()(T a, T b) {
        return a < b;
    }
};

template<class T>
class Desc {
public:
    bool operator()(T a, T b) {
        return a > b;
    }
};

int main() {
    LE <int, Desc<int>> Lista;

    Lista.add(1);
    Lista.add(8);
    Lista.add(5);
    Lista.add(2);
    Lista.print();
    Lista.del(1);
    Lista.del(5);
    Lista.print();

    LE <char, Asc<char>> Lista2;

    Lista2.add('K');
    Lista2.add('B');
    Lista2.add('A');
    Lista2.add('J');
    Lista2.print();
    Lista2.del('J');
    Lista2.del('K');
    Lista2.print();
}
