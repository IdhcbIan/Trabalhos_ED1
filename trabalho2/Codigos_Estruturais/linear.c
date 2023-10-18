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
  newNode->data = value;
  newNode->next = NULL;

  return newNode;
}

List* create_list(){
  List* L = malloc(sizeof(List));
  
  return L;
}

//-------Definindo Funcoes -------------------------------

void add_node(List* L, int value){
  if (L->front){
    Node* current = L->front; 
    while (current->next){
      current = current->next;
    }
    Node* new = create_node(value);
    current->next = new;
  }else{
  L->front = create_node(value);
  }
}

void display_element(List* L){
  Node* current = L->front; 
  int i = 0;
  while (current){
    printf("%d", current->data);
    current = current->next;
    i++;
  }
}

void add(char num[], List* L) {  
    int length = strlen(num);

    for(int i = 0; i < length; i++) {
        char c = num[i];  
        add_node(L, c - '0'); 
    }
}

//-------Problemas -------------------------------



//-------Funcao Main------------------------------

int main(){
  List* L = create_list();
  char num[] = "22222222222222222222222222222222";
  add(num, L);
  display_element(L);

  return 0;
}




