
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char**argv) {
    /* //USANDO ÍNDICES
    int m3[3][5];
    int m1[3][4]= {{5, 4, 6, 2},
                   {2, 8, 4, 4},
                   {3, 3, 1, 6}};
    int m2[4][5]= {{8, 6, 5, 7, 9},
                   {4, 3, 2, 5, 3},
                   {1, 8, 6, 4, 2},
                   {5, 2, 1, 4, 3}};
    int i, j, k;
    int somaProduto;
    
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
           somaProduto = 0;
           for(k=0; k<4; k++){
               somaProduto += m1[i][k] * m2[k][j];
               m3[i][j] = somaProduto;
           }
        }
    }
    
    //imprime
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            cout << "[" << m3[i][j] << "] ";
        }
        cout << endl;
    }
     */
    
    
    int m1[3][4]= {{5, 4, 6, 2},
                   {2, 8, 4, 4},
                   {3, 3, 1, 6}};
    int m2[4][5]= {{8, 6, 5, 7, 9},
                   {4, 3, 2, 5, 3},
                   {1, 8, 6, 4, 2},
                   {5, 2, 1, 4, 3}};
    int m3[3][5];
    
    int i, j, k;
    int *p1, *p2, *q1, *q2, *r;
    /*
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
           somaProduto = 0;
           for(k=0; k<4; k++){
               somaProduto += m1[i][k] * m2[k][j];
               m3[i][j] = somaProduto;
           }
        }
    }
    */
    r=&m3[0][0];
    for( p1=&m1[0][0]; p1<&m1[0][0]+12; p1+=4){
        for( q1=&m2[0][0]; q1<&m2[0][0]+5; q1++){
           *r = 0;
           for( p2=p1, q2=q1; p2<p1+4; p2++, q2+=5){
               *r += *p2 * *q2;  
           }
           r++;
        }
    }
    
    //imprime
    cout << "Produto das Matrizes: " << endl;
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            cout << "[" << m3[i][j] << "] ";
        }
        cout << endl;
    }
    
    for(r=&m3[0][0]; r<&m3[0][0]+15; r++){
        cout << *r << " ";
    }
    return 0;
}

