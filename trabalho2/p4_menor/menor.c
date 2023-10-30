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

void add_linear(char num[], List* L) {  
    int length = strlen(num);

    for(int i = 0; i < length; i++) {
        char c = num[i];  
        add_node(L, c - '0'); 
    }
}

void add_reverse(List* L, char num[]) {  
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

List* invert_list(List* N1) {
    Node* prev = NULL;
    Node* current = N1->front;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    N1->front = prev;

    return N1;
}

//-------Problemas -------------------------------


//++++++++++++++Menor +++++++++++++
List* menor(List* N1, List* N2){
  List* Nf = create_list();
  
  Node* n1 = N1->front; 
  Node* n2 = N2->front; 

  
  while (n1 || n2){
    
    if (n1 && n2){
      if (n1->data>n2->data){
        printf("False\n");
        break;
      }else if (n1->data<n2->data){
        printf("True\n");
        break;
      }else{
        n1 = n1->next;
        n2 = n2->next;
      }
    }
    else if (n1&&!n2){  
      printf("False\n");
      break;
    }
    else if (n2&&!n1){  
      printf("True\n");
      break;
      }
    }

  return Nf;
}





//-------Funcao Main------------------------------

int main(){
  List* N1 = create_list();
  List* N2 = create_list();

  char inp[10];

  int i = 0;
  char c = 'u';
  while(c!=' '){
    scanf("%c", &c);
    if (c == ' ')  
        break;
    inp[i] = c;
    i++;
  }


  c = 'u';
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
  display_list_reverse(N1);

  printf("O Segundo Numero eh: ");
  display_list_reverse(N2);

  if (strcmp(inp, "maior") == 0){
    maior(N1, N2);
  }

  return 0;
}




