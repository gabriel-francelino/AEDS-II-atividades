/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>

#include "lista.h"

using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista* inicia_lista() {
	tLista* tmp = new (tLista);
	tmp->tam = 0;
	tmp->lista = NULL;

        cout << "-A lista foi iniciada."<<endl;
	return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista * encerra_lista(tLista * ptlista) {
	no * ant = ptlista->lista;
	no * pont = ptlista->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
        cout << "-A lista foi removida."<<endl;
	
        return NULL;
}

/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @return verdareiro se o elemento foi encontrado.
 */
bool busca_enc(tLista * ptlista, int chave,  no** ant) {
        *ant = ptlista->lista;
	no * ptr = ptlista->lista;
        
	while (ptr != NULL && ptr->chave < chave) {
            *ant = ptr;
            ptr = ptr->prox;
        }
	return ptr != NULL && ptr->chave == chave;
}

/**
 * Realiza a insercao na lista encadeada ordenada (sem repeticoes).
 * @param chave a ser inserida.
 * @param valor a ser inserido.
 * @return verdadeiro se o elemento foi inserido.
 */
bool insere_enc(tLista * ptlista, int chave, int valor){
	no* ant;

        if (ptlista->tam == 0){
            ptlista->lista = new(no);
            ptlista->lista->chave = chave;
            ptlista->lista->valor = valor;
            ptlista->lista->prox = NULL;
            ptlista->tam++;
            return true;
        }
        if(busca_enc(ptlista, chave, &ant))
            return false;
        
        no * ptr = new(no);
        ptr->chave = chave;
        ptr->valor = valor;
        ptlista->tam++;        
        if (ant->chave < chave){
            ptr->prox = ant->prox;
            ant->prox = ptr;
        } else {
            ptr->prox = ptlista->lista;
            ptlista->lista = ptr;
        }

        return true;
}

/**
 * Realiza a remocao do elemento passado caso o mesmo esteja na lista encadeada.
 * @param chave do elemento a ser removido.
 * @return nulo em caso de lista vazia ou elemento inexistente,
 * e o no removido caso contrario.
 */
no * remove_enc(tLista * ptlista, int chave){
	no* ant, *ptr;

	if(ptlista->tam == 0 || !busca_enc(ptlista, chave, &ant))
            return NULL;

        if (ant->chave == chave){
            ptlista->lista = ant->prox;
            ptr = ant;
        } else {
            ptr = ant->prox;
            ant->prox = ptr->prox;
        }
        ptr->prox = NULL;
	return ptr;
}

/**
 * Imprime a lista encadeada.
 */
void imprime(tLista * ptlista){
	no * ptr = ptlista->lista;
        cout << "---Estado atual da lista:";
	while(ptr != NULL){
            cout << "-> ("<<ptr->chave<<","<<ptr->valor<<") ";
            ptr = ptr->prox;
	}
        cout << endl;
}

