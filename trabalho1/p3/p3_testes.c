/*
╔══╗─────────────╔══╗
║╔╗║─────────────║╔╗║
║╚╝╚╦╗╔╦══╦══╦══╗║╚╝╚╦╦═╗╔══╦═╦╦══╗
║╔═╗║║║║══╣╔═╣╔╗║║╔═╗╠╣╔╗╣╔╗║╔╬╣╔╗║
║╚═╝║╚╝╠══║╚═╣╔╗║║╚═╝║║║║║╔╗║║║║╔╗║
╚═══╩══╩══╩══╩╝╚╝╚═══╩╩╝╚╩╝╚╩╝╚╩╝╚╝
*/
#include<stdio.h>
#include<stdbool.h>

//Criando uma funcao que Printa um vetor(para visualisacao) //-----------
void vector_print(int size, int v[size]) {
    for(int i = 0; i < size; i++) {
        printf("%d ", v[i]);

    }
    printf("\n");
}


//Criando uma funcao que busca o vetor //-----------
int binary_find(int size, int vector[size], int find){
  int low = 0;
  int high = size -1; //Index do ultimo
  bool found = false; 

  while (low<=high) {
    int mid = (low+high) / 2;
    if (vector[mid] == find){
      printf("%d\n", mid);
      found = true;
      break;
    }else if (vector[mid]<find) {
      low = mid + 1;
    }else{
      high = mid -1;
    }
  }
  if (found == false){
    printf("-1\n");
  }
}


// Defining the Vector
int vector[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


int main() {
    // Getting size of the vector
    int size = sizeof(vector) / sizeof(vector[0]); 

    // Reading the value to find
    int find;
    scanf("%d", &find);



    //Buscando a lista
    binary_find(size, vector, find);


    return 0;
}
