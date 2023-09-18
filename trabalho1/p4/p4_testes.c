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

// Defining the Vector
int vector[10] = {0,1,2,3,4,5,6,7,8,9};


int main() {
    // Getting size of the vector
    int size = sizeof(vector) / sizeof(vector[0]); 
    

    //Pegando pesquisas
    int find = 999991;

    int low = 0;
    int high = size -1; //Index do ultimo
    


    //Buscando a lista
    printf("%d\n", recursive_find(low, high, size, vector, find));



    return 0;
}
