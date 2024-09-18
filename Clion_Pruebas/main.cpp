/*Vector
* Clist
* Cdeque
*/

class CDeque{
    int Tam_Mapa;
    const int Tam_Array;
    int ** Mapa = new int* [Tam_Mapa];
    int ** In_Mapa = Mapa + Tam_Mapa/2;
    int ** Fin_Mapa = In_Mapa;
    int * In_Arr = *In_Mapa + Tam_Array/2;
    int * Fin_Arr = In_Arr;
    int Num_Elementos=0;
    int Num_Arrays=1;

    inline void Expandir_M (); //Supone que ha colapsado ya sea por In o Fin
    void Colapsar_M (); //Se supone que lo expandido esta vació
    inline void Expandir_A (int**& Ptr_Mapa,int*& Ptr_Array); //Para belleza del code
    inline void Colapsar_A (int**& Ptr_Mapa,int*& Ptr_Array);

public:
    CDeque(const int Tam_Map, const int Tam_Arr):Tam_Mapa(Tam_Map),Tam_Array(Tam_Arr){*In_Mapa=new int [Tam_Array];};
    void push_front(int valor);
    void push_back(int valor);
    void pop_front();
    void pop_back();
    int& operator[](int valor);
    void print();
};

void CDeque::Expandir_M() {
    int old_TM = Tam_Mapa;
    Tam_Mapa=(Tam_Mapa*2)+1;
    //Nuevo mapa inicilizado y Copiado del antiguo
    int ** New_Mapa = new int* [Tam_Mapa];
    int ** Temp_In = New_Mapa + ((Tam_Mapa-Tam_Mapa/2)/2) ;
    for (int **Mapa_Copy = Mapa; Mapa_Copy<Mapa+old_TM ; Mapa_Copy++, Temp_In++) { Temp_In=Mapa_Copy; }
    //Reemplazo
    int ** Temp_Mapa = Mapa;
    Mapa = New_Mapa;
    delete Temp_Mapa;
}

void CDeque::Colapsar_M() {
    int Tam_Expansion= ((Tam_Mapa-Tam_Mapa/2)/2);
    Tam_Mapa=(Tam_Mapa-1)/2;
    int ** Colapse_Mapa = new int* [Tam_Mapa];
    int ** Temp_In = Colapse_Mapa;
    for (int **Mapa_Copy = Mapa + Tam_Expansion ; Mapa_Copy<= ((Mapa+(Tam_Mapa*2)+1)-1) - Tam_Expansion ; Mapa_Copy++,Temp_In++) {

    }
}

void CDeque::Expandir_A(int**& Ptr_Mapa,int*& Ptr_Array) {
    *Ptr_Mapa=new int [Tam_Array];
    Ptr_Array=*Ptr_Mapa;
}

void CDeque::Colapsar_A(int**& Ptr_Mapa,int*& Ptr_Array) {
    int *Temp = *Ptr_Mapa;
    Ptr_Array= *Ptr_Mapa;
    delete Temp;
}

void CDeque::push_front(const int valor) {
    if (In_Arr==Fin_Arr) {
        *In_Arr++=valor;
        Num_Elementos++;
    }
    else if(In_Arr==*In_Mapa && In_Arr!=*Mapa) {
        In_Mapa--;
        Expandir_A(In_Mapa,In_Arr);
        Num_Arrays++;
        In_Arr += Tam_Array-1;
        *In_Arr=valor;
        Num_Elementos++;
    }
    else if(In_Arr==*In_Mapa && In_Arr==*Mapa) {}

}

void CDeque::push_back(int valor) {

}

void CDeque::pop_front() {

}

void CDeque::pop_back() {

}




int &CDeque::operator[](int valor) {

}

void CDeque::print() {

}

int main() {
    return 0;
}
