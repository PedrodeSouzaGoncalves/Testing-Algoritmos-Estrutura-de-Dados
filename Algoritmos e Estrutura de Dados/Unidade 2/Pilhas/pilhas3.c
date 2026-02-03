#include <stdio.h>

int main()
{
    int pilha[20];
    int topo = 0;

    pilha[topo] = 25;
    topo++;

    printf("\nA quantidade de elementos na pilha é de: %d", topo);
    printf("\nO valor no topo é de: %d", pilha[0]);
    
    return 0;
}