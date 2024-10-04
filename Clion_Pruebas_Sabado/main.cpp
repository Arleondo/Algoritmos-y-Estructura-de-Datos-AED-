#include <iostream>

using namespace std;

template <class T>
struct nodo {
    T** Array= new T * [5];
    nodo<T>* next;
    T** Fin= nullptr;
    nodo(nodo<T>* n = nullptr) {next = n;}
};

template <class T, class U>
struct LE {
    U op;
    nodo<T>* head = nullptr;
    nodo<T>* tail = nullptr;

    void add(T v);
    void del(T v);
    bool find(nodo<T>*& Node_pos ,T**& Array_pos, T v);
    void print();
};

template<class T, class U>
void LE<T, U>::print() {
    cout << "Head" << "->";
    for (nodo<T>* it = head; it; it = it->next) {
        cout << "[ ";
        for (T** it_2 = it->Array; it_2 != &it->Array[4] && it_2<=it->Fin ; ++it_2) {
            cout << **it_2 << " , ";
        }
        cout << " ]->";
    }
    cout << "nullptr " << endl;
}

template<class T, class U>
bool LE<T, U>::find(nodo<T>*& Node_pos ,T**& Array_pos, T v) {
    Node_pos = head;
    for (;Node_pos<=tail && Node_pos ;Node_pos = Node_pos->next) {
        for (Array_pos = Node_pos->Array; Array_pos<=Node_pos->Fin && !(op(v,**Array_pos)) ;Array_pos++) {
            if (op(v, **Array_pos) || **Array_pos == v) {
                return true;
            }
            if (Array_pos++){ continue;}
            else{break;}
        }
        if (Node_pos->next){ continue;}
        else {return false;}
    }
    return false;
}
template<class T, class U>
void LE<T, U>::del(T v) {
    nodo<T>* Nodo_actual = nullptr; T** Array_actual = nullptr;


    if (find(Nodo_actual, Array_actual, v) && **Array_actual == v) {
        T temp_dato= **(tail->Fin);
        delete *Array_actual; ++Array_actual;

        for (;Nodo_actual<=tail;Nodo_actual=Nodo_actual->next) {

            for (T ** Prev= Array_actual-- ;Array_actual<=Nodo_actual->Fin ; Array_actual++){
                swap (*Array_actual, *Prev);
            }

            if (Nodo_actual->Fin==Nodo_actual->Array+4) {
                if (Nodo_actual->next) {
                    Array_actual = Nodo_actual->next->Array;
                    swap(*(Nodo_actual->Fin),*Array_actual);
                }
            }

            if (Nodo_actual==tail) {
                if (Nodo_actual->Fin != Nodo_actual->Array) {
                    --(Nodo_actual->Fin); return;
                }
                if (find (Nodo_actual,Array_actual,temp_dato)) {
                    delete[] Nodo_actual->next; Nodo_actual->next = nullptr;
                    return;
                }
                delete [] head;
            }
        }
    }
}

template<class T, class U>
void LE<T, U>::add(T v) {
    T * Valor= new T;
    *Valor= v;
    if (head==nullptr) {
        head = new nodo<T>;
        head->Array[0] = Valor;
        tail = head;
        tail->Fin = head->Array;
        return;
    }

    nodo<T>* Nodo_actual = nullptr; T** Array_actual = nullptr;

    if (find (Nodo_actual, Array_actual, v) && **Array_actual == v) {return;}

    T* Temp_dato= *Array_actual;
    *Array_actual = Valor;
    if (Array_actual>Nodo_actual->Fin){
        Nodo_actual->Fin=Array_actual;
        return;}

    if (Array_actual < (Nodo_actual->Array)+4) {
        ++Array_actual;
    } else if (Nodo_actual->next) {
        Array_actual = Nodo_actual->next->Array; Nodo_actual=Nodo_actual->next;}
    else {
        Nodo_actual->next = new nodo<T>; tail= Nodo_actual->next;
        Array_actual = Nodo_actual->next->Array;
    }

    for (;Nodo_actual<=tail && Nodo_actual ;Nodo_actual=Nodo_actual->next) {

        for (;Array_actual<=Nodo_actual->Fin;Array_actual++) {
            swap(*Array_actual, Temp_dato);
        }


        if (Nodo_actual->Fin==Nodo_actual->Array+4) {
            if (Nodo_actual->next) {
                Array_actual = Nodo_actual->next->Array;
                continue;
            }
            Nodo_actual->next = new nodo<T>; tail= Nodo_actual->next;
            Array_actual = Nodo_actual->next->Array;
        }

    }
    T** Array_actual2 = nullptr;
    if (find (Nodo_actual,Array_actual2,v)) {
        swap(*Array_actual,Temp_dato);
        Nodo_actual->Fin=Array_actual;
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
    LE <int, Asc<int>> Lista;

    Lista.print();
    Lista.add(1);
    Lista.add(2);
    Lista.add(3);
    Lista.add(4);
    Lista.add(5);
    Lista.print();
    Lista.add(6);
    Lista.add(7);
    Lista.add(8);
    Lista.add(9);
    Lista.print();
    Lista.del(2);
    Lista.del(4);
    Lista.del(6);
    Lista.del(8);
    Lista.print();

}
