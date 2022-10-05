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

no * lista1;

/*
 * 
 */
int main() {
	lista1 = inicia_lista();
        /*
	cout<<"valor retornado: "<<insere_enc(lista1, 1, 5)<<endl;
	imprime(lista1);
	
	cout<<"valor retornado: "<<insere_enc(lista1, 4, 10)<<endl;
	imprime(lista1);
	
	cout<<"valor retornado: "<<insere_enc(lista1, 3, 15)<<endl;
	imprime(lista1);
	
	cout<<"valor retornado: "<<insere_enc(lista1, 6, 24)<<endl;
	imprime(lista1);
        */
        cout<<"valor retornado: "<<insere_fim_enc(lista1, 2, 12)<<endl;
	imprime(lista1);
        
        //cout<<"valor retornado: "<<insere_enc(lista1, 5, 35)<<endl;
	//imprime(lista1);
	
	cout<<"valor retornado: "<<insere_fim_enc(lista1, 8, 4)<<endl;
	imprime(lista1);
        
        cout<<"valor retornado: "<<insere_fim_enc(lista1, 1, 1)<<endl;
	imprime(lista1);
        
        //cout<<"valor retornado: "<<remove_enc(lista1, 2)<<endl;
	//imprime(lista1);
	
	encerra_lista(lista1);
	
	return (EXIT_SUCCESS);
}
