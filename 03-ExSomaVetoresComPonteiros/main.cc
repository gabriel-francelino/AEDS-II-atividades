
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a[] = {1,2,3,4};
int b[] = {5,6,7,8};
int c[4];

int *p, *q, *r;

int main(int argc, char**argv) {
    // Prints welcome message...
    cout << " Aritmética de Ponteiros... " << endl; 
    
    cout << endl << " c =";
    for(p=a , q=b, r=c; p < a+4; p++, q++, r++){
        *r = *p + *q;
        cout << " [" << *r << "] ";
    }
    
    cout << endl;
    
    return 0;
}
