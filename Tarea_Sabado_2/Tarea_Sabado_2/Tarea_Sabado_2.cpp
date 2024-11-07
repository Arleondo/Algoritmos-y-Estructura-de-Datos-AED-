#pragma once;
#include <iostream>

const int tamaño = 5;

template <class T>
struct Node {
    T Array[tamaño]; 
    Node<T>* next;
    int numeros;
    Node(Node<T>* n = nullptr) : next(n), numeros(0) {}
};

template <class T, class O>
struct CList {
    Node<T>* head = nullptr;
    int pos = 0;
    O comp;

    CList() {};

    void push(T v);
    void pop(T v);
    void order();
    void print();

};

template <class T, class O>
void CList<T, O>::push(T v) {
    if (!head) {
        head = new Node<T>();}

    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;}

    if (temp->numeros < tamaño) {
        temp->Array[temp->numeros++] = v;}
    
    else {
        temp->next = new Node<T>();
        temp->next->Array[temp->next->numeros++] = v;}

    pos++;
    order();
}

template <class T, class O>
void CList<T, O>::pop(T v) {
    if (!head) {return;}

    Node<T>* temp = head;
    Node<T>* prev = nullptr;

    while (temp) {
        for (int i = 0; i < temp->numeros; ++i) {
            if (temp->Array[i] == v) {
                for (int j = i; j < temp->numeros - 1; ++j) {
                    temp->Array[j] = temp->Array[j + 1];}
                temp->numeros--;
                pos--;

                if (temp->numeros == 0) {
                    if (prev) {
                        prev->next = temp->next;
                        delete temp;
                    }
                    else {
                        delete head;
                        head = nullptr;
                    }
                }
                return;}}
        prev = temp;
        temp = temp->next; 
    }
}

template <class T, class O>
void CList<T, O>::order() {
    if (!head) { return };
    bool swapped;
    do {
        swapped = false;
        Node<T>* temp = head;

        while (temp) {
            for (int i = 0; i < temp->numeros - 1; ++i) {
                if (comp(temp->Array[i], temp->Array[i + 1])) {
                    std::swap(temp->Array[i], temp->Array[i + 1]);
                    swapped = true;
                }
            }
            temp = temp->next;
        }
        
        temp = head;
        while (temp && temp->next) {
            if (comp(temp->Array[temp->numeros - 1], temp->next->Array[0])) {
                std::swap(temp->Array[temp->numeros - 1], temp->next->Array[0]);
                swapped = true;
            }
            temp = temp->next;
        }

    } while (swapped);
}

template <class T, class O>
void CList<T, O>::print() {
    Node<T>* temp = head;
    cout << "Head->";
    while (temp) {
        cout << "[ ";
        for (int i = 0; i < temp->numeros; ++i) {
            cout << temp->Array[i] << " , ";
        }
        cout << "]-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
    cout << "N° Nodos: " << pos << endl;
}


template <class T>
struct asc {
    bool operator() (T a, T b) {
        return a > b;}};

template <class T>
struct desc {
    bool operator() (T a, T b) {
        return a < b;}};

int main() {
    
    CList<int, asc<int>> LE;
    LE.push(1);
    LE.push(2);
    LE.push(3);
    LE.push(4);
    LE.push(5);
    LE.print();
    LE.push(6);
    LE.push(7);
    LE.push(8);
    LE.push(9);
    LE.print();

    return 1;
}
