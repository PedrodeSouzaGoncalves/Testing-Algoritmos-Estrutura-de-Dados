#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

struct Usuario{
    char chave[50];
    char nome[50];
    char senha[50];
};

struct Usuario* criar_tabela_hash(){
    struct Usuario* pessoa = (struct Usuario*)malloc(TAM * sizeof(struct Usuario));
    for (int i =0; i < TAM; i++){
        strcpy(pessoa[i].chave, "");
        strcpy(pessoa[i].nome, "");
        strcpy(pessoa[i].senha, "");
    }
    return pessoa;
}

int calcular_hash(char* chave){
    int hash = 0;
    for (int i = 0; i < strlen(chave); i++){
        hash += chave[i];
    }
    return hash % TAM;
}

void inserir_elemento_hash(struct Usuario* pessoa, char* chave, char* nome, char* senha){
    int indice = calcular_hash(chave);
    while (strcmp(pessoa[indice].chave, "") != 0){
        indice = (indice + 1) % TAM;
    }
    strcpy(pessoa[indice].chave, chave);
    strcpy(pessoa[indice].nome, nome);
    strcpy(pessoa[indice].senha, senha);
}

char* buscar_elemento_hash(struct Usuario* pessoa, char* chave, char* nome, char* senha){
    int indice = calcular_hash(chave);
    while(strcmp(pessoa[indice].chave, "") != 0){
        if(strcmp(pessoa[indice].chave, chave) == 0){
            strcpy(nome, pessoa[indice].nome);
            strcpy(senha, pessoa[indice].senha);
            return pessoa[indice].nome;

        }
        indice = (indice + 1) % TAM;
    }
    return "Valor inválido";
}

void imprimir_tabela(struct Usuario* pessoa, char* chave, char* nome, char* senha){
    int i;
    for (i = 0; i < TAM; i++){
        printf("Identificação: %s, Nome: %s, Senha: %s", chave, nome, senha);
    }
}

int main()
{
    int opcao, contador = 1;
    char chave[50], nome[50], senha[50];

    struct Usuario* pessoa = criar_tabela_hash();

    //inserir_elemento_hash(pessoa, "ID1", "Pedro", "Minerva01");

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            if(contador > TAM){
                printf("Tabela cheia!");
                break;
            }
            printf("\n--Inserir usuário--\n");
            printf("Digite o nome: \n");
            scanf("%s", nome);

            printf("Digite a senha: \n");
            scanf("%s", senha);
            senha[strcspn(senha, "\n")] = '\0';

            sprintf(chave, "%d", contador);
            inserir_elemento_hash(pessoa, chave, nome, senha);
            printf("Usuário inserido com sucesso! Chave gerada: %s\n", chave);

        break;
        case 2:
            printf("\n--Buscar usuário--\n");
            printf("Digite a chave: \n");
            scanf("%s", chave);
            chave[strcspn(chave, "\n")] = '\0';

            if(buscar_elemento_hash(pessoa, chave, nome, senha)){
                printf("Nome: %s\n", nome);
                printf("Senha: %s\n", senha);
            } else{
                printf("Usuário não encontrado.\n");
            }
        break;

        case 3:
            printf("\n--Imprimindo os Usuários cadastrados--\n");
            imprimir_tabela(pessoa, chave, nome, senha);
        break;

        default:
            printf("Saindo do programa!");
        }
    }while (opcao != 0);
    
    free(pessoa);
    return 0;
}