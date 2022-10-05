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

/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @param pont ponteiro que aponta a posicao encontrada.
 */
void busca_enc(no * ptlista, int chave, no ** ant, no ** pont) {
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

void busca_fim_enc(no * ptlista, int chave, no ** ant, no ** pont) {
    *ant = ptlista;
    *pont = NULL;
    no* ptr = ptlista->prox;
    
    while(ptr != NULL){
        if(ptr->chave == chave){
            *pont = ptr;
            ptr = NULL;
        }else{
            *ant = ptr;
            ptr = ptr->prox;
            
        }
        
    }
}

/**
 * Realiza a insercao na lista encadeada ordenada (sem repeticoes).
 * @param chave a ser inserida.
 * @param valor a ser inserido.
 * @return -1 em caso de falha, 0 em caso de sucesso.
 */
int insere_enc(no * ptlista, int chave, int valor) {
    int retorno = -1;
    no* ant;
    no* pont;

    busca_enc(ptlista, chave, &ant, &pont);

    if (pont == NULL) {
        no * ptr = new(no);
        ptr->chave = chave;
        ptr->valor = valor;
        ptr->prox = ant->prox;
        ant->prox = ptr;
        retorno = 0;
    }

    return retorno;
}


int insere_fim_enc(no * ptlista, int chave, int valor) {
    int retorno = -1;
    no* ptr = new(no);
    no* ant;
    no* pont;
    
    busca_fim_enc(ptlista, chave, &ant, &pont);
    
    if(pont == NULL){
        ptr->chave = chave;
        ptr->valor = valor;
        ant->prox = ptr;
        retorno = 0;
    }
    
    return retorno;
}
/*
int insere_inicio_enc(no * ptlista, int chave, int valor) {
    
}
*/

/**
 * Realiza a remocao do elemento passado caso o mesmo esteja na lista encadeada.
 * @param chave do elemento a ser removido.
 * @return nulo em caso de lista vazia ou elemento inexistente,
 * e o no removido caso contrario.
 */
no * remove_enc(no * ptlista, int chave) {
    no* ant;
    no* pont;

    busca_enc(ptlista, chave, &ant, &pont);
    if (pont != NULL) {
        ant->prox = pont->prox;
        return pont;
    }
    return NULL;
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

