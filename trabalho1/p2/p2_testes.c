/*
╭━━╮╱╱╱╱╱╱╱╱╱╱╱╱╱╭━━━╮╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╭╮
┃╭╮┃╱╱╱╱╱╱╱╱╱╱╱╱╱┃╭━╮┃╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃
┃╰╯╰┳╮╭┳━━┳━━┳━━╮┃╰━━┳━━┳━━┳╮╭┳━━┳━╮╭━━┳┳━━┫┃
┃╭━╮┃┃┃┃━━┫╭━┫╭╮┃╰━━╮┃┃━┫╭╮┃┃┃┃┃━┫╭╮┫╭━╋┫╭╮┃┃
┃╰━╯┃╰╯┣━━┃╰━┫╭╮┃┃╰━╯┃┃━┫╰╯┃╰╯┃┃━┫┃┃┃╰━┫┃╭╮┃╰╮
╰━━━┻━━┻━━┻━━┻╯╰╯╰━━━┻━━┻━╮┣━━┻━━┻╯╰┻━━┻┻╯╰┻━╯
╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃
╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╰╯
*/
#include<stdio.h>
#include<stdbool.h>

// Function to print a vector for visualization
void vector_print(int size, int v[size]) {
    for(int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Defining the Vector
int vector[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// Function to find an element in the vector
void vector_find(int size, int v[size], int find_i) {
    bool did_y_find = false;
    for(int i = 0; i < size; i++) {
        if (v[i] == find_i) {
            did_y_find = true;
            break;  
        }
    }
  
    if (did_y_find) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
}

int main() {
    // Getting size of the vector
    int size = sizeof(vector) / sizeof(vector[0]); 

    // Reading the value to find
    int find;
    scanf("%d", &find);
  
    // Search for the value
    vector_find(size, vector, find);

    return 0;
}
