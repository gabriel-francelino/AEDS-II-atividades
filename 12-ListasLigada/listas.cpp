/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct no_ {
    //critério de busca da ordenação
    int chave;

    //'carga útil' do nó
    //num cenario real, poderia ser, por exemplo: nome, endereco...
    int valor;

    struct no_ * prox;
} no;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
no* inicia_lista() {
    no* tmp = new (no);
    tmp->chave = 0;
    tmp->valor = 0;
    tmp->prox = NULL;

    cout << "-A lista foi iniciada." << endl;
    return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 */
void encerra_lista(no * ptlista) {
    no * ant = ptlista->prox;
    no * pont = ant->prox;

    while (pont != NULL) {
        delete(ant);
        ant = pont;
        pont = pont->prox;
    }
    delete(ant);
    cout << "-A lista foi removida." << endl;

    delete(ptlista);
}

void busca(no * ptlista, int chave, no ** ant, no ** pont) {
    *ant = ptlista;
    *pont = NULL;
    no* ptr = ptlista->prox;

    while (ptr != NULL) {
        if (ptr->chave == chave) {
            *pont = ptr;
            ptr = NULL;
        } else {
            *ant = ptr;
            ptr = ptr->prox;
        }

    }
}

int insere_fim(no * ptlista, int chave, int valor) {
    int retorno = -1;
    no* ptr = new(no);
    no* pont;
    no* inicio;
    no* fim = ptlista;

    busca(ptlista, chave, &fim, &pont);

    if (pont == NULL) {
        ptr->chave = chave;
        ptr->valor = valor;
        fim->prox = ptr;
        ptr->prox = NULL;
        retorno = 0;
    }

    return retorno;
}

int insere_inicio(no * ptlista, int chave, int valor) {
    int retorno = -1;
    no* ptr = new(no);
    no* inicio;
    no* pont;

    busca(ptlista, chave, &inicio, &pont);

    inicio = ptlista;

    if (pont == NULL) {
        ptr->chave = chave;
        ptr->valor = valor;
        ptr->prox = inicio->prox;
        inicio->prox = ptr;
        retorno = 0;
    }



    return retorno;
}

no * remove_inicio(no * ptlista) {
    no* retorno = NULL;
    no* pont = ptlista->prox;

    if (pont != NULL) {
        retorno = pont;
        *pont = *pont->prox;
    }
    return retorno;
}

/*no * remove_fim(no * ptlista) {
    no* retorno = NULL;
    no* pont = ptlista;

    while (pont->prox != NULL) {
        pont = pont->prox;
    }
    retorno = pont;
    //pont = pont->prox;
    pont->prox = NULL;
    

    return retorno;
}*/


no * remove_fim(no * ptlista) {
    no* retorno = NULL;
    no* pont = ptlista;
    no* ant;
    while (pont->prox != NULL) {
        ant = pont;
        pont = pont->prox;   
        retorno = ant;
    }
    ant->prox = NULL;
    
    return retorno;
}
 

/**
 * Imprime a lista encadeada.
 */
void imprime(no * ptlista) {
    no * ptr = ptlista->prox;
    cout << "---Estado atual da lista:";
    while (ptr != NULL) {
        cout << "-> (" << ptr->chave << "," << ptr->valor << ") ";
        ptr = ptr->prox;
    }
    cout << endl;
}

