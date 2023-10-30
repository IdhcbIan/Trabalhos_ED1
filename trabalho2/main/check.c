#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------Definindo Estruturas -------------------------------

typedef struct Node{
  int data;
  struct Node* next;

}Node;


typedef struct List{
  Node* front;

}List;


Node* create_node(int value){
  Node* newNode = malloc(sizeof(Node));
  if (!newNode) {
    perror("Failed to allocate memory for node");
    exit(EXIT_FAILURE);
  }
  
  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

List* create_list(){
  List* L = malloc(sizeof(List));
  if (!L) {
    perror("Failed to allocate memory for list");
    exit(EXIT_FAILURE);
  }
  L->front = NULL;

  return L;
}


//---------------------------------------------------------------
void add_node(List* L, int value){
  if (L->front){
         //percorremos, com o ponteiro "current", toda a lista, até que aponte para o ultimo elemento
    Node* current = L->front;
    while (current->next){
      current = current->next;
    }
    Node* new = create_node(value);//adicionamos um novo nó como ultimo elemento
    current->next = new;
  }else{
 //caso a lista esteja vazia, apenas adicionamos um novo nó e setamos o ponteiro
  L->front = create_node(value);
  }
}


int main(){
  List* L = create_list();


  add_node(L, 1);
  add_node(L, 2);
  add_node(L, 3);



  return 0;
}




