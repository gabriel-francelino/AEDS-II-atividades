/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   arvores.h
 * Author: anaca
 *
 * Created on 5 de Abril de 2022, 21:06
 */

#ifndef ARVORES_H
#define ARVORES_H

using namespace std;

// Estrutura de nós da lista----------------------------------------------------
typedef struct no_ {
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int nPortas;
    string placa;
    struct no_* prox;
} no;

// Estrutura do "nó cabeça" da lista--------------------------------------------
typedef struct {
    int tam;
    struct no_ *lista;
} tLista;

// Estrutura da árvore binária--------------------------------------------------
typedef struct noArvore {
    no *end;
    struct noArvore *esquerda;
    struct noArvore *direita;
} noArvore;

// Estrutura da árvore AVL------------------------------------------------------
typedef struct noAVL {
    no *end;
    struct noAVL *esquerda;
    struct noAVL *direita;
    short altura;
} noAVL;

// Inicialização da lista--------------------------------------------------------

tLista* inicia_lista();
void encerra_lista(tLista *ptlista);

//funções de gerenciamento-------------------------------------------------------

bool busca_enc(tLista *ptlista, string placa, no **ant);
bool insere_enc(tLista *ptlista, string placa, no *veiculo);
bool remove_enc(tLista *ptlista, string placa);
void imprime(tLista *ptlista);

//-----------------------------------ÁRVORE BINÁRIA-----------------------------

noArvore *busca_arvore(noArvore *raiz, string placa);
noArvore *insere_arvore(noArvore *raiz, no **end);
void imprime_arvore(noArvore *raiz);
void imprime_preOrdem(noArvore *raiz);
void encerra_arvore(noArvore *raiz);

//FILA-------------------------------ÁRVORE AVL---------------------------------

short alturaNoAVL(noAVL *raiz);
short fatorAVL(noAVL *raiz);
short maior(short n, short m);
noAVL *rotacaoEsquerda(noAVL *raiz);
noAVL *rotacaoDireita(noAVL *raiz);
noAVL *rotacaoEsquerdaDireita(noAVL *raiz);
noAVL *rotacaoDireitaEsquerda(noAVL *raiz);
noAVL *balancearAVL(noAVL *raiz);
noAVL *insere_avl(noAVL *raiz, no **end);
void imprime_avl(noAVL *raiz);
void imprime_preOrdemAVL(noAVL *raiz);
void encerra_avl(noAVL *raiz);


#endif /* ARVORES_H */

