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

void remove_zero(List* N){
  Node* n = N->front;

  while (n->data==0){
    if(n->data==0){
      N->front = n->next;
      free(n);
      n = N->front;
    }
  }
}

void display_element_reverse(Node* current) {
    if (current == NULL) {
        return;
    }

    display_element_reverse(current->next);

    printf("%d", current->data);
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

int size(List* N1) {
    Node* n1 = N1->front;
    int i = 0;

    while (n1) {
        i++;
        n1 = n1->next;
    }
      return i;               
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


//++++++++++++++Soma +++++++++++++
List* soma(List* N1, List* N2){
  List* Nf = create_list();

  N1 = invert_list(N1);
  N2 = invert_list(N2);

  Node* n1 = N1->front;
  Node* n2 = N2->front;

  int extra = 0;

  while (n1 || n2){

    if (n1 && n2){
      int final = n1->data + n2->data + extra;
      int digit = 0;
      if (final >= 10){
        digit = final % 10;
        extra = 1;
      }else{
        digit = final;
        extra = 0;
      }
      add_node(Nf, digit);
      n1 = n1->next;
      n2 = n2->next;
    }
    else if (n1){
      int final = n1->data + extra;
      extra = 0;
      add_node(Nf, final);
      n1 = n1->next;
    }
    else if (n2){
      int final = n2->data + extra;
      extra = 0;
      add_node(Nf, final);
      n2 = n2->next;
      }
    }
    if (!N1->front->next && !N2->front->next)
      add_node(Nf, extra);


  Nf = invert_list(Nf);

  remove_zero(Nf);

  return Nf;
}


//++++++++++++++Igual +++++++++++++
void igual(List* N1, List* N2){

  remove_zero(N1);
  remove_zero(N2);

  Node* n1 = N1->front;
  Node* n2 = N2->front;

  if (size(N1)!=size(N2)){
    printf("False");
    return;
  }

  int find = 0;
  while (n1 && n2){
    if (n1->data == n2->data){
      n1 = n1->next;
      n2 = n2->next;
      find = 1;
    }else{
      printf("False\n");
      find = 0;
      break;
    }
  }
  if(find==1){
      printf("True\n");
  }
}





//++++++++++++++Menor +++++++++++++
void menor(List* N1, List* N2){

  remove_zero(N1);
  remove_zero(N2);

  Node* n1 = N1->front;
  Node* n2 = N2->front;

  if (size(N1)>size(N2)){
    printf("False");
    n1 = NULL;
    n2 = NULL;
  }else if(size(N1)<size(N2)){
    printf("True");
    n1 = NULL;
    n2 = NULL;
  }

  int check = 0;
  while (n1 && n2){
    if (n1->data>n2->data){
      printf("False\n");
      check = 1;
      break;
    }else if (n1->data<n2->data){
      printf("True\n");
      check = 1;
      break;
    }else{
      n1 = n1->next;
      n2 = n2->next;
    }
  }
  if (check == 0){
    printf("False\n");
  }
}


//++++++++++++++Maior +++++++++++++
void maior(List* N1, List* N2){
 
  remove_zero(N1);
  remove_zero(N2);

  Node* n1 = N1->front;
  Node* n2 = N2->front;

  if (size(N1)>size(N2)){
    printf("True");
    n1 = NULL;
    n2 = NULL;
  }else if(size(N1)<size(N2)){
    printf("False");
    n1 = NULL;
    n2 = NULL;
  }
  
  int check = 0;
  while (n1 && n2){
    if (n1->data>n2->data){
      printf("True\n");
      check = 1;
      break;
    }else if (n1->data<n2->data){
      printf("False\n");
      check = 1;
      break;
    }else{
      n1 = n1->next;
      n2 = n2->next;
    }
  }
  if (check == 0){
    printf("False\n");
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
  while(scanf("%c", &c) != EOF) {
      if (c == '\n')
          break;
      add_node(N2, c - '0');
  }

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




