#include <iostream>

using namespace std;

template <class T>
struct nodo{

    T valor;
    nodo<T> * next;
    nodo (T v, nodo<T>* n = nullptr){
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

}

template<class T, class U>
bool LE<T, U>::find(T v, nodo<T> *& pos) {
    pos=head;
    for ( nodo<T> p=pos ; p ; p->next ){
        if ( op(v, p->valor ) || v==pos->valor ){
            return true;
        }
        pos = p;
    }
    return false;
}

template<class T, class U>
void LE<T, U>::del(T v) {


}

template<class T, class U>
void LE<T, U>::add(T v) {
    nodo<T>* AddNodo(v);
    if (head == nullptr ){
        head->next = AddNodo;
    }
    for (nodo<T>* it=head; it ; it->next){
        if (fint (v,it)){
            nodo<T>* TempNodo;
            TempNodo->next = it;
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




/*Tipo = T
 * V= funtor
 * Asc o Desc
 * HEAD->1->2->5->8->null
 * HEAD->A->B->J->K->null
 */

int main() {


}
