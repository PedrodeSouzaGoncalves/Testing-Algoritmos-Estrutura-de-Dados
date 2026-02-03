/*Bibliotecas para serem usadas no códgio, inclusão de stdlib.h para poder manipular memória e string.h para manipular strings*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estrutura tarefa, contém inteiro para o identificador único e uma array de char para descrição além de outra estrutura que aponta para outro nó*/
struct tarefa{
  int IU;
  char descricao[100];
  struct tarefa* next;
};

// Função para criar um novo nó
struct tarefa* newNode(int IU, char* descricao){
    struct tarefa* temp = (struct tarefa*)malloc(sizeof(struct tarefa));
    if (temp == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    temp->IU = IU; // atribui o identificador
    strncpy(temp -> descricao, descricao, sizeof(temp->descricao)-1);
    temp->descricao[sizeof(temp->descricao)-1] = '\0';
    temp->next = NULL; // novo nó não aponta para ninguém inicialmente
    return temp;
}

// Função para adicionar no final da lista
struct tarefa* addNodeEnd(struct tarefa* head, int IU, char* descricao) {
    struct tarefa* novo = newNode(IU, descricao);
    
    // Caso a lista esteja vazia, o novo nó vira a cabeça
    if (head == NULL) {
        return novo;
    }
    
    // Senão, percorre até o último nó
    struct tarefa* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Último nó passa a apontar para o novo
    temp->next = novo;
    return head;
}

// Função para imprimir os elementos da lista
void printList(struct tarefa* head){
    if(head == NULL){
        printf("A lista está vazia.\n");
        return;
    }
    printf("Lista de tarefas: \n");
    struct tarefa* temp = head;
    while(temp != NULL){
        printf("IU: %d | Descrição: %s\n", temp->IU, temp->descricao);
        temp = temp->next; // avança para o próximo nó
    }
}

/*Função para remover um nó*/
struct tarefa* removeNode(struct tarefa* head, int IU) {
    struct tarefa* temp = head;
    struct tarefa* prev = NULL;

    if (temp != NULL && temp->IU == IU) {
        head = temp->next;  // atualiza cabeça da lista
        free(temp);        // libera memória do nó removido  
        return head;
    }

    // Percorre até encontrar o nó desejado ou chegar no fim
    while (temp != NULL && temp->IU != IU) {
        prev = temp;
        temp = temp->next;
    }

    // Se não encontrou o nó
    if (temp == NULL) {
        printf("Nó com IU %d nao encontrado.\n", IU);
        return head;
    }

    // Desvincula o nó da lista e libera memória
    prev->next = temp->next;
    free(temp);
    return head;
}

// Libera toda a memória da lista
void freeList(struct tarefa* head){
    struct tarefa* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    // Declarando o struct para poder usá-lo
    struct tarefa* head = NULL;

    // Inserindo tarefas
    head = addNodeEnd (head, 1, "Primeira tarefa");
    head = addNodeEnd(head, 2, "Segunda tarefa");
    head = addNodeEnd(head, 3, "Terceira tarefa");

    //Mostrar a lista
    printList(head);

    // Removendo uma tarefa
    printf("\nRemovendo a tarefa de IU = 2...\n");
    head = removeNode(head, 2);

    // Mostrar a lista de novo
    printList(head);

    // Libera memória ao final
    freeList(head);

    return 0;
}