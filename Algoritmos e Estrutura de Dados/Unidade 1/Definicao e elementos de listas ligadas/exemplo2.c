#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Linked_List{
    struct Node* head;
};

int main (){
    struct Linked_List my_list;
    my_list.head = (struct Node*)malloc(sizeof(struct Node));
    my_list.head -> next = NULL;

    // Inserção de elementos
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = 42;
    newNode -> next = my_list.head -> next;
    my_list.head -> next = newNode;

    // Remoção de elementos
    struct Node* temp = my_list.head -> next;
    my_list.head -> next = temp -> next;
    free(temp);

    return 0;
}