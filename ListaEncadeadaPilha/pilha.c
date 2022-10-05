/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: anaca
 *
 * Created on 3 de Fevereiro de 2022, 11:27
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no_ {
    int chave;
    int valor;

    struct no_ * prox;
} no;

no * topo;


void insere_pilha(int chave, int valor) {
    no * ptr = malloc(sizeof (no));
    ptr->chave = chave;
    ptr->valor = valor;
    ptr->prox = topo;
    topo = ptr;
    
}

no * remove_pilha(){
    no * retorno = NULL;
    if (topo != NULL) {
        retorno = topo;
        topo = topo->prox;
    }
    return retorno;
}

void imprime(){
    no * ptr = topo;
    printf("-----LISTA----\n");
    while(ptr!=NULL){   
        printf("chave: %d valor: %d \n", ptr->chave, ptr->valor);
        printf("--------------\n");
        ptr = ptr->prox;
    }
}

int main(int argc, char** argv) {
    
    insere_pilha(1,10);
    insere_pilha(5,12);
    insere_pilha(3,8);
    imprime();
    remove_pilha();
    //remove_pilha();
    imprime();
    
    return 0;
}

