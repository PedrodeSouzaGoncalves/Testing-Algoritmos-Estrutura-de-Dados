#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nó da lista
struct Cliente{
    char* nome;
    char placa[15];
    int servico; // 1 = alinhamento, 2 = balanceamento
    struct Cliente* prox;
};

// Função para adicionar novo nó
struct Cliente* newCliente(char* nome, char* placa, int servico){
    struct Cliente* temp = (struct Cliente*)malloc(sizeof(struct Cliente));
    temp->nome = strdup(nome);
    strcpy(temp -> placa, placa);
    temp -> servico = servico;
    temp->prox = NULL;
    return temp;
}

// Função para imprimir 
void print_list(struct Cliente* cliente){
    while (cliente != NULL){
        printf("%s, %s, %d ", cliente->nome, cliente->placa, cliente->servico );
        cliente = cliente->prox;
    }
    printf("NULL\n");
}

int main(){
    struct Cliente* primeiro = NULL;
    struct Cliente* segundo = NULL;
    struct Cliente* terceiro = NULL;

    primeiro = newCliente("Pedro", "Testing", 1);
    segundo = newCliente("Thais", "Princess", 0);
    terceiro = newCliente("Chesira", "Dona", 1);

    primeiro -> prox = segundo;
    segundo -> prox = terceiro;

    print_list(primeiro);

    return 0;
}