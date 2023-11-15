#include <stdio.h>

void hanoi(int n, char origem, char auxiliar, char destino) {
    if (n == 1) {
        printf("Mova o disco 1 da torre %c para a torre %c\n", origem, destino);
        return;
    }

    hanoi(n - 1, origem, destino, auxiliar);
    printf("Mova o disco %d da torre %c para a torre %c\n", n, origem, destino);
    hanoi(n - 1, auxiliar, origem, destino);
}

int main() {
    int n;
    char origem = 'A', auxiliar = 'B', destino = 'C';

    printf("Digite o número de discos: ");
    scanf("%d", &n);

    hanoi(n, origem, auxiliar, destino);

    return 0;
}