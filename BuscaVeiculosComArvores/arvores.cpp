#include <iostream>
#include <string.h>

#include "arvores.h"

using namespace std;

//------------------------------------------------------------------------

/**
 * @brief Inicializa a lista principal.
 * 
 * @return tLista* 
 */
tLista* inicia_lista() {
    tLista* tmp = new(tLista);
    tmp->tam = 0;
    tmp->lista = NULL;
    return tmp;
}

/**
 * @brief Realiza a liberação dos nós da lista principal.
 * 
 * @param ptlista Lista principal.
 */
void encerra_lista(tLista *ptlista) {
    no *ant = ptlista->lista;
    no *pont = ptlista->lista;
    while (ant != NULL) {
        pont = ant->prox;
        delete(ant);
        ant = pont;
    }
    delete(ptlista);
}
// Inserção e remoção da lista ordenada-----------------------------------------

/**
 * @brief Realiza a busca pelo nó e ordena a lista.
 * 
 * @param ptlista Lista principal.
 * @param placa Chave para busca a ser realizada.
 * @param ant Ponteiro que contém o endereço do último nó da lista.
 * @return true 
 * @return false 
 */
bool busca_enc(tLista *ptlista, string placa, no **ant) {
    *ant = ptlista->lista;
    no *ptr = ptlista->lista;
    while (ptr != NULL && ptr->placa != placa) {
        *ant = ptr;
        ptr = ptr->prox;
    }
    return ptr != NULL && ptr->placa == placa;
}

/**
 * @brief Realiza a inserção de um nó na lista de maneira ordenada.
 * 
 * @param ptlista Lista principal.
 * @param placa Chave para o nó a ser inserido.
 * @param veiculo Ponteiro que contém o endereço do nó a ser inserido.
 * @return true 
 * @return false 
 */
bool insere_enc(tLista *ptlista, string placa, no *veiculo) {
    no* ant;
    if (ptlista->tam == 0) {
        ptlista->lista = new(no);
        ptlista->lista->modelo = veiculo->modelo;
        ptlista->lista->marca = veiculo->marca;
        ptlista->lista->tipo = veiculo->tipo;
        ptlista->lista->ano = veiculo->ano;
        ptlista->lista->km = veiculo->km;
        ptlista->lista->potencia = veiculo->potencia;
        ptlista->lista->combustivel = veiculo->combustivel;
        ptlista->lista->cambio = veiculo->cambio;
        ptlista->lista->direcao = veiculo->direcao;
        ptlista->lista->cor = veiculo->cor;
        ptlista->lista->nPortas = veiculo->nPortas;
        ptlista->lista->placa = veiculo->placa;
        ptlista->lista->prox = NULL;
        ptlista->tam++;
        return true;
    }
    if (busca_enc(ptlista, placa, &ant))
        return false;
    no * ptr = new(no);
    ptr->modelo = veiculo->modelo;
    ptr->marca = veiculo->marca;
    ptr->tipo = veiculo->tipo;
    ptr->ano = veiculo->ano;
    ptr->km = veiculo->km;
    ptr->potencia = veiculo->potencia;
    ptr->combustivel = veiculo->combustivel;
    ptr->cambio = veiculo->cambio;
    ptr->direcao = veiculo->direcao;
    ptr->cor = veiculo->cor;
    ptr->nPortas = veiculo->nPortas;
    ptr->placa = veiculo->placa;
    ptlista->tam++;
    ptr->prox = ant->prox;
    ant->prox = ptr;
    return true;
}

/**
 * @brief Realiza a remoção de um nó na lista principal.
 * 
 * @param ptlista Lista principal.
 * @param placa Chave para o nó a ser removido.
 * @return true 
 * @return false 
 */
bool remove_enc(tLista *ptlista, string placa) {
    no* ant, *ptr;
    if (ptlista->tam == 0 || !busca_enc(ptlista, placa, &ant))
        return false;
    if (ant->placa == placa) {
        ptlista->lista = ant->prox;
        ptr = ant;
    } else {
        ptr = ant->prox;
        ant->prox = ptr->prox;
    }
    ptr->prox = NULL;
    return true;
}

/**
 * @brief Imprime os nós a lista principal.
 * 
 * @param ptlista Lista principal.
 */
