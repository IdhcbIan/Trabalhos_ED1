#include <stdio.h>
#include <stdlib.h>

//-------// Criando a lista //---------------

typedef struct Node{
  int data;
  struct Node* next;

}Node;

typedef struct List{
  Node* front;  

}List;

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

void add_node(List* L, int value){
  Node* current = L->front; 
  while (current->next){
    current = current->next;
  }
  Node* new = create_node(value);
  current->next = new;
}

//-------// Problemas //---------------

//Questao 1
void display_list(List* L){
  Node* current = L->front; 
  while (current){
    printf("%d\n", current->data);
    current = current->next;
  }

}

//Questao 3
void display_element(List* L, int key){
  Node* current = L->front; 
  int i = 0;
  while (i < key){
    current = current->next;
    i++;
  }
  printf("%d\n", current->data);
}

//Questao 3
void display_element(List* L, int key){
  Node* current = L->front; 
  int i = 0;
  while (i < key){
    current = current->next;
    i++;
  }
  printf("%d\n", current->data);
}

//---------------------------------------

int main(){
  List* L = create_list(2);
  add_node(L, 3);
  add_node(L, 4);
  display_element(L, 1);

  return 0;
}
