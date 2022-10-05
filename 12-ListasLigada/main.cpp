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
#include "listas.h"

using namespace std;

no * lista1;

/*
 * 
 */
int main() {
    lista1 = inicia_lista();
    
    cout << "valor retornado: " << insere_fim(lista1, 2, 12) << endl;
    imprime(lista1);

    cout << "valor retornado: " << insere_fim(lista1, 8, 4) << endl;
    imprime(lista1);

    cout << "valor retornado: " << insere_fim(lista1, 3, 1) << endl;
    imprime(lista1);
    
    cout << "valor retornado: " << insere_inicio(lista1, 5, 1) << endl;
    imprime(lista1);
    
    cout << "valor retornado: " << insere_inicio(lista1, 5, 8) << endl;
    imprime(lista1);
    
    cout << "valor retornado: " << insere_inicio(lista1, 6, 1) << endl;
    imprime(lista1);
    
    cout << "valor retornado: " << remove_inicio(lista1) << endl;
    imprime(lista1);
    
    cout << "valor retornado: " << remove_fim(lista1) << endl;
    imprime(lista1);
    
    cout << "valor retornado: " << remove_fim(lista1) << endl;
    imprime(lista1);
    
    encerra_lista(lista1);

    return (EXIT_SUCCESS);
}
