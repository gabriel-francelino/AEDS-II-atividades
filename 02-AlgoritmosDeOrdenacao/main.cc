#include <iostream>

using namespace std;

void bubblesort(int *v){
  int aux, atrib = 0;
  for (int i = 9; i > 0; i--)
    for (int j = 0; j < i; j++)
      if (v[j] > v[j+1]) {
        aux = v[j]; atrib++;
        v[j] = v[j+1]; atrib++;
        v[j+1] = aux; atrib++;
      }
  cout << atrib << " atribuições." << endl;
}

void insertionsort(int *v){
  int aux, j, atrib = 0;
  for (int i = 1; i < 10; i++){
    aux = v[i]; atrib++;
    j = i - 1;
    while (j >= 0 && v[j] > aux){
      v[j+1] = v[j]; atrib++;
      j--;
    }
    v[j+1] = aux; atrib++;
  }
  cout << atrib << " atribuições." << endl;
}

void selectionsort(int *v){
  int aux, j, min, atrib = 0;
  for (int i = 0; i < 10; i++){
    min = i;
    aux = v[i]; atrib++;
    for (int j = i+1; j < 10; j++)
      if (v[j] < aux) {
        aux = v[j]; atrib++;
        min = j;
      }
    v[min] = v[i]; atrib++;
    v[i] = aux; atrib++;
  }
  cout << atrib << " atribuições." << endl;
}

void imprimevetor(int *v){
  for (int i = 0; i < 10; i++)
    cout << "  " << v[i];
  cout << endl;
}

int main(int argc, char**argv){

  cout << endl << " Métodos de Ordenação" << endl << endl;

  int vb0[10] = {0,1,2,3,4,5,6,7,8,9}; // Vetor ordenado.
  int vb1[10] = {5,8,2,0,6,9,1,4,3,7}; // Vetor desordenado.
  int vb2[10] = {9,8,7,6,5,4,3,2,1,0}; // Vetor em ordem inversa.

  cout << " Bubble Sort, vetor ordenado: " << endl;
  imprimevetor(vb0);
  bubblesort(vb0);
  imprimevetor(vb0);

  cout << " Bubble Sort, vetor desordenado: " << endl;
  imprimevetor(vb1);
  bubblesort(vb1);
  imprimevetor(vb1);

  cout << " Bubble Sort, vetor em ordem inversa: " << endl;
  imprimevetor(vb2);
  bubblesort(vb2);
  imprimevetor(vb2);

  cout << endl;

  int vi0[10] = {0,1,2,3,4,5,6,7,8,9}; // Vetor ordenado.
  int vi1[10] = {5,8,2,0,6,9,1,4,3,7}; // Vetor desordenado.
  int vi2[10] = {9,8,7,6,5,4,3,2,1,0}; // Vetor em ordem inversa.

  cout << " Insertion Sort, vetor ordenado: " << endl;
  imprimevetor(vi0);
  insertionsort(vi0);
  imprimevetor(vi0);

  cout << " Insertion Sort, vetor desordenado: " << endl;
  imprimevetor(vi1);
  insertionsort(vi1);
  imprimevetor(vi1);

  cout << " Insertion Sort, vetor em ordem inversa: " << endl;
  imprimevetor(vi2);
  insertionsort(vi2);
  imprimevetor(vi2);

  cout << endl;

  int vs0[10] = {0,1,2,3,4,5,6,7,8,9}; // Vetor ordenado.
  int vs1[10] = {5,8,2,0,6,9,1,4,3,7}; // Vetor desordenado.
  int vs2[10] = {9,8,7,6,5,4,3,2,1,0}; // Vetor em ordem inversa.

  cout << " Selection Sort, vetor ordenado: " << endl;
  imprimevetor(vs0);
  selectionsort(vs0);
  imprimevetor(vs0);

  cout << " Selection Sort, vetor desordenado: " << endl;
  imprimevetor(vs1);
  selectionsort(vs1);
  imprimevetor(vs1);

  cout << " Selection Sort, vetor em ordem inversa: " << endl;
  imprimevetor(vs2);
  selectionsort(vs2);
  imprimevetor(vs2);

  cout << endl;
  return 0;
}
