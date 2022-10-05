/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: flavio
 *
 * Created on 17 de Dezembro de 2020, 11:42
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no_ {
    //criterio de busca
    //ordenacao
    int chave;

    //'carga util' do no
    //num cenario real, poderia
    //ser por exemplo, nome, endereco...
    int valor;

    struct no_ * prox;
} no;

no * ptlista;

/**
 * Realiza a alocacao do espaco
 * para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
no* inicia_lista() {
    no* tmp = malloc(sizeof (no));
    tmp->chave = 0;
    tmp->valor = 0;
    tmp->prox = NULL;

    return tmp;
}

/**
 * Desaloca o espaco previamente 
 * alocado para a lista encadeada.
 */
void encerra_lista() {
    no * ant = ptlista->prox;
    no * pont = ant->prox;

    while (pont != NULL) {
        free(ant);
        ant = pont;
        pont = pont->prox;
    }
    free(ant);

    free(ptlista);
}

/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @param pont ponteiro que aponta a posicao encontrada.
 */
void busca_enc(int chave, no ** ant, no ** pont) {
    *ant = ptlista;
    *pont = NULL;

    no * ptr = ptlista->prox;
    while (ptr != NULL) {
        if (ptr->chave < chave) {
            *ant = ptr;
            ptr = ptr->prox;
        } else {
            if (ptr->chave == chave) {
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

/**
 * Realiza a insercao na lista encadeada ordenada (sem repeticoes).
 * @param chave a ser inserida.
 * @param valor a ser inserido.
 * @return -1 em caso de falha, 0 em caso de sucesso.
 */
int insere_enc(int chave, int valor) {
    int retorno = -1;
    no* ant;
    no* pont;

    busca_enc(chave, &ant, &pont);

    if (pont == NULL) {
        no * ptr = malloc(sizeof (no));
        ptr->chave = chave;
        ptr->valor = valor;
        ptr->prox = ant->prox;
        ant->prox = ptr;
        retorno = 0;
    }

    return retorno;
}

/**
 * Realiza a remocao do elemento passado caso o mesmo esteja na lista encadeada.
 * @param chave do elemento a ser removido.
 * @return nulo em caso de lista vazia ou elemento inexistente,
 * e o no removido caso contrario.
 */
no * remove_enc(int chave) {
    /*TODO*/
    no * ant;
    no * pont;
    
    busca_enc(chave, &ant, &pont);
    
    if(pont != NULL){
        ant->prox = pont->prox;
        return pont;
    }

    return NULL;
}

/**
 * Imprime a lista encadeada.
 */
void imprime() {
    no * ptr = ptlista->prox;
    while (ptr != NULL) {
        printf("(chave, valor): (%d, %d)\n", ptr->chave, ptr->valor);
        ptr = ptr->prox;
    }
    printf("---------\n");
}

/*
 * 
 */
int main() {
    ptlista = inicia_lista();

    printf("valor retornado: %d\n", insere_enc(1, 5));
    imprime();

    printf("valor retornado: %d\n", insere_enc(2, 10));
    imprime();

    printf("valor retornado: %d\n", insere_enc(3, 15));
    imprime();

    printf("valor retornado: %d\n", insere_enc(2, 10));
    imprime();
    
    printf("valor retornado: %p \n", remove_enc(2));
    imprime();

    encerra_lista(ptlista);

    return (EXIT_SUCCESS);
}
