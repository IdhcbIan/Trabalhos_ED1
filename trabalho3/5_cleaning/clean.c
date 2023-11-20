#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------// Criando estruturas //------------------------------------------------------------------------

//++++  No +++++++++++++++++++++++++
typedef struct Node{
  char numbers[16];
  char name[30];
  char age[3];
  char balance[30];
  struct Node* Rig;
  struct Node* Lef;

}Node;


//++++  arvore +++++++++++++++++++++++++
typedef struct Tree{
  struct Node* root;

}Tree;


//------------------// Funcoes elementares //------------------------------------------------------------------------

//++++  Criando um no +++++++++++++++++++++++++
Node* newNode(char numbers[16], char name[30], char age[3], char balance[30]){
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        return NULL;
    }
  
    temp->numbers[0] = '\0';
    temp->name[0] = '\0';
    temp->age[0] = '\0';
    temp->balance[0] = '\0';

    strcat(temp->numbers, numbers);
    strcat(temp->name, name);
    strcat(temp->age, age);
    strcat(temp->balance, balance);

    temp->Rig = NULL;
    temp->Lef = NULL;

    return temp;
}

//++++  Criando uma arvore +++++++++++++++++++++++++
Tree* newTree(Node* root){
  Tree* bonsai = (Tree*)malloc(sizeof(Tree));
  bonsai->root = root;


  return bonsai;
}
//------------------// Funcoes //------------------------------------------------------------------------


//++++  Recolhe uma linha +++++++++++++++++++++++++
char* line() {
    char input[100];
    char *numbers;
    int nI = 0;
    
    // Reading the whole line
    fgets(input, sizeof(input), stdin);

    // Allocate memory for numbers dynamically
    numbers = (char *)malloc(16 * sizeof(char));
    if (numbers == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Getting numbers
    int i = 0;
    while (input[i] != ',' && input[i] != '\0' && nI < 15) {
        if ((input[i] >= '0' && input[i] <= '9')) {
            numbers[nI++] = input[i];
        }
        i++;
    }
    numbers[nI] = '\0';

    return numbers;
}

//++++  Recolhe input +++++++++++++++++++++++++
Node* input() {
    char input[100];
    char numbers[16] = {0}; 
    char name[30] = {0};
    char age[3] = {0};
    char balance[30] = {0};
    int nI = 0;

    // Reading the whole line
    fgets(input, sizeof(input), stdin);

    // Getting numbers
    int i = 0;
    while (input[i] != ',' && input[i] != '\0') {
        if ((input[i] >= '0' && input[i] <= '9')) {
            numbers[nI++] = input[i];
        }
        i++;
    }
    numbers[nI] = '\0';

    i += 2; 
    nI = 0;

    // Getting name
    while (input[i] != ',' && input[i] != '\0') {
        name[nI++] = input[i];
        i++;
    }
    name[nI] = '\0';

    i += 2; 
    nI = 0;

    // Getting age
    while (input[i] != ',' && input[i] != '\0') {
        age[nI++] = input[i];
        i++;
    }
    age[nI] = '\0';

    i += 2; 
    nI = 0;

    // Getting balance
    while (input[i] != '\0' && input[i] != '\n') {
        balance[nI++] = input[i];
        i++;
    }
    balance[nI] = '\0';

    return newNode(numbers, name, age, balance);
}


//++++  Busca um no +++++++++++++++++++++++++
Node* busca(Node* groot, char num[16]){
  
  if (strcmp(num, groot->numbers) == 0){
    return groot;
  } 

  if (strcmp(num, groot->numbers) > 0){
    return busca(groot->Rig, num);
  } else if (strcmp(num, groot->numbers) < 0){
    return busca(groot->Lef, num);
  }

}


//++++  Imprime Nos formatand-os +++++++++++++++++++++++++
void print_node(Node* groot){
    if (groot == NULL) {
        printf("Node is NULL\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        printf("%c", groot->numbers[i]);
    }
    printf(".");
    for (int i = 3; i < 6; i++) {
        printf("%c", groot->numbers[i]);
    }
    printf(".");
    for (int i = 6; i < 9; i++) {
        printf("%c", groot->numbers[i]);
    }
    printf("-");
    for (int i = 9; i < 11; i++) {
        printf("%c", groot->numbers[i]);
    }

    // Print other details
    printf(", %s, ", groot->name);
    printf("%s, ", groot->age);
    printf("%s\n", groot->balance);
}

//++++  Imprime a lista em ordem +++++++++++++++++++++++++
void inOrder(Node* groot){
  if (groot==NULL){
    return;
  }

  inOrder(groot->Lef);
  print_node(groot);
  inOrder(groot->Rig);
  
}
//++++  Insere nos recursivamente em seu lugar +++++++++++++++++++++++++
Node* insert(Node* groot, Node* add){
  if(groot == NULL){
    return add;
  }

  // Compare strings using strcmp
  if (strcmp(add->numbers, groot->numbers) > 0){
    groot->Rig = insert(groot->Rig, add);
  } else if (strcmp(add->numbers, groot->numbers) < 0){
    groot->Lef = insert(groot->Lef, add);
  }

  return groot;
}

//------------------// Provisorio //------------------------------------------------------------------------

void printTreeUtil(Node* root, int space, int depth) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += depth;

    // Process right child first
    printTreeUtil(root->Rig, space, depth);

    // Print current node after space count
    printf("\n");
    for (int i = depth; i < space; i++)
        printf(" ");
    printf("%s\n", root->numbers);

    // Process left child
    printTreeUtil(root->Lef, space, depth);
}

// Wrapper over printTreeUtil()
void printTree(Node* root) {
    // Initial space is 0
    printTreeUtil(root, 0, 10);  // depth can be adjusted for the width of the tree
}



//------------------// Funcao Main //------------------------------------------------------------------------

int main() {
  
    int times;
    scanf("%d\n", &times);
    Node* groot = NULL;
    Node* add = NULL;

    for(int i=0;i<times;i++){
      if (i==0){
        add = input();
        groot = insert(groot, add);
        Tree* T = newTree(groot); 
        groot = T->root;

      }else{
        add = input();
        groot = insert(groot, add);

      }
    }

    char operation;
    scanf("%c\n", &operation);

    if (operation == 'B'){
    char *num = line();
    Node* find = busca(groot, num);
    print_node(find);
    } else if (operation == 'I'){
        add = input();
        groot = insert(groot, add);
        inOrder(groot);
    } 

    return 0;
}
