#include <stdio.h>
#include <stdlib.h>

int main(){
    int var = 15;
    int *ptr; // declarando um ponteiro

    ptr = &var; // 
    
    printf("Conteudo de var = %d\n", var);
    //imprimindo o endereço da variável
    printf("Endereço de var = %p\n", &var);

    printf("conteudo apontado por ptr = %d\n", *ptr);
    printf("endereco apontado por ptr = %p\n", ptr);

    return 0;
}