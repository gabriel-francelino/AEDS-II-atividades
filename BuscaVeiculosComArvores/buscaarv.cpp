#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void interface() {
    cout << endl;
    cout << "+-------------------------------------------+" << endl;
    cout << "|         GERENCIAMENTO DE BUSCA            |" << endl;
    cout << "|     Escolha qual comando deseja fazer:    |" << endl;
    cout << "|       1)Adicinar veiculo.                 |" << endl;
    cout << "|       2)Remover veiculo.                  |" << endl;
    cout << "|       3)Arvore Binaria.                   |" << endl;
    cout << "|       4)Arvore AVL.                       |" << endl;
    cout << "|       5)Relatorio.                        |" << endl;
    cout << "|   Ou aperte outra tecla para finalizar.   |" << endl;
    cout << "+-------------------------------------------+" << endl;
}

// ------------------------------------------------------------------

// NO Veiculos

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

// ------------------------------------------------------------------

// LISTA

typedef struct {
	int tam;            
	struct no_ *lista;
} tLista;

tLista* inicia_lista() {
	tLista* tmp = new(tLista);
	tmp->tam = 0;
	tmp->lista = NULL;
	return tmp;
}

void encerra_lista(tLista *ptlista) {
	no *ant = ptlista->lista;
	no *pont = ptlista->lista;
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
}

bool busca_enc(tLista *ptlista, string placa,  no **ant) {
    *ant = ptlista->lista;
	no *ptr = ptlista->lista;
	while (ptr != NULL && ptr->placa != placa) {
        *ant = ptr;
        ptr = ptr->prox;
    }
	return ptr != NULL && ptr->placa == placa;
}

