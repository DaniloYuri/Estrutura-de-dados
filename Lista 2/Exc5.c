#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inverterString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int obterPrecedencia(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

char *infixoParaPrefixo(char *infixo) {
    inverterString(infixo);
    int len = strlen(infixo);
    char *prefixo = (char *)malloc(len + 1);
    char *saida = (char *)malloc(len);
    int indiceSaida = 0;
    int indicePilha = 0;
    char pilha[len];

    for (int i = 0; i < len; i++) {
        if (infixo[i] == ' ' || infixo[i] == '\t' || infixo[i] == '\n') {
            continue;
        } else if (infixo[i] == ')') {
            pilha[indicePilha++] = infixo[i];
        } else if (infixo[i] == '(') {
            while (indicePilha > 0 && pilha[indicePilha - 1] != ')') {
                prefixo[indiceSaida++] = pilha[--indicePilha];
            }
            indicePilha--; 
        } else if (ehOperador(infixo[i])) {
            while (indicePilha > 0 && obterPrecedencia(pilha[indicePilha - 1]) >= obterPrecedencia(infixo[i])) {
                prefixo[indiceSaida++] = pilha[--indicePilha];
            }
            pilha[indicePilha++] = infixo[i];
        } else {
         
            prefixo[indiceSaida++] = infixo[i];
        }
    }

    while (indicePilha > 0) {
        prefixo[indiceSaida++] = pilha[--indicePilha];
    }

    prefixo[indiceSaida] = '\0';
    inverterString(prefixo);
    free(saida);
    return prefixo;
}

int main() {
    char infixo[256];
    printf("Digite a expressão aritméticaparentesiada: ");
    gets(infixo);

    char *prefixo = infixoParaPrefixo(infixo);
    printf("Prefixo: %s\n", prefixo);

    free(prefixo);

    return 0;
}
