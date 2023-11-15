#include <stdio.h>

int prod(int m, int n) {
    if (m == 0 || n == 0) {
        return 0; 
    } else if (n < 0) {
        return -prod(m, -n); 
    } else if (n == 1) {
        return m;
    } else {
        return m + prod(m, n - 1);
    }
}

int main() {
    int m, n;
    
    printf("Digite dois numeros naturais (m e n): ");
    scanf("%d %d", &m, &n);
    
    int resultado = prod(m, n);
    
    printf("O produto de %d e %d e %d\n", m, n, resultado);

    return 0;
}