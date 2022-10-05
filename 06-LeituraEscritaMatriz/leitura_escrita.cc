
#include <iostream>
#include <fstream> //biblioteca para manipular arquivos

using namespace std;

int main(int argc, char**argv) {

    //escrita no arquivo---------------------------------------------------------------------------
    ofstream myfile;
    myfile.open("exemplo.txt");
    if (myfile.is_open()) {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    } else
        cout << "Unable to open file.";

    
    //leitura do arquivo---------------------------------------------------------------------------
    string line;
    ifstream myfile ("exemplo.txt");
    if (myfile.is_open()){  //is_open verifica se ela existe
        while(!myfile.eof()){   //eof verifica se chegou no fim do arquivo
            myfile >> line;
            cout << "string: " << line << endl;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file"; 
     
    //leitura de uma matriz---------------------------------------------------------------------------
        int lin, col, i, j, *p;
    int mat[3][4];
    
    // Prints welcome message...
    cout << "Leitura de matriz" << endl;

    ifstream myfile1 ("matriz1.mtz");
    if (myfile1.is_open()){
        while ( !myfile1.eof() ){
            myfile1 >> lin;
            cout << "    Linhas: " << lin;
            myfile1 >> col;
            cout << "    Colunas: " << col << endl;
            if (lin < 1 or col < 1){
                cout << "Erro: dimensões não formam matriz." << endl;
                return -1;
            }
            int *p = &mat[0][0];
            for (int i = 0; i < lin; i++){
                for (int j = 0; j < col; j++){
                    //myfile1 >> mat[i][j];
                    myfile1 >> *p;
                    p++;
                    cout << "  mat[" << i << "][" << j << "]: " << mat[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }
        myfile1.close();
    }
    else
        cout << "Unable to open file"; 
    
    //escrita da matriz em um arquivo---------------------------------------------------------------------------
    ofstream myfile2;
    myfile2.open ("matriz2.mtz");
    if (myfile2.is_open()){
        cout << "Escrita da Matriz" << endl;
        myfile2 << lin << " " << col << endl;
        for (int i = 0; i < lin; i++){
            for (int j = 0; j < col; j++){
                myfile2 << mat[i][j] << " ";
            }
            myfile2 << endl;
        }
        cout << endl;
        myfile2.close();
    }
    else 
        cout << "Unable to open file";
     

    return 0;
}
