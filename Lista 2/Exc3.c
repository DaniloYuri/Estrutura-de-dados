#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int prio(char o) {
    switch (o) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return -1; // operador inválido!
}

int avaliarExpressaoPosfixa(char *expr) {
    Pilha p = pilha(256);
    int i, op1, op2, resultado;

    for (i = 0; expr[i]; i++) {
        if (isdigit(expr[i])) {
            empilha(expr[i] - '0', p);
        } else if (strchr("+-*/", expr[i])) {
            op2 = desempilha(p);
            op1 = desempilha(p);
            switch (expr[i]) {
                case '+': empilha(op1 + op2, p); break;
                case '-': empilha(op1 - op2, p); break;
                case '*': empilha(op1 * op2, p); break;
                case '/': empilha(op1 / op2, p); break;
            }
        }
    }

    resultado = topo(p);
    destroip(&p);

    return resultado;
}

char *infixaParaPosfixa(char *expr) {
    static char s[256];
    int j = 0;
    Pilha p = pilha(256);
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') empilha('(', p);
        else if (isdigit(expr[i])) s[j++] = expr[i];
        else if (strchr("+-/*", expr[i])) {
            while (!vaziap(p) && prio(topo(p)) >= prio(expr[i]))
                s[j++] = desempilha(p);
            empilha(expr[i], p);
        } else if (expr[i] == ')') {
            while (topo(p) != '(')
                s[j++] = desempilha(p);
            desempilha(p);
        }
    }
    while (!vaziap(p))
        s[j++] = desempilha(p);
    s[j] = '\0';
    destroip(&p);
    return s;
}

int main() {
    char expressaoInfixa[512];
    printf("Digite uma expressao aritmetica na forma infixa: ");
    gets(expressaoInfixa);

    char expressaoPosfixa[256];
    strcpy(expressaoPosfixa, infixaParaPosfixa(expressaoInfixa));

    int valor = avaliarExpressaoPosfixa(expressaoPosfixa);

    printf("Forma posfixa: %s\n", expressaoPosfixa);
    printf("Valor numerico: %d\n", valor);

    return 0;
}
