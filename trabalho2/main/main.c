#include<stdio.c>

// Definindo estruturas

typedef struct Node{
  int data;
  struct Node* next;

}Node;


typedef struct List{
  Node* front;  

}List;

// Definindo funcoes

Node* create_node(int value){
  Node* newNode = malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

List* create_list(int value){
  List* L = malloc(sizeof(List));
  L->front = create_node(value);
  
  return L;
}

// Definindo Funcoes

void add_node(List* L, int value){
  Node* current = L->front; 
  while (current->next){
    current = current->next;
  }
  Node* new = create_node(value);
  current->next = new;
}


//-------Funcao Main-------------------


int main(){




  return 0;
}




