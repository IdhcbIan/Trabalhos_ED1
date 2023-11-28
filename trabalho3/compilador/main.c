#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//++++++++++++++Criando estruturas++++++++++++++
//Nó
typedef struct Node{
  char numbers[16]; //CPF
  char name[30]; //Nome
  char age[3]; //Idade
  char balance[30];  //Saldo da conta
  struct Node* Rig; //Ponteiro para subárvore da direita
  struct Node* Lef; //Ponteiro para subárvore da esquerda

}Node;


//Árvore
typedef struct Tree{
  struct Node* root; //Ponteiro para nó raiz

}Tree;


//++++++++++++++Funções Elementares++++++++++++++
//Criando um nó
Node* newNode(char numbers[16], char name[30], char age[3], char balance[30]){
	//Alocação dinâmica e verificação
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        return NULL;
    }
  
	//Atribui NULL para todas os campos do nó que está sendo criado 
    temp->numbers[0] = '\0';
    temp->name[0] = '\0';
    temp->age[0] = '\0';
    temp->balance[0] = '\0';

	//Concatena os campos do nó com os parâmetros (dados que foram digitados)
    strcat(temp->numbers, numbers);
    strcat(temp->name, name);
    strcat(temp->age, age);
    strcat(temp->balance, balance);

	//Atribui NULL para os ponteiros do novo nó
    temp->Rig = NULL;
    temp->Lef = NULL;

    return temp;
}

//Criando uma árvore
Tree* newTree(Node* groot){
	//Alocação dinâmica e verificação
	Tree* bonsai = (Tree*)malloc(sizeof(Tree));
	if (bonsai == NULL) {
		return NULL;
	}
	//O nó raiz da árvore será o primeiro nó digitado
	bonsai->root = groot;


  return bonsai;
}


//++++++++++++++Funções Auxiliares++++++++++++++
//Recolhe uma linha; função usada nas operações que precisa localizar o CPF (busca e remoção)
char* line() {
    char input[100];
    char *numbers;
    int nI = 0;
    
    //Lê a linha inteira
    fgets(input, sizeof(input), stdin);

	//Alocação dinâmica e verificação
    numbers = (char *)malloc(16 * sizeof(char));
    if (numbers == NULL) {
		return NULL;
	}

    //Pegar os apenas números do CPF (variável numbers)
    int i = 0;
	//Condições de parada: encontrar a vírgula que separa o CPF do nome, chegar no NULL ou tamanho do vetor ultrapassar 14 que é o número máximo de caracteres de um CPF
    while (input[i] != ',' && input[i] != '\0' && nI < 15) {
        if ((input[i] >= '0' && input[i] <= '9')) {
            numbers[nI++] = input[i];
        }
        i++;
    }
    numbers[nI] = '\0';

    return numbers;
}

//Recolhe o input
Node* input() {
    char input[100];
    char numbers[16] = {0}; 
    char name[30] = {0};
    char age[3] = {0};
    char balance[30] = {0};
    int nI = 0;

    //Lê a linha inteira
    fgets(input, sizeof(input), stdin);

    //Pegar os apenas números do CPF (variável numbers), mesmo funcionamento da função line
    int i = 0;
    while (input[i] != ',' && input[i] != '\0') {
        if ((input[i] >= '0' && input[i] <= '9')) {
            numbers[nI++] = input[i];
        }
        i++;
    }
    numbers[nI] = '\0';

	//Ajuste das variáveis locais para percorrer a string na primeira letra do nome
    i += 2; 
    nI = 0;

    //Pegar o nome; condições de parada: chegar na vírgula ou em NULL
    while (input[i] != ',' && input[i] != '\0') {
        name[nI++] = input[i];
        i++;
    }
    name[nI] = '\0';

	//Ajuste das variáveis locais para percorrer a string no primeiro dígito da idade
    i += 2; 
    nI = 0;

    //Pegar a idade; condições de parada: chegar na vírgula ou em NULL
    while (input[i] != ',' && input[i] != '\0') {
        age[nI++] = input[i];
        i++;
    }
    age[nI] = '\0';
	
	//Ajuste das variáveis locais para percorrer a string no primeiro dígito do saldo
    i += 2; 
    nI = 0;

    //Pegar o saldo; condições de parada: chegar em NULL ou quebra de linha
    while (input[i] != '\0' && input[i] != '\n') {
        balance[nI++] = input[i];
        i++;
    }
    balance[nI] = '\0';
	//Retorna chamando a função que cria o nó passando as informações recolhidas acima como argumentos
    return newNode(numbers, name, age, balance);
}

//Imprime os nós formatados
void print_node(Node* groot){
	//Se recebermos NULL como parâmetro, significa que não tem o CPF no banco de dados
    if (groot == NULL) {
        printf("Pessoa nao encontrada\n");
        return;
    }
	
	//Imprime o CPF, incluindo os pontos e traço
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

	//Imprime os outros campos da struct
    printf(", %s, ", groot->name);
    printf("%s, ", groot->age);
    printf("%s\n", groot->balance);
}

