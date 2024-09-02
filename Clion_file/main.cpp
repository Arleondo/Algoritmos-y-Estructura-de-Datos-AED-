#include <iostream>
using namespace std;

class Sort {

    int* array;
    int array_length;

public:

    Sort(int* a, int x) : array(a), array_length(x) {};

    virtual bool comparator (int* r) = 0;

    void ordenamiento (){
        for (int x=array_length ; x>-1 ; x-- ){
            for (int j=0; j<=x ; j++){
                if (comparator(array)){
                    swap ( *array, *(array+1));
                }
            }
        }
    }
};

class Mayor_menor : public Sort {

public:
    
    bool comparator (int* r) override {
        return  *r < *(r + 1);
    }


};


int main() {
    int A[10]={5,7,4,3,1,6,8,9,10,2};

    Mayor_menor Arr(A,9);
    Sort * Lis = &Arr;




    return 0;
}
