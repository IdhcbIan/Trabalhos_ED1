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
  List* N1 = create_list();
  List* N2 = create_list();
  char inp[10];

  int i = 0;
  while(inp[i]!=' '){
    scanf("%c", &inp[i]);
  }

  char c = 'u';
  while(c != ' '){
    scanf("%c", &c);
    if (c == ' ')  
        break;
    add_node(N1, c - '0');
  }

   c = 'u';
  while(c != '\n'){
    scanf("%c", &c);
    if (c == '\n')  
        break;
    add_node(N2, c - '0');
  }

  printf("O Primeiro Numero eh: ");
  display_element(N1);
  printf("\n");
  printf("O Segundo Numero eh: ");
  display_element(N2);


  return 0;
}




