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


//-------Definindo Funcoes -------------------------------

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

void display_element(List* L){
  Node* current = L->front;
  while (current){
    printf("%d", current->data);
    current = current->next;
  }
}

void add_linear(char num[], List* L) {
    int length = strlen(num);

    for(int i = 0; i < length; i++) {
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

int size(List* N1){
  Node* n1 = N1->front;
  int i = 0;

  while (n1){
    i++;
    n1 = n1->next;
  }
}

void free_list(List* L){
  Node* current = L->front;
  Node* next;
  
  while(current){
    next = current->next;
    free(current);
    current = next;
  }
  free(L);
}
//-------Problemas -------------------------------


//++++++++++++++Menor +++++++++++++
void menor(List* N1, List* N2){
  List* Nf = create_list();

  Node* n1 = N1->front;
  Node* n2 = N2->front;

  while (n1->data==0 || n2->data==0){
    if(n1->data==0){
      N1->front = n1->next;
      free(n1);
      n1 = N1->front;
    }
    if(n2->data==0){
      N2->front = n2->next;
      free(n2);
      n2 = N2->front;
    }
  }
  n1 = N1->front;
  n2 = N2->front;

  if (size(N1)>size(N2)){
    printf("False");
    n1 = NULL;
    n2 = NULL;
  }else if(size(N1)<size(N2)){
    printf("True");
    n1 = NULL;
    n2 = NULL;
  }

  while (n1 && n2){
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
}

//++++++++++++++Maior +++++++++++++
void maior(List* N1, List* N2){
  List* Nf = create_list();

  Node* n1 = N1->front;
  Node* n2 = N2->front;

  while (n1->data==0 || n2->data==0){
    if(n1->data==0){
      N1->front = n1->next;
      free(n1);
      n1 = N1->front;
    }
    if(n2->data==0){
      N2->front = n2->next;
      free(n2);
      n2 = N2->front;
    }
  }
  n1 = N1->front;
  n2 = N2->front;

  if (size(N1)>size(N2)){
    printf("True");
    n1 = NULL;
    n2 = NULL;
  }else if(size(N1)<size(N2)){
    printf("False");
    n1 = NULL;
    n2 = NULL;
  }

  while (n1 && n2){
    if (n1->data>n2->data){
      printf("True\n");
      break;
    }else if (n1->data<n2->data){
      printf("False\n");
      break;
    }else{
      n1 = n1->next;
      n2 = n2->next;
    }
  }
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

  //Remember to comment ou this part!!
  //printf("O Primeiro Numero eh: ");
  //display_element(N1);
  //printf("\n");

  //printf("O Segundo Numero eh: ");
  //display_element(N2);
  //printf("\n");

  if (strcmp(inp, "soma") == 0){
    //printf("A soma dos numeros eh: ");
    List* Nf = soma(N1, N2);
    display_element(Nf);
    free_list(Nf);
    free_list(N1);
    free_list(N2);
  }else if (strcmp(inp, "igual") == 0){
    igual(N1, N2);
    free_list(N1);
    free_list(N2);
  }else if (strcmp(inp, "maior") == 0){
    maior(N1, N2);
    free_list(N1);
    free_list(N2);
  }else if (strcmp(inp, "menor") == 0){
    menor(N1, N2);
    free_list(N1);
    free_list(N2);
  }
  return 0;
}




