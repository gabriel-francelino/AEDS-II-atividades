#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

void constroiHeap (int m, int v[]){
    int aux;
    for (int k = 1; k < m; ++k) {                   
        int f = k+1;
        while (f > 1 && v[f/2-1] < v[f-1]) {  
            aux = v[f/2-1];
            v[f/2-1] = v[f-1];
            v[f-1] = aux;
            f /= 2; //f = f / 2;                       
        }
        cout << endl << "ConstroiHeap k = " << k;
        for (int *p = v; p < v + m; p++){
            cout << "   " << *p;
        }
    }
}

void peneira (int m, int v[]) {
    int f = 2, aux;
    while (f <= m) {
        if (f < m && v[f-1] < v[f])
            ++f;
        if (v[f/2-1] >= v[f-1]) 
            break;
        aux = v[f/2-1];
        v[f/2-1] = v[f-1];
        v[f-1] = aux;
        f *= 2; // f = f * 2;
    }
    cout << endl << "Peneira m = " << m;
    for (int *p = v; p < v + m; p++){
        cout << "   " << *p;
    }
}

void HeapSort (int n, int v[]){
    int aux;
    constroiHeap (n, v);
    for (int m = n; m >= 2; --m) {
        aux = v[0];
        v[0] = v[m-1];
        v[m-1] = aux;
        peneira (m-1, v);
    }
}

int main(int argc, char** argv) {
    int v[] = {5, 1, 9, 0, 6, 8, 2, 4, 7, 3};
    int *p;
    
    int tamanho = 10;
    
    cout << "Heap Sort..." << endl;
    
    cout << "Estado Inicial" << endl;
    for (p = v; p < v + tamanho; p++){
        cout << "   " << *p;
    }
    
    //constroiHeap(10, v);
    HeapSort(tamanho, v);
    
    cout << endl << "Estado Final" << endl;
    for (p = v; p < v + tamanho; p++){
        cout << "   " << *p;
    }
    cout << endl;
    
    return 0;
}

