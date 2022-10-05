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
#include "lista.h"

using namespace std;

tLista * lista1;

/*
 * 
 */
int main() {
    no * p;
    lista1 = inicia_lista();

    cout<<"insere 4: "<<insere_enc(lista1, 4, 5)<<endl;
    imprime(lista1);

    cout<<"insere 2: "<<insere_enc(lista1, 2, 10)<<endl;
    imprime(lista1);

    cout<<"insere 5: "<<insere_enc(lista1, 5, 15)<<endl;
    imprime(lista1);

    cout<<"insere 3: "<<insere_enc(lista1, 3, 12)<<endl;
    imprime(lista1);

    cout<<"insere 1: "<<insere_enc(lista1, 1, 12)<<endl;
    imprime(lista1);

    cout<<"remove 3: "<< (p = remove_enc(lista1, 3))<<endl;
    delete (p);
    imprime(lista1);

    cout<<"remove 5: "<< (p = remove_enc(lista1, 5))<<endl;
    delete (p);
    imprime(lista1);

    cout<<"remove 1: "<< (p = remove_enc(lista1, 1))<<endl;
    delete (p);
    imprime(lista1);

    cout<<"remove 2: "<< (p = remove_enc(lista1, 2))<<endl;
    delete (p);
    imprime(lista1);

    cout<<"remove 4: "<< (p = remove_enc(lista1, 4))<<endl;
    delete (p);
    imprime(lista1);

    cout<<"remove 3: "<< (p = remove_enc(lista1, 3))<<endl;
    delete (p);
    imprime(lista1);

    lista1 = encerra_lista(lista1);

    return (EXIT_SUCCESS);
}
