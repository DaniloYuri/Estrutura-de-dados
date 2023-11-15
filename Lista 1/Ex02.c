#include <stdio.h>
#include "pilha.h" 

int main() {
    int n, num;

    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    Pilha A = pilha(n);
    Pilha B = pilha(n);

    printf("Digite os números:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        // Verifica se o número já foi empilhado
        int found = 0;
        Pilha tmp = pilha(n);

        while (!vaziap(A)) {
            int curr = desempilha(A);
            if (curr == num) {
                found = 1;
                break;
            }
            empilha(curr, tmp);
        }

        while (!vaziap(tmp)) {
            empilha(desempilha(tmp), A);
        }
        destroip(&tmp);

        if (!found) {
            empilha(num, A);
        }
    }

    while (!vaziap(A)) {
        Itemp curr = desempilha(A);

        while (!vaziap(B) && curr > topo(B)) {
            empilha(desempilha(B), A);
        }

        empilha(curr, B);
    }

    printf("Números ordenados:\n");
    while (!vaziap(B)) {
        printf("%d ", desempilha(B));
    }
    printf("\n");

    destroip(&A);
    destroip(&B);

    return 0;
}
