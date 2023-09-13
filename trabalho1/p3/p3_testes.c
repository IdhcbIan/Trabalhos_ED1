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


int main() {
    //Pegando tamanho
    int size;
    scanf("%d", &size);
    
    //Pegando vetor
    int vector[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }

    
    //Pegando numero de pesquisas
    int searches;
    scanf("%d", &searches);
   

    //Pegando pesquisas
    int find;
    int to_find[searches];

    
    for(int i=0; i<searches; i++){
        scanf("%d", &find);
        to_find[i] = find;
    }


    //Buscando a lista
    for(int i=0; i<searches; i++){
      binary_find(size, vector, to_find[i]);
    }




    return 0;
}
