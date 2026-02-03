#include <stdio.h>

// Criando struct para ser usado como lista

typedef struct node
{
    int valor;
    struct node *prox;
}Node;

// Inserção no início da lista

void inserir_no_inicio(Node **lista, int num)
{
    Node *novo = malloc(sizeof(Node));

    if(novo){
        novo -> valor = num;
        novo -> prox = *lista;
        *lista = novo;
    } else{
        printf("Erro ao alocar memória\n");
    }
}

// Inserção no final da lista

void inserir_no_fim(Node **lista, int num){
    Node *aux, *novo = malloc(sizeof(Node));

    if(novo){
        novo -> valor = num;
        novo -> prox = NULL;

        // é o primeiro?
        if(*lista==NULL)
            *lista= novo;
        else {
            aux = *lista;
            while(aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        }
    } else
    printf("Erro ao alocar memória!\n");
}


int main()
{





    return 0;
}