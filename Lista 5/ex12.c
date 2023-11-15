#include <stdio.h>

int resto(int m, int n) {
    if (m < 0) {
        return -resto(-m, n); 
    } else if (m < n) {
        return m; 
    } else {
        return resto(m - n, n);
    }
}

int main() {
    int m, n;
    
    printf("Digite dois numeros naturais (m e n): ");
    scanf("%d %d", &m, &n);
    
    if (n == 0) {
        printf("Erro: n deve ser diferente de zero.\n");
        return 1;
    }
    
    int resultado = resto(m, n);
    
    printf("O resto da divisao de %d por %d e %d\n", m, n, resultado);

    return 0;
}