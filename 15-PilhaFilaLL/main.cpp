/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: flavio, paulo
 *
 * Created on January 26, 2021, 11:00 AM
 */

#include <iostream>
#include <stdlib.h>
//#include "pilha.h"
#include "fila.h"

using namespace std;

//tPilha * pilha1;
tFila * fila1;

/*
 * 
 */
int main() {
    no * p;
    
    //------------------------------PILHA---------------------------------------
    /*pilha1 = inicia_pilha();

    push(pilha1, 5);
    cout<<"push pilha 1: ";
    imprime(pilha1);

    push(pilha1, 10);
    cout<<"push pilha 2: ";
    imprime(pilha1);

    push(pilha1, 15);
    cout<<"push pilha 3: ";
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"pop pilha 1: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"pop pilha 2: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    push(pilha1, 12);
    cout<<"push pilha 4: ";
    imprime(pilha1);

    push(pilha1, 20);
    cout<<"push pilha 5: ";
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"pop pilha 3: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"pop pilha 4: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"pop pilha 5: "<< p->valor <<endl;
    delete (p);
    imprime(pilha1);

    p = pop(pilha1);
    cout<<"pop pilha 6: "<< endl;
    delete (p);
    imprime(pilha1);

    pilha1 = encerra_pilha(pilha1);*/
    
    //------------------------------FILA----------------------------------------
    fila1 = inicia_fila();
    
    push(fila1, 5);
    cout<<"push fila 1: ";
    imprime(fila1);

    push(fila1, 10);
    cout<<"push fila 2: ";
    imprime(fila1);

    push(fila1, 15);
    cout<<"push fila 3: ";
    imprime(fila1);
    
    p = pop(fila1);
    cout<<"pop fila 1: "<< p->valor <<endl;
    delete (p);
    imprime(fila1);
    
    p = pop(fila1);
    cout<<"pop fila 1: "<< p->valor <<endl;
    delete (p);
    imprime(fila1);
    
    fila1 = encerra_fila(fila1);

    return (EXIT_SUCCESS);
}
