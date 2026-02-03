#include <stdio.h>
#include <stdlib.h>

/*Tabela Hash linear com vetor*/

// Vamos trabalhar com uma tabela de 15 elementos, seguindo a fórmula
// 2*15 = 30, número primos próximos, 29 e 31. Usaremos o 31

#define TAM 31

typedef struct no{
    int chave;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inicializarlista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inicializar_tabela(int t[]){
    int i;
    for (i = 0; i < TAM; i++)
        t[i] = 0;
}

int funcao_hash(int chave){
    return chave % TAM;
}

void inserir_elemento(int t[], int valor){
    int id = funcao_hash(valor);
    while(t[id] != 0){
        id = funcao_hash(id+1);
    }
    t[id] = valor;
}

int buscar_elemento(int t[], int chave){
    int id = funcao_hash(chave);
    printf("\nChave gerada: %d\n", id);
    while(t[id] != 0){
        if(t[id] == chave)
            return t[id];
        else
            id = funcao_hash(id +1);
    }
    return 0;
}

void imprimir_tabela(int t[]){
    int i;
    for (i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main()
{
    int opcao, valor, retorno, tabela[TAM];

    inicializar_tabela(tabela);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao){
        case 1:
            printf("\tQual valor deseja inserir?");
            scanf("%d", &valor);
            inserir_elemento(tabela, valor);
            break;
        case 2:
            printf("\tQual valor deseja buscar?");
            scanf("%d", &valor);
            retorno = buscar_elemento(tabela, valor);
            if (retorno != 0)
                printf("\tValor encontrado: %d\n", retorno);
            else
                printf("\tValor não encontrado!\n");
            break;
        case 3:
            printf("Todos os valores da tabela:\n");
            imprimir_tabela(tabela);
            break;
        default:
            printf("Saindo do programa!\n");
        }

    }while(opcao != 0);

    return 0;
}