#include <iostream>

using namespace std;

template <class T>
struct nodo{
    T valor;
    nodo<T> * next;
    nodo ( T v , nodo<T>* n = nullptr){
        valor=v;
        next=n;
    }
};

template <class T,class U>
struct LE{
    U op;
    nodo<T>* head = nullptr;

    void add(T v);
    void del(T v);
    bool find(T v, nodo<T>*& pos);
    void print();
};

template<class T, class U>
void LE<T, U>::print() {
    cout << "Head" << "->";
    for(nodo<T>* it=head; it ; it=it->next) {
        cout << it->valor << "->";
    }
    cout << "nullptr" << endl;
}

template<class T, class U>
bool LE<T, U>::find(T v, nodo<T> *& pos) {
    pos=head;
    for ( nodo<T>* p=pos ; p ; p=p->next ){
        if ( op(v, p->valor ) || v==pos->valor ){
            return true;
        }
        pos = p;
    }
    return false;
}

template<class T, class U>
void LE<T, U>::del(T v) {

    nodo<T>* it = nullptr;
    if (find(v, it)) {
        if (it == head) {
            head = it->next;
        }
        else {
            nodo<T>* it_2 = head;
            while (it_2 && it_2->next != it) {
                it_2 = it_2->next;
            }
            if (it_2) {
                it_2->next = it->next;
            }
        }
        delete it;
    }

}

template<class T, class U>
void LE<T, U>::add(T v) {

    auto* AddNodo = new nodo<T>(v);

    if (head == nullptr) {
        head = AddNodo;
        return;
    }

    if (op(v, head->valor)) {
        AddNodo->next = head;
        head = AddNodo;
    }
    else {
        nodo<T>* it = head;
        while (it->next && op(it->next->valor, v)) {
            it = it->next;
        }
        AddNodo->next = it->next;
        it->next = AddNodo;
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

    Lista.add(1);
    Lista.add(8);
    Lista.add(5);
    Lista.add(2);
    Lista.print();


    LE <char, Asc<char>> Lista2;

    Lista2.add('K');
    Lista2.add('B');
    Lista2.add('A');
    Lista2.add('J');
    Lista2.print();

}