//Imprime a lista na travessia PreOrdem 
void preOrder(Node* groot){
	if (groot==NULL){
		return;
	}
	print_node(groot);
	preOrder(groot->Lef);
	preOrder(groot->Rig);
}

//Imprime a lista na travessia EmOrdem 
void inOrder(Node* groot){
	if (groot==NULL){
		return;
	}
	inOrder(groot->Lef);
	print_node(groot);
	inOrder(groot->Rig);
}

//Insere nós recursivamente
Node* insert(Node* groot, Node* add){
	if(groot == NULL){
		return add;
	}

	//Compara strings usando strcmp e adiciona o nó de forma ordenada na árvore
	if (strcmp(add->numbers, groot->numbers) > 0){
		groot->Rig = insert(groot->Rig, add);
	}else if (strcmp(add->numbers, groot->numbers) < 0){
		groot->Lef = insert(groot->Lef, add);
	}
	return groot;
}

//Desaloca
void deleteTree(Node* groot) {
    if (groot == NULL) {
        return;
    }
	//Percorre a árvore em travessia PosOrdem para desalocar
    deleteTree(groot->Lef);
    deleteTree(groot->Rig);
    free(groot);
}


//++++++++++++++Operações++++++++++++++
//Busca
Node* busca(Node* groot, char num[16]){
  
	if (groot == NULL){
		return groot;
	//Se o CPF buscado e o CPF do nó raiz forem iguais, o nó procurado é o raiz
	}else if (strcmp(num, groot->numbers) == 0){
		return groot;
	}

	//Se o CPF procurado for maior que o da raiz, procura na subárvore da direita
	if (strcmp(num, groot->numbers) > 0){
		return busca(groot->Rig, num);
	//Se o CPF procurado for menor que o da raiz, procura na subárvore da esquerda
	}else if (strcmp(num, groot->numbers) < 0){
		return busca(groot->Lef, num);
	}
	//Se o CPF não for encontrado, retorna NULL
	return NULL;
}

//Remoção para caso o nó tenha dois filhos
Node* findPred(Node* groot) {
    Node* current = groot->Lef;
    while (current && current->Rig != NULL)
        current = current->Rig;
    return current;
}

//Remoção
Node* remove_node(Node* groot, char num[16]) {
	if (groot == NULL)
		return groot;

	//Buscando o nó na árvore ordenada
	if (strcmp(num, groot->numbers) < 0)
		groot->Lef = remove_node(groot->Lef, num);
	else if (strcmp(num, groot->numbers) > 0)
		groot->Rig = remove_node(groot->Rig, num);
	//Quando encontrar o nó procurado
	else {
		//Caso 1: um nó filho
		if (groot->Lef == NULL) {
			Node* temp = groot->Rig;
			free(groot);
			return temp;
		}else if (groot->Rig == NULL) {
			Node* temp = groot->Lef;
			free(groot);
			return temp;
		}

		//Caso 2: dois nós filhos
		Node* temp = findPred(groot);
		//Copia os campos do nó temp para o nó raiz
		strcpy(groot->numbers, temp->numbers);
		strcpy(groot->name, temp->name);
		strcpy(groot->age, temp->age);
		strcpy(groot->balance, temp->balance);
		groot->Lef = remove_node(groot->Lef, temp->numbers);
    }
	return groot;
}


//++++++++++++++Função Main++++++++++++++
int main() {
	//Recebe o número de pessoas que serão cadastradas 
	int times;
	scanf("%d\n", &times);
	Node* groot = NULL;
	Node* add = NULL;
	Tree* T = NULL;

	//Recebe os dados de todas as pessoas
	for(int i=0;i<times;i++){
		//Se for a primeira pessoa, precisa receber o input, criar o nó e a árvore usando esse nó como raiz
		if (i==0){
			add = input();
			groot = insert(groot, add);
			Tree* T = newTree(groot); 
			groot = T->root;
		//Caso contrário, só precisa receber o input e adicionar na árvore
		}else{
			add = input();
			groot = insert(groot, add);
		}
	}
	
	//Lê a operação digitada
	char operation;
	scanf("%c\n", &operation);

	//Realiza a operação escolhida 
	if (operation == 'B'){char *num = line();
      Node* find = busca(groot, num);
	  if (find==NULL){
	  }
	  print_node(find);
	}else if (operation == 'I'){
		add = input();
		groot = insert(groot, add);
		preOrder(groot);
	}else if (operation == 'R'){
		char *num = line();
		groot = remove_node(groot, num);
		preOrder(groot);
	}
	//Libera a memória
	deleteTree(groot);
	free(T);
	return 0;
}