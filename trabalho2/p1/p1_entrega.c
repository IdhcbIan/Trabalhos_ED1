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
  printf("\n");
}

void add(char num[], List* L) {  
    int length = strlen(num);

    for(int i = length - 1; i >= 0; i--) {  
        char c = num[i];  
        add_node(L, c - '0'); 
    }
}

void display_element_reverse(Node* current) {
    if (current == NULL) {
        return;  // Base case: If node is NULL, return
    }
    
    // First, recurse to the end
    display_element_reverse(current->next);
    
    // Then, print the current node's data
    printf("%d", current->data);
}

void display_list_reverse(List* L) {
    display_element_reverse(L->front);
    printf("\n");
}
//-------Problemas -------------------------------
// Como o Maximo que dois dijitos pode ser eh 9
// Podemos considerar que toda vez que a soma de um dos nodes tenha 2 dijitos, ent o digito da frente sera "1"

List* soma(List* N1, List* N2){
  List* Nf = create_list();
  
  Node* n1 = N1->front; 
  Node* n2 = N2->front; 

  int i = 0;
  while (n1 && n2){
    int final = n1->data + n2->data;
    add_node(Nf, final);
    n1 = n1->next;
    n2 = n2->next;
    i++;
  }
  
  i = 0;
  while (n1){
    int final = n1->data;
    add_node(Nf, final);
    n1 = n1->next;
    i++;
  }

  i = 0;
  while (n2){
    int final = n2->data;
    add_node(Nf, final);
    n2 = n2->next;
    i++;
  }
  return Nf;
}


//-------Funcao Main------------------------------

int main(){
  List* N1 = create_list();
  char num1[] = "12345";
  add(num1, N1);
  printf("O Primeiro Numero eh: ");
  display_element(N1);


  List* N2 = create_list();
  char num2[] = "3333333333333333";
  add(num2, N2);
  printf("O Segundo Numero eh: ");
  display_element(N2);


  List* F = soma(N1,N2);
  display_list_reverse(F);

  return 0;
}




