/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   listas.h
 * Author: anaca
 *
 * Created on 3 de Março de 2022, 14:00
 */

#ifndef LISTAS_H
#define LISTAS_H

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
void busca(no * ptlista, int chave, no ** inicio, no ** pont);
int insere_fim(no * ptlista, int chave, int valor);
int insere_inicio(no * ptlista, int chave, int valor);
no * remove_inicio(no * ptlista);
no * remove_fim(no * ptlista);
void imprime(no * ptlista);

#endif /* LISTAS_H */

