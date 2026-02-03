#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    p = malloc(sizeof(int));

    /*malloc aloca memória, sizeof define o tamanho
    o que acontece é que a função malloc vai alocar a memória de acordo
    com o que a função sizeof definir, no caso acima foi de 1 int, 4 bytes*/

    if(!p){
        printf("Erro de memória insuficiente");
    } else{
        printf("Memória alocada com sucesso");
    }
    return 0;
}