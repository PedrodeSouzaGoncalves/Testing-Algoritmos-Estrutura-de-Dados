#include <stdio.h>
#include <stdlib.h>

struct Pilha{
    int topo;
    int capacidade;
    float *proxElemento;
};

void cria_pilha(struct Pilha *p, int c){
    p -> proxElemento = (float*)malloc(c *sizeof(float));
    p -> topo = -1;
    p -> capacidade = c;
}

void push_pilha(struct Pilha *p, float v){
    p -> topo++;
    p -> proxElemento[p -> topo] = v;
}

float pop_pilha(struct Pilha *p){
    float aux = p -> proxElemento [p -> topo];
    p -> topo--;
    printf("O elemento removido foi %.2f\n", aux);
    return aux;
}

int pilha_vaiza(struct Pilha *p){
    if(p -> topo == -1)
    return 1; // Se o topo for igual -1 a função retorna verdadeiro
    else
    return 0; // Caso contrário, a função retorna falso
}

int pilha_cheia(struct Pilha *p){
    if(p -> topo == p -> capacidade -1)
    return 1;
    else
    return 0;
}

void imprime_pilha(struct Pilha *p){
    int i;
    for(i=(p->topo); i>=0; i--){
        printf("%.2f\n",p->proxElemento[i]);
    }
}

int main()
{
    struct Pilha pedro;

    cria_pilha(&pedro, 5);

    push_pilha(&pedro, 7);
    push_pilha(&pedro, 27);
    push_pilha(&pedro, 3);
    push_pilha(&pedro, 81);
    push_pilha(&pedro, 1);

    //printf("A pilha tem %d, elementos\n", pedro.capacidade);
    //printf("O primerio elemento %.2f\n", pedro.proxElemento[0]);
    //printf("O último elemento é %.2f\n", pedro.proxElemento[4]);

    imprime_pilha(&pedro);

    pilha_vaiza(&pedro);

    pop_pilha(&pedro);

    imprime_pilha(&pedro);

    return 0;
}