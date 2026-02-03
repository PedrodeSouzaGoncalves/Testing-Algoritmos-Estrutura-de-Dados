#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* buscarElemento(struct Node* head, int elemento){
    struct Node* current = head;

    while (current != NULL){
        if (current->data == elemento){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    int elementoBuscado = 2;
    struct Node* resultado = buscarElemento(head, elementoBuscado);

    if (resultado != NULL){
        printf("Elemento encontrado: %d\n", resultado->data);
    } else {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}