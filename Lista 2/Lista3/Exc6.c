#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h" // Inclua o arquivo "pilha.h" que você já possui

// Função para calcular o valor da expressão prefixa
int valpre(char* expressao) {
    int tamanho = strlen(expressao);
    Pilha pilha = pilha(tamanho);

    // Percorre a expressão da direita para a esquerda
    for (int i = tamanho - 1; i >= 0; i--) {
        if (expressao[i] >= '0' && expressao[i] <= '9') {
            // Se for um dígito, converte para inteiro e empilha
            empilha(expressao[i] - '0', pilha);
        } else if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/') {
            // Se for um operador, desempilha dois operandos e realiza a operação
            int operando1 = desempilha(pilha);
            int operando2 = desempilha(pilha);

            switch (expressao[i]) {
                case '+':
                    empilha(operando1 + operando2, pilha);
                    break;
                case '-':
                    empilha(operando1 - operando2, pilha);
                    break;
                case '*':
                    empilha(operando1 * operando2, pilha);
                    break;
                case '/':
                    empilha(operando1 / operando2, pilha);
                    break;
            }
        }
    }

    int resultado = desempilha(pilha);
    destroip(&pilha); // Libera a pilha

    return resultado;
}

int main() {
    char expressao[256];
    printf("Digite a expressão aritmética prefixa: ");
    gets(expressao);

    int resultado = valpre(expressao);
    printf("Resultado: %d\n", resultado);

    return 0;
}
