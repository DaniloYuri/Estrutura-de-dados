#include <stdio.h>

int quoc(int m, int n) {
    if (m < 0) {
        return -quoc(-m, n); 
    } else if (m < n) {
        return 0; 
    } else {
        return 1 + quoc(m - n, n);
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
    
    int resultado = quoc(m, n);
    
    printf("O quociente da divisao de %d por %d e %d\n", m, n, resultado);

    return 0;
}