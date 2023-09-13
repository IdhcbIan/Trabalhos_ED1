/*
██╗███╗░░██╗██╗░░░██╗███████╗██████╗░████████╗███████╗██████╗░
██║████╗░██║██║░░░██║██╔════╝██╔══██╗╚══██╔══╝██╔════╝██╔══██╗
██║██╔██╗██║╚██╗░██╔╝█████╗░░██████╔╝░░░██║░░░█████╗░░██████╔╝
██║██║╚████║░╚████╔╝░██╔══╝░░██╔══██╗░░░██║░░░██╔══╝░░██╔══██╗
██║██║░╚███║░░╚██╔╝░░███████╗██║░░██║░░░██║░░░███████╗██║░░██║
╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝

██╗░░░██╗███████╗████████╗░█████╗░██████╗░
██║░░░██║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗
╚██╗░██╔╝█████╗░░░░░██║░░░██║░░██║██████╔╝
░╚████╔╝░██╔══╝░░░░░██║░░░██║░░██║██╔══██╗
░░╚██╔╝░░███████╗░░░██║░░░╚█████╔╝██║░░██║
░░░╚═╝░░░╚══════╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝
*/
#include<stdio.h>

//Criando uma funcao que Printa um vetor(para visualisacao) //-----------
void vector_print(int v[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}



int main(){
    
    //Pegando tamanho
    int size;
    scanf("%d", &size);
    
    //Pegando vetor
    int vector[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }

    // Criando o Vetor invertido //-----------
    int inversed[size];
    int i = size-1;
    for(i;i>=0;i--){
      inversed[(size -1 - i)] = vector[i];
    }


    //Imprimindo um vetor(tirar para testar o tempor) //-----------
    vector_print(inversed, size); 
    
    return 0;
}
