/*
╭━━╮╱╱╱╱╱╱╱╱╱╱╱╱╱╭━━━╮
┃╭╮┃╱╱╱╱╱╱╱╱╱╱╱╱╱┃╭━╮┃
┃╰╯╰┳╮╭┳━━┳━━┳━━╮┃╰━╯┣━━┳━━┳╮╭┳━┳━━┳┳╮╭┳━━╮
┃╭━╮┃┃┃┃━━┫╭━┫╭╮┃┃╭╮╭┫┃━┫╭━┫┃┃┃╭┫━━╋┫╰╯┃╭╮┃
┃╰━╯┃╰╯┣━━┃╰━┫╭╮┃┃┃┃╰┫┃━┫╰━┫╰╯┃┃┣━━┃┣╮╭┫╭╮┃
╰━━━┻━━┻━━┻━━┻╯╰╯╰╯╰━┻━━┻━━┻━━┻╯╰━━┻╯╰╯╰╯╰╯
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

int recursive_find(int low, int high, int size, int vector[size], int find){

    if (low > high) { 
        return -1;
    }

    int mid = (low+high) / 2;

    if (vector[mid] == find){
        return mid;
    } else if (vector[mid] < find) {
        return recursive_find(mid + 1, high, size, vector, find);
    } else {
        return recursive_find(low, mid - 1, size, vector, find);
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

    int low = 0;
    int high = size -1; //Index do ultimo
    
    for(int i=0; i<searches; i++){
        scanf("%d", &find);
        to_find[i] = find;
    }


    //Buscando a lista
    for(int i=0; i<searches; i++){
      printf("%d\n", recursive_find(low, high, size, vector, to_find[i]));
    }



    return 0;
}
