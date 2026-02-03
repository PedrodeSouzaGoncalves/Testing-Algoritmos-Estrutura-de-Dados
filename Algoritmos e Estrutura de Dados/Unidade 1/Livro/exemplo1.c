#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

struct alunos{
    char nome[25];
    struct aluno* prox;
};

typedef struct alunos Classe;

int main()
{

    char *pnt;
    pnt = malloc(2);
    printf("Digite algo: \n");
    scanf("%c",&pnt);
    printf("Foi isso que foi digitado %c", pnt);

    return 0;
}