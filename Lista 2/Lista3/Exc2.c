#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct pilha {
    int max;
    int topo;
    char *item;
} *Pilha;

Pilha pilha(int m) {
    Pilha P = malloc(sizeof(struct pilha));
    P->max = m;
    P->topo = -1;
    P->item = malloc(m * sizeof(char));
    return P;
}

int vaziap(Pilha P) {
    if (P->topo == -1)
        return 1;
    else
        return 0;
}

int cheiap(Pilha P) {
    if (P->topo == P->max - 1)
        return 1;
    else
        return 0;
}

void empilha(char x, Pilha P) {
    if (cheiap(P)) {
        puts("\n pilha cheia!");
        abort();
    }
    P->topo++;
    P->item[P->topo] = x;
}

char desempilha(Pilha P) {
    if (vaziap(P)) {
        puts("\n pilha vazia!");
        abort();
    }
    char x = P->item[P->topo];
    P->topo--;
    return x;
}

char topo(Pilha P) {
    if (vaziap(P)) {
        puts("\n pilha vazia!");
        abort();
    }
    return P->item[P->topo];
}

void destroip(Pilha *Q) {
    free((*Q)->item);
    free(*Q);
    *Q = NULL;
}

// Função para verificar a prioridade dos operadores
int prioridade(char operador) {
    if (operador == '*' || operador == '/')
        return 2;
    if (operador == '+' || operador == '-')
        return 1;
    return 0; // Prioridade mínima para outros caracteres
}

// Função para converter de notação infixa para prefixa
char *prefixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    // Inverter a expressão infixa
    char *infixReversed = strdup(e);
    strrev(infixReversed);

    for (int i = 0; infixReversed[i]; i++) {
        char c = infixReversed[i];

        if (isdigit(c) || isalpha(c)) {
            s[j++] = c;
        } else if (c == ')') {
            empilha(c, P);
        } else if (c == '(') {
            while (!vaziap(P) && topo(P) != ')') {
                s[j++] = desempilha(P);
            }
            if (!vaziap(P) && topo(P) == ')') {
                desempilha(P); // Desempilhe o '(' correspondente
            }
        } else {
            while (!vaziap(P) && prioridade(topo(P)) >= prioridade(c)) {
                s[j++] = desempilha(P);
            }
            empilha(c, P);
        }
    }

    while (!vaziap(P)) {
        s[j++] = desempilha(P);
    }

    s[j] = '\0';
    strrev(s); // Inverter novamente para obter a notação prefixa

    destroip(&P);
    free(infixReversed);

    return s;
}

int main() {
    char *infix = "((2*3)+(8/4))";
    char *prefix = prefixa(infix);
    printf("Infixa: %s\n", infix);
    printf("Prefixa: %s\n", prefix);

    return 0;
}
