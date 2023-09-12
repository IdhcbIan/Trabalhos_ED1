/*
╭━━╮╱╱╱╱╱╱╱╱╱╱╱╱╱╭━━━╮╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╭╮
┃╭╮┃╱╱╱╱╱╱╱╱╱╱╱╱╱┃╭━╮┃╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃
┃╰╯╰┳╮╭┳━━┳━━┳━━╮┃╰━━┳━━┳━━┳╮╭┳━━┳━╮╭━━┳┳━━┫┃
┃╭━╮┃┃┃┃━━┫╭━┫╭╮┃╰━━╮┃┃━┫╭╮┃┃┃┃┃━┫╭╮┫╭━╋┫╭╮┃┃
┃╰━╯┃╰╯┣━━┃╰━┫╭╮┃┃╰━╯┃┃━┫╰╯┃╰╯┃┃━┫┃┃┃╰━┫┃╭╮┃╰╮
╰━━━┻━━┻━━┻━━┻╯╰╯╰━━━┻━━┻━╮┣━━┻━━┻╯╰┻━━┻┻╯╰┻━╯
╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃
╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╰╯
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
void vector_find(int size, int v[size], int find) {
  bool did_y_find = false;
    for(int i = 0; i < size; i++) {
        if (v[i] == find){
        did_y_find = true;
        break;
        }

    }
  if (did_y_find == true){
    printf("SIM\n");
  }else {
    printf("NAO\n");
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
      vector_find(size, vector, to_find[i]);
    }




    return 0;
}
