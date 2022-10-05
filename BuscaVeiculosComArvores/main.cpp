#include <cstdlib>
#include <iostream>
#include <fstream>
//#include <string>

#include "arvores.h"

using namespace std;

/**
 * @brief Interface para interação com o usuário.
 * 
 */
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

// Variaveis---------------------------------------------------------
noArvore *arvore;;
noAVL *avl;
tLista *lista;

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
            case 1:
            {
                cout << "Digite as informacoes do veiculo:" << endl << endl;
                no veiculo;

                cout << "Modelo do veiculo: (Para nomes compostos: nome1_nome2)" << endl;
                cin >> veiculo.modelo;
                cout << "Marca do veiculo: " << endl;
                cin >> veiculo.marca;
                cout << "Tipo do veiculo: " << endl;
                cin >> veiculo.tipo;
                cout << "Ano do veiculo: " << endl;
                cin >> veiculo.ano;
                cout << "Km do veiculo: " << endl;
                cin >> veiculo.km;
                cout << "Potencia do veiculo: " << endl;
                cin >> veiculo.potencia;
                cout << "Combustivel do veiculo: " << endl;
                cin >> veiculo.combustivel;
                cout << "Cambio do veiculo: " << endl;
                cin >> veiculo.cambio;
                cout << "Direcao do veiculo: " << endl;
                cin >> veiculo.direcao;
                cout << "Cor do veiculo: " << endl;
                cin >> veiculo.cor;
                cout << "Numero de portas do veiculo: " << endl;
                cin >> veiculo.nPortas;
                cout << "Placa do veiculo: " << endl;
                cin >> veiculo.placa;

                veiculo.prox = NULL;

                if(insere_enc(lista, veiculo.placa, &veiculo)){
                    cout << "Adicionado com sucesso!" << endl;
                } else {
                    cout << "Falha ao adicionar." << endl;
                }
            };
            break;
            case 2:
            {
                cout << "Digite a placa do veiculo que sera removida: ";
                string placa; 
                cin >> placa;
                cout << endl;
                if(remove_enc(lista, placa)){
                    cout << "Removido com sucesso!" << endl;
                } else {
                    cout << "Falha ao remover." << endl;
                }
            }
            break;
            case 3:
            {
                cout << "Arvore Binaria" << endl;
                encerra_arvore(arvore);
                arvore = NULL;
                no *ptr = lista->lista;
                while(ptr != NULL){
                    // Adiciona todos os elementos da lista na árvore
                    arvore = insere_arvore(arvore, &ptr);
                    ptr = ptr->prox;
                }
                imprime_preOrdem(arvore);
                cout << "--------------------------------------" << endl;
            }
            break;
            case 4:
            {
                cout << "Arvore AVL" << endl;
                encerra_avl(avl);
                avl = NULL;
                no *ptr = lista->lista;
                while(ptr != NULL){
                    // Adiciona todos os elementos da lista na avl
                    avl = insere_avl(avl, &ptr);
                    ptr = ptr->prox;
                }
                imprime_preOrdemAVL(avl);
                cout << "--------------------------------------" << endl;
            }
            break;
            case 5:
            {
                cout << "Relatorio: " << endl;
                imprime(lista);
            }
            break;
            default:
            {
                encerra_avl(avl);
                encerra_arvore(arvore);
                encerra_lista(lista);
                cout << "+-------------------------------------------+" << endl;
                cout << "|      Programa finalizado com sucesso!!    |" << endl;
                cout << "+-------------------------------------------+" << endl;
                op = 6;
            }
            break;
        }
    } while (op != 6);
    return 0;
}
