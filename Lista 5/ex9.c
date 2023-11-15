#include <stdio.h>

int par(int n) {
    if (n < 0) {
        n = -n;
    }

    if (n == 0) {
        return 1; 
    } else if (n == 1) {
        return 0; 
    } else {
        return par(n - 2); 
    }
}

int main() {
    int num;
    
    printf("Digite um numero natural: ");
    scanf("%d", &num);
    
    if (par(num)) {
        printf("%d e par.\n", num);
    } else {
        printf("%d e ímpar.\n", num);
    }

    return 0;
}