void imprime(tLista *ptlista) {
    no *ptr = ptlista->lista;
    cout << "+-------------------------------------------+" << endl;
    while (ptr != NULL) {
        cout << "  Modelo: " << ptr->modelo << endl;
        cout << "  Marca: " << ptr->marca << endl;
        cout << "  Tipo: " << ptr->tipo << endl;
        cout << "  Ano: " << ptr->ano << endl;
        cout << "  KM: " << ptr->km << endl;
        cout << "  Potencia: " << ptr->potencia << endl;
        cout << "  Combustivel: " << ptr->combustivel << endl;
        cout << "  Cambio: " << ptr->cambio << endl;
        cout << "  Direcao: " << ptr->direcao << endl;
        cout << "  Numero de Portas: " << ptr->nPortas << endl;
        cout << "  Placa: " << ptr->placa << endl;
        cout << "+-------------------------------------------+" << endl;
        ptr = ptr->prox;
    }
}

// ------------------------------ARVORE BINÁRIA------------------------------------

noArvore *insere_arvore(noArvore *raiz, no **end) {
    if (raiz == NULL) {
        noArvore *ptr = new(noArvore);
        ptr->end = *end;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        return ptr;
    } else {
        if ((*end)->placa < raiz->end->placa) {
            raiz->esquerda = insere_arvore(raiz->esquerda, end);
        }
        if ((*end)->placa > raiz->end->placa) {
            raiz->direita = insere_arvore(raiz->direita, end);
        }
        return raiz;
    }
}

/**
 * Imprime a árvore AVL em pré-ordem
 * @param raiz arvore avl
 */
void imprime_preOrdem(noArvore *raiz) {
    cout << "+-------------------------------------------+" << endl;
    cout << "  Modelo: " << raiz->end->modelo << endl;
    cout << "  Marca: " << raiz->end->marca << endl;
    cout << "  Tipo: " << raiz->end->tipo << endl;
    cout << "  Ano: " << raiz->end->ano << endl;
    cout << "  KM: " << raiz->end->km << endl;
    cout << "  Potencia: " << raiz->end->potencia << endl;
    cout << "  Combustivel: " << raiz->end->combustivel << endl;
    cout << "  Cambio: " << raiz->end->cambio << endl;
    cout << "  Direcao: " << raiz->end->direcao << endl;
    cout << "  Numero de Portas: " << raiz->end->nPortas << endl;
    cout << "  Placa: " << raiz->end->placa << endl;
    cout << "+-------------------------------------------+" << endl;
    if (raiz->esquerda != NULL) {
        imprime_preOrdem(raiz->esquerda);
    }
    if (raiz->direita != NULL) {
        imprime_preOrdem(raiz->direita);
    }
}

// Imprime as placas da arvore binaria da esquerda pra direita (crescente)

void imprime_arvore(noArvore *raiz) {
    if (raiz != NULL) {
        imprime_arvore(raiz->esquerda);
        cout << "--------------------------------------" << endl;
        cout << "Placa: " << raiz->end->placa << endl;
        imprime_arvore(raiz->direita);
    }
}

void encerra_arvore(noArvore *raiz) {
    if (raiz != NULL) {
        encerra_arvore(raiz->esquerda);
        encerra_arvore(raiz->direita);
        delete(raiz);
    }
}

noArvore *busca_arvore(noArvore *raiz, string placa) {
    if (raiz != NULL) {
        if (raiz->end->placa == placa) {
            return raiz;
        } else {
            if (placa > raiz->end->placa) {
                return busca_arvore(raiz->direita, placa);
            } else {
                return busca_arvore(raiz->esquerda, placa);
            }
        }
    }
    return NULL;
}


// ---------------------------------ÁRVORE AVL---------------------------------

short alturaNoAVL(noAVL *raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        return raiz->altura;
    }
}

short fatorAVL(noAVL *raiz) {
    if (raiz) {
        return (alturaNoAVL(raiz->esquerda) - alturaNoAVL(raiz->direita));
    } else {
        return 0;
    }
}

short maior(short n, short m) {
    return (n > m) ? n : m;
}

