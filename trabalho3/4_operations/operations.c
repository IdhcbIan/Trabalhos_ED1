#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------- Structures -------------------------------------

typedef struct Node{
  
  char numbers[16];
  char name[30];
  char age[3];
  char balance[30];
  struct Node* Rig;
  struct Node* Lef;


}Node;


typedef struct Tree{
  struct Node* root;

}Tree;


//------------------------------------------------
Node* newNode(char numbers[16], char name[30], char age[3], char balance[30]){
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
  
    temp->numbers[0] = '\0';  // Initialize to empty string
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

Tree* newTree(Node* root){
  Tree* bonsai = (Tree*)malloc(sizeof(Tree));
  bonsai->root = root;


  return bonsai;
}
//------------------------------------------------


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
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
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

//------------------------------------------------

Node* insert(Node* groot, Node* add){
  if(groot == NULL){
    return add;
  }

  if (add->numbers > groot->numbers){
    groot->Rig = insert(groot->Rig, add);
  }else if(add->numbers < groot->numbers){
    groot->Lef = insert(groot->Lef, add);
  }

  return groot;
}

//----- Utility Functions -----

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

//------------------------------------------------

int main() {
  
    int times;
    scanf("%d", &times);
    Node* groot;

    for(int i=0;i<times;i++){
      if (i==0){
        Tree* T = newTree(input()); 
        Node* groot = T->root;
      }
      groot = insert(groot, input());
    }
    printf("Number is: %s\n", groot->numbers); 
    //printf("%s\n",N1->name);
    printTree(groot);

    return 0;
}
