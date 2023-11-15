#include <stdio.h>

int sd(int n) {
    if (n < 10) {
        return n; 
    } else {
        return (n % 10) + sd(n / 10); 
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
    
    int resultado = sd(n);
    
    printf("A soma dos digitos de %d e %d\n", n, resultado);

    return 0;
}