noAVL *rotacaoEsquerda(noAVL *raiz) {
    noAVL *ptr1, *ptr2;
    ptr1 = raiz->direita;
    ptr2 = ptr1->esquerda;
    ptr1->esquerda = raiz;
    raiz->direita = ptr2;
    raiz->altura = maior(alturaNoAVL(raiz->esquerda), alturaNoAVL(raiz->direita)) + 1;
    ptr1->altura = maior(alturaNoAVL(ptr1->esquerda), alturaNoAVL(ptr1->direita)) + 1;
    return ptr1;
}

noAVL *rotacaoDireita(noAVL *raiz) {
    noAVL *ptr1, *ptr2;
    ptr1 = raiz->esquerda;
    ptr2 = ptr1->direita;
    ptr1->direita = raiz;
    raiz->esquerda = ptr2;
    raiz->altura = maior(alturaNoAVL(raiz->esquerda), alturaNoAVL(raiz->direita)) + 1;
    ptr1->altura = maior(alturaNoAVL(ptr1->esquerda), alturaNoAVL(ptr1->direita)) + 1;
    return ptr1;
}

noAVL *rotacaoEsquerdaDireita(noAVL *raiz) {
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
}

noAVL *rotacaoDireitaEsquerda(noAVL *raiz) {
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
}

noAVL *balancearAVL(noAVL *raiz) {
    short fb = fatorAVL(raiz);
    if (fb < -1 && fatorAVL(raiz->direita) <= 0) {
        raiz = rotacaoEsquerda(raiz);
    }
    if (fb > 1 && fatorAVL(raiz->esquerda) >= 0) {
        raiz = rotacaoDireita(raiz);
    }
    if (fb > 1 && fatorAVL(raiz->esquerda) < 0) {
        raiz = rotacaoEsquerdaDireita(raiz);
    }
    if (fb < -1 && fatorAVL(raiz->direita) > 0) {
        raiz = rotacaoDireitaEsquerda(raiz);
    }
    return raiz;
}

noAVL *insere_avl(noAVL *raiz, no **end) {
    if (raiz == NULL) {
        noAVL *ptr = new(noAVL);
        ptr->end = *end;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        ptr->altura = 0;
        return ptr;
    } else {
        if ((*end)->placa < raiz->end->placa) {
            raiz->esquerda = insere_avl(raiz->esquerda, end);
        }
        if ((*end)->placa > raiz->end->placa) {
            raiz->direita = insere_avl(raiz->direita, end);
        }
    }
    raiz->altura = maior(alturaNoAVL(raiz->esquerda), alturaNoAVL(raiz->direita)) + 1;
    raiz = balancearAVL(raiz);
    return raiz;
}

/**
 * Imprime a árvore AVL em pré-ordem
 * @param raiz arvore avl
 */
void imprime_preOrdemAVL(noAVL *raiz) {
    cout << "+-------------------------------------------+" << endl;
    cout << "  Modelo: " << raiz->end->modelo << endl;
    cout << "  Marca: " << raiz->end->marca << endl;
    cout << "  Tipo: " << raiz->end->tipo << endl;
    cout << "  Ano: " << raiz->end->ano << endl;
    cout << "  KM: " << raiz->end->km << endl;
    cout << "  Potencia: " << raiz->end->potencia << endl;
    cout << "  Combustivel: " << raiz->end->combustivel << endl;
    cout << "  Cambio: " << raiz->end->cambio << endl;
    cout << "  Direcao: " << raiz->end->direcao << endl;
    cout << "  Numero de Portas: " << raiz->end->nPortas << endl;
    cout << "  Placa: " << raiz->end->placa << endl;
    cout << "+-------------------------------------------+" << endl;
    if (raiz->esquerda != NULL) {
        imprime_preOrdemAVL(raiz->esquerda);
    }
    if (raiz->direita != NULL) {
        imprime_preOrdemAVL(raiz->direita);
    }
}

// Imprime as placas arvore AVL da esquerda pra direita (crescente)
void imprime_avl(noAVL *raiz) {
    if (raiz != NULL) {
        imprime_avl(raiz->esquerda);
        cout << "--------------------------------------" << endl;
        cout << "Placa: " << raiz->end->placa << endl;
        imprime_avl(raiz->direita);
    }
}

void encerra_avl(noAVL *raiz) {
    if (raiz != NULL) {
        encerra_avl(raiz->esquerda);
        encerra_avl(raiz->direita);
        delete(raiz);
    }
}

// ------------------------------------------------------------------



















