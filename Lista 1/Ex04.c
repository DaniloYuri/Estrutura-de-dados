#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
int estaBalanceada(const char *expressao) {
    int comprimento = strlen(expressao);
    Pilha p = pilha(comprimento);

    for (int i = 0; i < comprimento; i++) {
        char caractereAtual = expressao[i];

        if (caractereAtual == '(' || caractereAtual == '[' || caractereAtual == '{') {
            empilha(caractereAtual, p);
        } else if (caractereAtual == ')' || caractereAtual == ']' || caractereAtual == '}') {
            if (vaziap(p)) {
                destroip(&p);
                return 0;  // Expressão desbalanceada: fechamento sem abertura correspondente
            }

            char topoPilha = desempilha(p);

            if (!((topoPilha == '(' && caractereAtual == ')') ||
                  (topoPilha == '[' && caractereAtual == ']') ||
                  (topoPilha == '{' && caractereAtual == '}'))) {
                destroip(&p);
                return 0;  // Expressão desbalanceada: abertura e fechamento não correspondem
            }
        }
    }

    int expressaoBalanceada = vaziap(p);
    destroip(&p);

    return expressaoBalanceada;
}

int main() {
    char expressao[100];

    printf("Digite uma expressão: ");
    scanf("%s", expressao);

    if (estaBalanceada(expressao)) {
        printf("A expressão está balanceada.\n");
    } else {
        printf("A expressão não está balanceada.\n");
    }

    return 0;
}