bool insere_enc(tLista *ptlista, string placa, no *veiculo){
	no* ant;
    if (ptlista->tam == 0){
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
    if(busca_enc(ptlista, placa, &ant))
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

bool remove_enc(tLista *ptlista, string placa){
	no* ant, *ptr;
	if(ptlista->tam == 0 || !busca_enc(ptlista, placa, &ant))
            return false;
        if (ant->placa == placa){
            ptlista->lista = ant->prox;
            ptr = ant;
        } else {
            ptr = ant->prox;
            ant->prox = ptr->prox;
        }
        ptr->prox = NULL;
	return true;
}

void imprime(tLista *ptlista){
	no *ptr = ptlista->lista;
    cout << "+-------------------------------------------+" << endl;
	while(ptr != NULL){
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

tLista *lista;

// ------------------------------------------------------------------

// NO Arvore Binaria

typedef struct noArvore {
    no *end;
    struct noArvore *esquerda;
    struct noArvore *direita;
} noArvore;

// Árvore Binária

noArvore *insere_arvore(noArvore *raiz, no **end) {
    if(raiz == NULL) {
        noArvore *ptr = new(noArvore);
        ptr->end = *end;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        return ptr;
    } else {
        if((*end)->placa < raiz->end->placa) {
            raiz->esquerda = insere_arvore(raiz->esquerda, end);
        } 
        if((*end)->placa > raiz->end->placa) {
            raiz->direita = insere_arvore(raiz->direita, end);
        }
        return raiz;
    }
}

// Imprime a arvore binaria da esquerda pra direita (crescente)
void imprime_arvore(noArvore *raiz) {
    if(raiz != NULL) {
        imprime_arvore(raiz->esquerda);
        cout << "--------------------------------------" << endl;
        cout << "Placa: " << raiz->end->placa << endl;
        imprime_arvore(raiz->direita);
    }
}

void encerra_arvore(noArvore *raiz) {
    if(raiz != NULL) {
        encerra_arvore(raiz->esquerda);
        encerra_arvore(raiz->direita);
        delete(raiz);
    }
}

noArvore *busca_arvore(noArvore *raiz, string placa) {
    if(raiz != NULL) {
        if(raiz->end->placa == placa){
            return raiz;
        } else {
            if(placa > raiz->end->placa) {
                return busca_arvore(raiz->direita, placa);
            } else {
                return busca_arvore(raiz->esquerda, placa);
            }
        }
    }
    return NULL;
}

noArvore *arvore;

// ------------------------------------------------------------------

// NO Arvore AVL

typedef struct noAVL {
    no *end;
    struct noAVL *esquerda;
    struct noAVL *direita;
    short altura;
} noAVL;

// Arvore AVL

short alturaNoAVL(noAVL *raiz) {
    if(raiz == NULL) {
        return -1;
    } else {
        return raiz->altura;
    }
}

short fatorAVL(noAVL *raiz) {
    if(raiz) {
        return (alturaNoAVL(raiz->esquerda) - alturaNoAVL(raiz->direita));
    } else {
        return 0;
    }
}

short maior(short n, short m){
    return (n > m)? n : m;
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

noAVL *balancearAVL(noAVL *raiz){
    short fb = fatorAVL(raiz);
    if(fb < -1 && fatorAVL(raiz->direita) <= 0) {
        raiz = rotacaoEsquerda(raiz);
    }
    if(fb > 1 && fatorAVL(raiz->esquerda) >= 0) {
        raiz = rotacaoDireita(raiz);
    }
    if(fb > 1 && fatorAVL(raiz->esquerda) < 0) {
        raiz = rotacaoEsquerdaDireita(raiz);
    }
    if(fb < -1 && fatorAVL(raiz->direita) > 0) {
        raiz = rotacaoDireitaEsquerda(raiz);
    }
    return raiz;
}

noAVL *insere_avl(noAVL *raiz, no **end) {
    if(raiz == NULL) {
        noAVL *ptr = new(noAVL);
        ptr->end = *end;
        ptr->esquerda = NULL;
        ptr->direita = NULL;
        ptr->altura = 0;
        return ptr;
    } else {
        if((*end)->placa < raiz->end->placa) {
            raiz->esquerda = insere_avl(raiz->esquerda, end);
        } 
        if((*end)->placa > raiz->end->placa) {
            raiz->direita = insere_avl(raiz->direita, end);
        }
    }
    raiz->altura = maior(alturaNoAVL(raiz->esquerda), alturaNoAVL(raiz->direita)) + 1;
    raiz = balancearAVL(raiz);
    return raiz;
}

// Imprime a arvore AVL da esquerda pra direita (crescente)
void imprime_avl(noAVL *raiz) {
    if(raiz != NULL) {
        imprime_avl(raiz->esquerda);
        cout << "--------------------------------------" << endl;
        cout << "Placa: " << raiz->end->placa << endl;
        imprime_avl(raiz->direita);
    }
}

void encerra_avl(noAVL *raiz) {
    if(raiz != NULL) {
        encerra_avl(raiz->esquerda);
        encerra_avl(raiz->direita);
        delete(raiz);
    }
}

noAVL *avl;

// ------------------------------------------------------------------

int main(int argc, char** argv) {
    int op;
    ifstream cadastro("BD_veiculos.txt");
    if(cadastro.is_open()){
        lista = inicia_lista();
        while(!cadastro.eof()){
            no *dados = new(no);
            cadastro >> dados->modelo;
            cadastro >> dados->marca;
            cadastro >> dados->tipo;
            cadastro >> dados->ano;
            cadastro >> dados->km;
            cadastro >> dados->potencia;
            cadastro >> dados->combustivel;
            cadastro >> dados->cambio;
            cadastro >> dados->direcao;
            cadastro >> dados->cor;
            cadastro >> dados->nPortas;
            cadastro >> dados->placa;
            dados->prox = NULL;
            insere_enc(lista, dados->placa, dados);
            delete(dados);
        }
        cadastro.close();
    } else {
        cout << "Arquivo nao encontrado!" << endl;
        delete(lista);
        return 0;
    }
    do {
        interface();
        cout << "Digite a opcao que deseja realizar: ";
        cin >> op;
        cout << endl;
        switch (op) {
            case 1: {
                cout << "Digite as informacoes do veiculo:" << endl << endl;
                no veiculo;
                cout << "Modelo do veiculo: ";
                cin.ignore();
                getline(cin, veiculo.modelo);
                cout << "Marca do veiculo: ";
                getline(cin, veiculo.marca);
                cout << "Tipo do veiculo: ";
                getline(cin, veiculo.tipo);
                cout << "Ano do veiculo: ";
                cin >> veiculo.ano;
                cout << "Km do veiculo: ";
                cin >> veiculo.km;
                cout << "Potencia do veiculo: ";
                cin >> veiculo.potencia;
                cout << "Combustivel do veiculo: ";
                cin.ignore();
                getline(cin, veiculo.combustivel);
                cout << "Cambio do veiculo: ";
                getline(cin, veiculo.cambio);
                cout << "Direcao do veiculo: ";
                getline(cin, veiculo.direcao);
                cout << "Cor do veiculo: ";
                getline(cin, veiculo.cor);
                cout << "Numero de portas do veiculo: ";
                cin >> veiculo.nPortas;
                cout << "Placa do veiculo: ";
                cin.ignore();
                getline(cin, veiculo.placa);
                cout << endl;
                veiculo.prox = NULL;
                if(insere_enc(lista, veiculo.placa, &veiculo)){
                    cout << "Adicionado com sucesso!" << endl;
                } else {
                    cout << "Falha ao adicionar." << endl;
                }
            } break;
            case 2: {
                cout << "Digite a placa do veiculo que sera removida: ";
                string placa; 
                cin.ignore();
                getline(cin, placa);
                cout << endl;
                if(remove_enc(lista, placa)){
                    cout << "Removido com sucesso!" << endl;
                } else {
                    cout << "Falha ao remover." << endl;
                }
            } break;
            case 3: {
                cout << "Arvore Binaria" << endl;
                encerra_arvore(arvore);
                arvore = NULL;
                no *ptr = lista->lista;
                while(ptr != NULL){
                    // Adiciona todos os elementos da lista na árvore
                    arvore = insere_arvore(arvore, &ptr);
                    ptr = ptr->prox;
                }
                imprime_arvore(arvore);
                cout << "--------------------------------------" << endl;
            } break;
            case 4: {
                cout << "Arvore AVL" << endl;
                encerra_avl(avl);
                avl = NULL;
                no *ptr = lista->lista;
                while(ptr != NULL){
                    // Adiciona todos os elementos da lista na avl
                    avl = insere_avl(avl, &ptr);
                    ptr = ptr->prox;
                }
                imprime_avl(avl);
                cout << "--------------------------------------" << endl;
            } break;
            case 5: {
                cout << "Relatorio: " << endl;
                imprime(lista);
            } break;
            default: {
                encerra_avl(avl);
                encerra_arvore(arvore);
                encerra_lista(lista);
                op = 6;
            } break;
        }
    } while (op != 6);
    system("pause");
    return 0;
}