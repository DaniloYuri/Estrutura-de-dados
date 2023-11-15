#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
    char c[513];
    Pilha P = pilha(513);
    Pilha P2 = pilha(513);
    
    printf("Digite qualquer frase: ");
    gets(c);
    
    int len = strlen(c);
    int wordStart = 0;

    for (int i = 0; i <= len; i++) {
        if (c[i] == ' ' || c[i] == '\0') {
            for (int j = i - 1; j >= wordStart; j--) {
                empilha(c[j], P);
            }
            if (c[i] == ' ') {
                empilha(' ', P);
            }
            wordStart = i + 1;
        }
    }
    
    printf("Inverso do mesmo é: ");
    
    while (!vaziap(P)) 
        empilha (desempilha(P),P2);
    
    while (!vaziap(P2))
    printf("%c", desempilha(P2));
    
    printf("\n");
    
    destroip(&P);
    
    return 0;
}