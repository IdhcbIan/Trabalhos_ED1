#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------------------------------------


void input(){
    char input[50];
    char numbers[16];
    char name[30];
    char age[3];
    char balance[30];
    int nI = 0;

    // Reading the whole line
    printf("Enter the input in the format '123.4, Ian Bezerra':\n");
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

    printf("%s\n", numbers);
    printf("%s\n", name);
    printf("%s\n", age);
    printf("%s\n", balance);

}



int main() {

    input();
    input();


    return 0;
}
