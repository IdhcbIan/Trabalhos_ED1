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
  strcat(temp->numbers, numbers);
  strcat(temp->name, name);
  strcat(temp->age, age);
  strcat(temp->balance, balance);

  return temp;
}

Tree* newTree(Node* root){
  Tree* bonsai = (Tree*)malloc(sizeof(Tree));
  bonsai->root = root;


  return bonsai;
}
//------------------------------------------------


Node* input(){
    char input[50];
    char numbers[16];
    char name[30];
    char age[3];
    char balance[30];
    int nI = 0;

    // Reading the whole line
    fgets(input, 50, stdin); 

    // Getting name
    int i = 0; 
    for (i; input[i] != ','; i++) {
        if (input[i] >= '0' && input[i] <= '9') { 
            numbers[nI++] = input[i];
        }
    }
    numbers[nI] = '\0';

    i += 2; 
    nI = 0;

    // Getting name
    for (i; input[i] != ','; i++) { 
        name[nI++] = input[i];
    } 
    name[nI] = '\0'; 

    i += 2; 
    nI = 0;

    // Getting age
    for (i; input[i] != ','; i++) { 
        age[nI++] = input[i];
    }
    age[nI] = '\0'; 

    i += 2; 
    nI = 0;

    // Getting balance
    for (i; input[i] != '\0' && input[i] != '\n'; i++) { 
        balance[nI++] = input[i];
    }

    Node* temp = newNode( numbers, name, age, balance);
    return temp;
}



int main() {

    Node* N1 = input();
    
    printf("%s\n",N1->name);

    return 0;
}
