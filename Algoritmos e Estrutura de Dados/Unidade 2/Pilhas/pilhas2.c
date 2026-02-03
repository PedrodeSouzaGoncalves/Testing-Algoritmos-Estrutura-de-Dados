#include <stdio.h>

struct Pilha{
    int topo;
    int capacidade;
    float *proxElemento;
};

void cria_pilha(struct Pilha *p, int c){
    p->proxElemento = malloc(c* sizeof(float));
    p->topo = -1;
    p->capacidade = c;
}

void push_pilha(struct Pilha *p, float v){
    p->topo++;
    p->proxElemento[p->topo]=v;
}

float pop_pilha(struct Pilha *p){
    float aux = p->proxElemento[p->topo];
    p->topo--;
    return aux;
}

int main()
{
    struct Pilha minhapilha;
    return 0;
}