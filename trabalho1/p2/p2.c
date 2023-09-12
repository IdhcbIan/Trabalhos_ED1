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

//Criando uma funcao que Printa um vetor(para visualisacao) //-----------
void vector_print(int v[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Definindo o Vetor //-----------
int vector[(10)] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 


int main(){
    
    //Descobrindo Tamanho do Vetor //-----------
    int size = sizeof(vector) / sizeof(vector[0]); 
    int i = size-1;
    
    return 0;
}
