/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paulo
 *
 * Created on August 27, 2019, 2:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

void intercala1 (int p, int q, int r, int v[]) {
   int *w = new int[r-p];
   int i = p, j = q;                    
   int k = 0;                           
   while (i < q && j < r) {             
      if (v[i] <= v[j])
          w[k++] = v[i++];  
      else 
          w[k++] = v[j++];               
   }                                       
   while (i < q) 
       w[k++] = v[i++];         
   while (j < r)
       w[k++] = v[j++];         
   for (i = p; i < r; ++i)
       v[i] = w[i-p]; 
   delete [] w;
}

void intercala2 (int p, int q, int r, int v[]){
   int i, j;
   int *w = new int[r-p];

   for (i = p; i < q; ++i)
       w[i-p] = v[i];
   for (j = q; j < r; ++j)
       w[r-p+q-j-1] = v[j];
   i = 0; 
   j = r-p-1;
   for (int k = p; k < r; ++k)
      if (w[i] <= w[j]) 
          v[k] = w[i++];
      else 
          v[k] = w[j--];
   delete [] w;
}

void MergeSort (int p, int r, int v[]){
    if (p < r-1) {                 
        int q = (p + r)/2;          
        MergeSort (p, q, v);        
        MergeSort (q, r, v);        
        intercala1 (p, q, r, v);     
    }
}

int main(int argc, char** argv) {
    int v[] = {5, 1, 9, 0, 6, 8, 2, 4, 7, 3};
    int z[] = {0, 1, 5, 9, 2, 3, 4, 6, 7, 8};
    int tamanho = 10;
    int *p;
    
    cout << "Merge Sort ..." << endl;
    
    cout << "Estado Inicial" << endl;
    for (p = z; p < z + tamanho; p++){
        cout << "   " << *p;
    }
    
    intercala1(0, 4, tamanho, z);
    //MergeSort(0, tamanho, v);
    
    cout << endl << "Estado Final" << endl;
    for (p = z; p < z + tamanho; p++){
        cout << "   " << *p;
    }
    cout << endl;
    
    return 0;
}

