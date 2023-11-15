#include <stdio.h>

int qd(int n) {
    if (n == 0 || n == 1) {
        return 1; 
    } else {
        return 1 + qd(n / 2); 
    }
}

int main() {
    int n;
    
    printf("Digite um numero natural: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Erro: O numero deve ser um numero natural (>= 0).\n");
        return 1;
    }
    
    int resultado = qd(n);
    
    printf("A quantidade de digitos binarios para representar %d e %d\n", n, resultado);

    return 0;
}