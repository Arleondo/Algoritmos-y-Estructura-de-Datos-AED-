#include <iostream>
using namespace std;

template<class T>
struct Nodo {
    int Tam;
    T* Array;
    Nodo<T>* Next;
    Nodo() {Tam = 0; Array = new T[5]; Next = nullptr;}
};

template<class T>
class List_array {

    Nodo<T>* Head;

    bool find(Nodo<T>**& nodo_pos, int& Elementos, T Valor) {

        for (nodo_pos = &Head; *nodo_pos;) {
            if (*((*nodo_pos)->Array + (*nodo_pos)->Tam - 1) < Valor && (*nodo_pos)->Tam == 5) {
                nodo_pos = &((*nodo_pos)->Next);}
            else {
                Elementos = 0;
                for (T* Arraypos = (*nodo_pos)->Array; Arraypos < (*nodo_pos)->Array + (*nodo_pos)->Tam; Arraypos++, Elementos++) {
                    if (*Arraypos > Valor) {
                        return false;
                    }
                    else if (*Arraypos == Valor) {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
public:
    List_array() {Head = nullptr;}

    void Add(T Valor) {
        Nodo<T>** Nodo_pos = nullptr;
        int Posicion = 0;

        if (find(Nodo_pos, Posicion, Valor)) {
            return;
        }

        while (true) {
            if (!(*Nodo_pos)) {
                (*Nodo_pos) = new Nodo<T>;
                *((*Nodo_pos)->Array) = Valor;
                (*Nodo_pos)->Tam += 1;
                return;
            }

            T Temp;

            for (T* Arr_pos = ((*Nodo_pos)->Array + Posicion); Arr_pos < (*Nodo_pos)->Array + (*Nodo_pos)->Tam; Arr_pos++) {
                Temp = *Arr_pos; *Arr_pos = Valor; Valor = Temp;
            }

            (*Nodo_pos)->Tam += 1;

            if ((*Nodo_pos)->Tam < 6) {
                *((*Nodo_pos)->Array + (*Nodo_pos)->Tam - 1) = Valor;
                return;}

            else {
                (*Nodo_pos)->Tam = 5;
                Posicion = 0;
                Nodo_pos = &((*Nodo_pos)->Next);}

        }

    }

    bool Del(T Valor){
        Nodo<T>** Nodo_act = nullptr;
        int Pos_Arr = 0;

        if (!(find(Nodo_act, Pos_Arr, Valor))) {
            return false;
        }

        while (*Nodo_act) {

            if ((*Nodo_act)->Tam == 1) {
                ((*Nodo_act)->Array) = NULL;
                delete (*Nodo_act)->Next;
                return true;
            }
            *((*Nodo_act)->Array + Pos_Arr) = NULL;

            T* Pos_act = ((*Nodo_act)->Array + Pos_Arr);
            for (; Pos_act < ((*Nodo_act)->Array + (*Nodo_act)->Tam); Pos_act++) {
                T temporal = *(Pos_act + 1);
                *Pos_act = temporal;
            }
            Pos_act--;
            if ((*Nodo_act)->Tam == 5 && (*Nodo_act)->Next) {
                T temp = *((*Nodo_act)->Next->Array);
                *Pos_act = temp;
            } else if(!(*Nodo_act)->Next){
                (*Nodo_act)->Tam--;
                return true;
            }
            Nodo_act = &((*Nodo_act)->Next);
            Pos_act=(*Nodo_act)->Array;
            Pos_Arr = 0;
        }
    }

    void print(){
        cout << "Head->";
        for (auto *Nodo_p=Head;Nodo_p;Nodo_p=Nodo_p->Next){
            cout << "[ ";
            for (T*Elemento=Nodo_p->Array; Elemento < Nodo_p->Array+Nodo_p->Tam ;Elemento++){
                cout <<*Elemento<<" ";
            }
            cout << "]->";
        }
        cout << "nullptr" << endl;
    }

};



int main(){
    List_array<int> Waza;
    Waza.Add(1);
    Waza.Add(2);
    Waza.Add(3);
    Waza.Add(4);
    Waza.Add(5);
    Waza.print();
    Waza.Add(6);
    Waza.Add(7);
    Waza.Add(8);
    Waza.print();
    Waza.Del(3);
    Waza.print();
}