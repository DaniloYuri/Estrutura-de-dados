#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int evalPosfix(char *posfixa) {
    Pilha P = pilha(256);
    for (int i = 0; posfixa[i]; i++) {
        char c = posfixa[i];
        if (c == 'F') {
            empilha(0, P);  // Valor numérico de F é 0
        } else if (c == 'V') {
            empilha(1, P);  // Valor numérico de V é 1
        } else if (c == '!') {
            int operand = desempilha(P);
            empilha(!operand, P);  // Operador NOT
        } else if (c == '&') {
            int operand2 = desempilha(P);
            int operand1 = desempilha(P);
            empilha(operand1 && operand2, P);  // Operador AND
        } else if (c == '|') {
            int operand2 = desempilha(P);
            int operand1 = desempilha(P);
            empilha(operand1 || operand2, P);  // Operador OR
        }
    }
    int result = topo(P);  // Resultado final
    destroip(&P);
    return result;
}

char *infixToPosfix(char *infix) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    int prio(char o) {
        switch (o) {
            case '(': return 0;
            case '|': return 1;
            case '&': return 2;
            case '!': return 3;
        }
        return -1; // operador inválido!
    }

    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(')
            empilha('(', P);
        else if (infix[i] == 'F' || infix[i] == 'V')
            s[j++] = infix[i];
        else if (strchr("&|!", infix[i])) {
            while (!vaziap(P) && prio(topo(P)) >= prio(infix[i]))
                s[j++] = desempilha(P);
            empilha(infix[i], P);
        } else if (infix[i] == ')') {
            while (topo(P) != '(')
                s[j++] = desempilha(P);
            desempilha(P);
        }
    }
    while (!vaziap(P))
        s[j++] = desempilha(P);
    s[j] = '\0';
    destroip(&P);
    return s;
}

int main() {
    char infix[256];
    printf("Entre com a expressão booleana parentesiada: ");
    gets(infix);

    char *posfixa = infixToPosfix(infix);
    int resultado = evalPosfix(posfixa);

    printf("Expressão posfixa: %s\n", posfixa);
    printf("Valor numérico: %d\n", resultado);

    return 0;
}
