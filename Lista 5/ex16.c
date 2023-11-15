#include <stdio.h>

int h(int n) {
    if (n == 1) {
        return 1; 
    } else {
        return 2 * h(n - 1) + 1; 
    }
}

int main() {
    int n;
    
    printf("Digite o numero de discos: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Erro: O numero de discos deve ser maior ou igual a 1.\n");
        return 1;
    }
    
    int resultado = h(n);
    
    printf("O numero minimo de movimentos para resolver as Torres de Hanoi com %d discos e %d\n", n, resultado);

    return 0;
}