/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: anaca
 *
 * Created on 4 de Fevereiro de 2022, 10:52
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no_ {
    int chave;
    int valor;
    
    struct no_ * prox;
}no;

no * inicio;
no * fim;

void insere_fila(int chave, int valor){
    no * ptr = malloc(sizeof(no));
    ptr->chave = chave;
    ptr->valor = valor;
    
    if(fim != NULL){
        fim->prox = ptr;
    }else{
        inicio = ptr;
        //fim = ptr;
    }
    fim = ptr;
    //free(ptr);
}

no * remove_fila(){
    no * retorno = NULL;
    
    if(inicio != NULL){
        retorno = inicio;
        inicio = inicio->prox;
    }else{
        fim = NULL;
    }
    
    return retorno;
}

void imprime(){
    no * ptr = inicio;
    printf("-----LISTA----\n");
    while(ptr != NULL){
        printf("chave: %d valor: %d \n", ptr->chave, ptr->valor);
        printf("--------------\n");
        
        if(ptr->chave == fim->chave){
            ptr->prox = NULL;
        }
        
        ptr = ptr->prox;
    }
    //free(ptr);
}

int main(int argc, char** argv) {
    
    insere_fila(1,10);
    insere_fila(5,12);
    insere_fila(6,8);
    imprime();
    remove_fila();
    //remove_fila();
    imprime();
    
    return 0;
}

