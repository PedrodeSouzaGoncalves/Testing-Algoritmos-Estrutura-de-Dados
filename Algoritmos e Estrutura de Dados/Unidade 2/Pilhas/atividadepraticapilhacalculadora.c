// Bibliotecas para poder usar entrada e saída e a função malloc
#include <stdio.h>
#include <stdlib.h>

// Estrutura Pilha como topo, capacidade e ponteiro para próximo elemento
struct Pilha{
    int topo;
    int capacidade;
    int *prox_elemento;
};

// Função para criar uma pilha, próximo elemento, topo e capacidade asignados 
void cria_pilha(struct Pilha *p, int c){
    p -> prox_elemento = (int*)malloc(c *sizeof(int)); // Uso do malloc para alocar memória dinâmicamente
    p -> topo = -1; 
    p -> capacidade = c;
}

// Função push (empilhar) para adicionar um novo elemento na pilha
void push_pilha(struct Pilha *p, int v){
    // Condição para verificar se a pilha está cheia e impedir novos elementos de serem adicionados evitando stack overflow
    if (p->topo == p->capacidade - 1) {
        printf("Erro: a pilha está cheia! Não é possível adicionar o elemento %d.\n", v);
        return;
    }

    p -> topo++; // aumento do topo 
    p -> prox_elemento[p -> topo] = v; // novo elemento guardado no topo
}

// Função pop (desimplhar) para remover o último elemento que entrou respeitando LIFO (Last in, First Out)
int pop_pilha(struct Pilha *p){
    // Condição para verificar se a pilha está vazia ou não.
    if (p->topo == -1) {
        printf("Erro: a pilha está vazia! Não há elementos para remover.\n");
        return -1; // valor simbólico de erro
    }

    int aux = p -> prox_elemento[p -> topo];
    p -> topo--;
    printf("O elemento removido foi %d\n", aux); // Messagem mostrando qual elemento foi removido
    return aux;
}

// Função que verifica se a pilha está vazia
int pilha_vazia(struct Pilha *p){
    if(p -> topo ==-1){
        printf("A pilha está vazia\n"); // Mensagem que aparece somente quando a pilha está vazia
        return 1;
    }else{
        printf("A pilha não está vazia\n"); // Mensagem que aparece somente quando a pilha não está vazia
        return 0;}
}

// Função para imprimir a pilha e mostrar tanto os elementos adicionados como os removidos e qual o estado da pilha atual
void imprime_pilha(struct Pilha *p){
    int i;
    printf("Os elementos da pilha são: \n");
    for (i=(p->topo); i>=0; i--){
        printf("%d\n", p->prox_elemento[i]);
    }
}

// Função principal onde será criada a estrutura e as funções serão chamadas 
int main()
{
    struct Pilha calcular; // Estrura calcular

    cria_pilha(&calcular, 5); // Pilha calcular criada com a função criar, com 5 elementos no total

    printf("\n--- Teste pilha vazia ---\n");

    pilha_vazia(&calcular); // Verificando se a pilha está vazia, retornando verdadeiro

    printf("\n--- Teste de inserção ---\n");

    // Função push para adicionar elementos, neste caso foram adicionados mais que 5 elementos para verificar o funcionamento correto do código
    push_pilha(&calcular, 5+5);
    push_pilha(&calcular, 5*60);
    push_pilha(&calcular, 10-75);
    push_pilha(&calcular, 100/2);
    push_pilha(&calcular, 100+2);
    push_pilha(&calcular, 100+100);
    push_pilha(&calcular, 100+666);

    // Função que imprime os valores adicionados à pilha
    imprime_pilha(&calcular);

    printf("\n--- Teste de remoção ---\n");

    // Função pop (desempilha) para remover o último elemento que entrou na pilha
    pop_pilha(&calcular);

    // Função pilha vazia que não retornará que ela está vazia comprovando que a função funciona
    pilha_vazia(&calcular);

    free(calcular.prox_elemento); // Liberando a memória

    return 0;
}