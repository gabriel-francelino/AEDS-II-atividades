#include<stdio.h>
#include<stdlib.h>

typedef struct no_arvore_ no_arvore;
struct no_arvore_{
    int valor;
    no_arvore * esq;
    no_arvore * dir;
};

/**
 * @brief aloca a memória e inicia o novo nó com os valores esperados.
 * 
 * @param valor valor a ser guardado no nó
 * @return no_arvore* endereço do novo nó alocado.
 */
no_arvore * inicia_no(int valor){
    no_arvore * no = malloc(sizeof(no_arvore));
    no-> valor = valor;
    no->esq = NULL;
    no->dir = NULL;

    return no;
}

/**
 * @brief realiza a busca do nó na árvore.
 * 
 * @param raiz raiz da árvore onde será feita a busca
 * @param valor valor que se deseja buscar na árvore
 * @return no_arvore* retorna NULL caso o valor não esteja na árvore. Caso contrário, o endereço do nó contendo o valor.
 */
no_arvore * busca(no_arvore * raiz, int valor){
    //retorna null se o valor não for encontrado
    //caso contrário, retorna o nó contendo o valor
    if(raiz == NULL ||raiz->valor == valor){
        return raiz;
    }

    if(raiz->valor > valor){
        return busca(raiz->esq, valor);
    }else{
        return busca(raiz->dir, valor);
    }
}

/**
 * @brief realiza a inserção do nó na árvore
 * 
 * @param raiz raiz da árvore onde será feita a inserção
 * @param no nó que será inserido
 * @return no_arvore* a raiz da árvore.
 */
no_arvore * insere(no_arvore * raiz, no_arvore * no){
    if(raiz == NULL){
        return no;
    }
    //evitando que nos duplicados sejam inseridos na arvore
    if(busca(raiz, no->valor) != NULL){
        free(no);
        return raiz;
    }

    if(raiz->valor > no->valor){
        raiz->esq = insere(raiz->esq, no);
    }else{
        raiz->dir = insere(raiz->dir, no);
    }

    return raiz;
}



/**
 * @brief imprime a árvore passada.
 * 
 * @param raiz raiz da árvore a ser impressa
 * @param ordem parâmetro que define a ordem de impressão da árvore. Os valores aceitos são:
 * 1 - pré-ordem
 * 2 - em-ordem
 * 3 - pós-ordem
 */
void imprime(no_arvore * raiz, int ordem){
    if(raiz == NULL){
        printf("Árvore vazia.\n");
        return;
    }

    switch (ordem)
    {
    case 1:
        printf("%d ", raiz->valor);
        if(raiz->esq != NULL){
            imprime(raiz->esq, 1);
        }
        if(raiz->dir != NULL){
            imprime(raiz->dir, 1);
        }
        break;

    case 2:
        if(raiz->esq != NULL){
            imprime(raiz->esq, 2);
        }
        printf("%d ", raiz->valor);
        if(raiz->dir != NULL){
            imprime(raiz->dir, 2);
        }
        break;

    case 3:
        if(raiz->esq != NULL){
            imprime(raiz->esq, 3);
        }
        if(raiz->dir != NULL){
            imprime(raiz->dir, 3);
        }
        printf("%d ", raiz->valor);
        break;
    
    default:
        printf("==============================\n");
        printf("Ordem inválida! As opções são:\n");
        printf("1 - pré-ordem\n");
        printf("2 - em-ordem\n");
        printf("3 - pós-ordem\n");
        printf("==============================\n");
        break;
    }
}

int main(){
    no_arvore * raiz = NULL;
    no_arvore * no = inicia_no(2);
    raiz = insere(raiz, no);

    no = inicia_no(1);
    raiz = insere(raiz, no);

    no = inicia_no(4);
    raiz = insere(raiz, no);

    no = inicia_no(5);
    raiz = insere(raiz, no);

    imprime(raiz, 1);
    printf("\n");

    imprime(raiz, 2);
    printf("\n");

    imprime(raiz, 3);
    printf("\n");

    /*TODO*/
    //implementar a função de remoção de nós.

    //implementar uma função que deve ser chamada ao término do programa para liberar
    //a memória alocada para a árvore.

    return 0;
}