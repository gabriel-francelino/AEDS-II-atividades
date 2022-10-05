#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

int separa (int v[], int p, int r) {
   int pivo = v[r]; // escolhe um pivô
   int temp, j = p;
   for (int k = p; k < r; ++k)
      if (v[k] <= pivo) {
         temp = v[j];
         v[j] = v[k];
         v[k] = temp;
         ++j; 
      } 
   v[r] = v[j];
   v[j] = pivo;
   return j; 
}

void QuickSort (int v[], int p, int r) {
    if (p < r) {                   
      int j = separa (v, p, r);   
      QuickSort (v, p, j-1);      
      QuickSort (v, j+1, r);      
    }
}

int main(int argc, char** argv) {
    int v[] = {5, 1, 9, 0, 6, 8, 2, 4, 7, 3};
    int *p;
    
    int tamanho = 10;
    
    cout << "Quick Sort..." << endl;
    
    cout << "Estado Inicial" << endl;
    for (p = v; p < v + tamanho; p++){
        cout << "   " << *p;
    }
    
    //cout << endl << " Posição do Pivô " << separa(v, 0, tamanho-1) << endl;
    QuickSort(v, 0, tamanho-1);
    
    cout << endl << "Estado Final" << endl;
    for (p = v; p < v + tamanho; p++){
        cout << "   " << *p;
    }
    cout << endl;
    
    return 0;
}

