#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void maiorValor(Pilha A, Pilha B, float valor, Conjunto conjunto){
    if (!pertence(conjunto, valor)) {
        insere(conjunto, valor);
        
        if (!vaziap(A)) {
            if (valor > topo(A)) {
                empilha(desempilha(A), B);
                maiorValor(A, B, valor, conjunto);
            } else {
                empilha(valor, A);
                if (!vaziap(B)) {
                    float fAux = desempilha(B);
                    if (fAux < topo(A)) {
                        empilha(fAux, A);
                    } else {
                        maiorValor(A, B, fAux, conjunto);
                    }
                }
            }
        } else {
            empilha(valor, A);
            if (!vaziap(B)) {
                empilha(desempilha(B), A);
            }
            return;
        }
    }
}

int main(void){
    Pilha A = pilha(5);
    Pilha B = pilha(5);
    Conjunto conjunto = criaConjunto();
    int n = 0;
    float fNumeroInserido = 0.0;
    
    do {
        printf("Insira um numero para a pilha: \n");
        scanf("%f", &fNumeroInserido);
        maiorValor(A, B, fNumeroInserido, conjunto);
        n++;
    } while (n < 5);
    
    while (!vaziap(B)) empilha(desempilha(B), A);
    
    while (!vaziap(A))
        printf("%.2f  ", desempilha(A));
    printf("\n");
    
    destroip(&A);
    destroip(&conjunto);
    
    return 0;
}