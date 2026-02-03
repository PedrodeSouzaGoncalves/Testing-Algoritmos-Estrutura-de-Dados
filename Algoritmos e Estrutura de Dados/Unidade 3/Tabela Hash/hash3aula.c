#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 10

struct Elemento{
    char chave[50];
    char valor[50];
};

struct Elemento* criar_tabela_hash(){
    struct Elemento* tabela = (struct Elemento*)malloc(TAMANHO * sizeof(struct Elemento));
    for (int i =0; i < TAMANHO; i++){
        strcpy(tabela[i].chave, "");
        strcpy(tabela[i].valor, "");
    }
    return tabela;
}

int calcular_hash(char* chave){
    int hash = 0;
    for (int i = 0; i < strlen(chave); i++){
        hash += chave[i];
    }
    return hash % TAMANHO;
}

void inserir_elemenot_hash(struct Elemento* tabela, char* chave, char* valor){
    int indice = calcular_hash(chave);
    while (strcmp(tabela[indice].chave, "") != 0){
        indice = (indice + 1) % TAMANHO;
    }
    strcpy(tabela[indice].chave, chave);
    strcpy(tabela[indice].valor, valor);
}

char* buscar_elemento_hash(struct Elemento* tabela, char* chave){
    int indice = calcular_hash(chave);
    while(strcmp(tabela[indice].chave, "") != 0){
        if(strcmp(tabela[indice].chave, chave) == 0){
            return tabela[indice].valor;
        }
        indice = (indice + 1) % TAMANHO;
    }
    return "Valor inválido";
}

int main ()
{
    struct Elemento* tabela = criar_tabela_hash();

    inserir_elemenot_hash(tabela, "ch1", "Professor");
    inserir_elemenot_hash(tabela, "ch2", "Advogado");
    inserir_elemenot_hash(tabela, "ch3", "Médico");

    printf("%s\n", buscar_elemento_hash(tabela,"ch1"));
    printf("%s\n", buscar_elemento_hash(tabela,"ch2"));
    printf("%s\n", buscar_elemento_hash(tabela,"ch4"));

    free(tabela);

    return 0;
}