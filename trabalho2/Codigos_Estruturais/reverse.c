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


void add(List* L, char num[]) {  
    int length = strlen(num);

    for(int i = length - 1; i >= 0; i--) {  
        char c = num[i];  
        add_node(L, c - '0'); 
    }
}

void display_element_reverse(Node* current) {
    if (current == NULL) {
        return;  
    }
    
    display_element_reverse(current->next);
    
    printf("%d", current->data);
}

void display_list_reverse(List* L) {
    display_element_reverse(L->front);
    printf("\n");
}



//------------Problemas -------------------------------------------------
// Como o Maximo que dois digitos pode ser eh 9
// Podemos considerar que toda vez que a soma de um dos nodes tenha 2 digitos, ent o digito da frente sera "1"

//------------Funcao Main------------------------------

int main(){
  List* N1 = create_list();
  char num1[] = "123456";
  add(N1, num1);
  printf("O Primeiro Numero eh: ");
  display_list_reverse(N1);


  List* N2 = create_list();
  char num2[] = "123456";
  add(N2, num2);
  printf("O Segundo Numero eh: ");
  display_list_reverse(N2);



  return 0;
}
