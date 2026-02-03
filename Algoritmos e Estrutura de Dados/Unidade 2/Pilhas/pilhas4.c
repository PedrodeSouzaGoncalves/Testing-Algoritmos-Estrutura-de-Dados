#include <stdio.h>
#include <stdlib.h>

#define tamanho_pilha 20

typedef struct{
    int vetor[tamanho_pilha];
    int topo;
} Pilha;

void empilhar(int valor, Pilha *pilha){
    
    // testa se tem espaço
    if(pilha->topo < tamanho_pilha){
        //empilhar
        pilha->vetor[pilha->topo] = valor;
        pilha->topo++;
    } else{
        // pilha cheia
        printf("Não há mais espaço na pilha.\n");
    }
}

void desempilha(Pilha *pilha){

    // testar se a pilha não esta vazia
    if(pilha->topo > 0){
        // desempilha
        pilha->topo--;
        printf("Elemento retirado: %d", pilha->vetor[pilha->topo]);
    } else{
        // pilha vazia
        printf("A pilha está vazia.\n");
    }
}

int isCheia(Pilha *pilha){
    if(pilha->topo >= tamanho_pilha){
        return 1;
    } else{
        return 0;
    }
}

int isVazia(Pilha *pilha){
    if(pilha->topo == 0){
        return 1;
    } else{
        return 0;
    }
}

void imprimePilha(Pilha *pilha){
    int i;
    for (i=(pilha->topo);i--;i>=0){
        printf("%02d\n", pilha->vetor[i]);
    }
}

int main()
{
    // declara uma pilha
    Pilha p;
    p.topo = 0;

    // empilhar elementos
    empilhar(5,&p);  //primeiro elemento
    empilhar(2,&p);  //segundo elemento
    empilhar(6,&p);  //terceiro elemento 
    empilhar(9,&p);  //quarto elemento 
    empilhar(50,&p);  //quinto elemento 

    desempilha(&p);

    printf("Topo da pilha: %d\n", p.topo); // quantidade de elementos na pilha não o valor do topo

    imprimePilha(&p);

    return 0;
}