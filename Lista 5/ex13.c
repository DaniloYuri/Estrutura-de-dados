#include <stdio.h>

int q(int n) {
    if (n == 1) {
        return 1; 
    } else {
        return (2 * n - 1) + q(n - 1); 
    }
}

int main() {
    int n;
    
    printf("Digite um numero natural: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Erro: O numero deve ser um numero natural (>= 1).\n");
        return 1;
    }
    
    int resultado = q(n);
    
    printf("O quadrado de %d e %d\n", n, resultado);

    return 0;
}