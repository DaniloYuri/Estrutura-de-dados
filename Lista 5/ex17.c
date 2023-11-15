#include <stdio.h>
#include <string.h>

void inv(char s[], int p, int u) {
    if (p >= u) {
        return; 
    }
    
    char temp = s[p];
    s[p] = s[u];
    s[u] = temp;

    inv(s, p + 1, u - 1);
}

int main() {
    char str[] = "abcdef"; 
    int p = 1; 
    int u = 4; 

    printf("String original: %s\n", str);

    if (p >= 0 && u < strlen(str)) {
        inv(str, p, u);
        printf("String invertida: %s\n", str);
    } else {
        printf("Erro: Posições fora dos limites da string.\n");
    }

    return 0;
}