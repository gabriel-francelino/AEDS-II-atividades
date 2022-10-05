/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: paulo
 *
 * Created on January 26, 2021, 11:32 AM
 */

#ifndef LISTA_H
#define LISTA_H

typedef struct no_ {
	//critério de busca da ordenação
	int chave;

	//'carga útil' do nó
	//num cenario real, poderia ser, por exemplo: nome, endereco...
	int valor;

	struct no_ * prox;
} no;

no* inicia_lista();
void encerra_lista(no * ptlista);
void busca_enc(no * ptlista, int chave, no ** ant, no ** pont);
void busca_fim_enc(no * ptlista, int chave, no ** ant, no ** pont);
int insere_enc(no * ptlista, int chave, int valor);
int insere_fim_enc(no * ptlista, int chave, int valor);
int insere_inicio_enc(no * ptlista, int chave, int valor);
no * remove_enc(no * ptlista, int chave);
void imprime(no * ptlista);

#endif /* LISTA_H */

