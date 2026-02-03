#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tarefa {
    int IU;
    char descricao[100];
    struct tarefa* next;
};

/* Protótipos */
struct tarefa* newNode(int IU, char* descricao);
struct tarefa* addNodeEnd(struct tarefa* head, int IU, char* descricao);
void printList(struct tarefa* head);
struct tarefa* removeNode(struct tarefa* head, int IU);
void freeList(struct tarefa* head);

/* Definições das funções */
struct tarefa* newNode(int IU, char* descricao) {
    struct tarefa* temp = (struct tarefa*)malloc(sizeof(struct tarefa));
    if (temp == NULL) {
        fprintf(stderr, "Erro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }
    temp->IU = IU;
    strncpy(temp->descricao, descricao, sizeof(temp->descricao)-1);
    temp->descricao[sizeof(temp->descricao)-1] = '\0';
    temp->next = NULL;
    return temp;
}

struct tarefa* addNodeEnd(struct tarefa* head, int IU, char* descricao) {
    struct tarefa* novo = newNode(IU, descricao);
    if (head == NULL) return novo;
    struct tarefa* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = novo;
    return head;
}

void printList(struct tarefa* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("Lista de tarefas:\n");
    struct tarefa* temp = head;
    while (temp != NULL) {
        printf("IU: %d | Descrição: %s\n", temp->IU, temp->descricao);
        temp = temp->next;
    }
}

struct tarefa* removeNode(struct tarefa* head, int IU) {
    struct tarefa* temp = head;
    struct tarefa* prev = NULL;

    if (temp != NULL && temp->IU == IU) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->IU != IU) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Nó com IU %d não encontrado.\n", IU);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

void freeList(struct tarefa* head) {
    struct tarefa* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    struct tarefa* head = NULL;

    head = addNodeEnd(head, 1, "Primeira tarefa");
    head = addNodeEnd(head, 2, "Segunda tarefa");
    head = addNodeEnd(head, 3, "Terceira tarefa");

    printList(head);

    printf("\nRemovendo a tarefa IU = 2...\n");
    head = removeNode(head, 2);

    printList(head);

    freeList(head);
    return 0;
}