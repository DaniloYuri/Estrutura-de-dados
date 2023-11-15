#include <stdio.h>
#include <string.h>
#include <ctype.h>

int pal(char s[], int p, int u) {
    while (p <= u && isspace(s[p]))
        p++;
    while (p <= u && isspace(s[u]))
        u--;

    if (p >= u) {
        return 1; 
    }

    if (tolower(s[p]) != tolower(s[u])) {
        return 0; 
    }

    return pal(s, p + 1, u - 1);
}

int main() {
    char str[] = "ola amor a roma mundo"; 
    int p = 4; 
    int u = 14; 

    printf("String original: %s\n", str);

    if (pal(str, p, u)) {
        printf("A string e um palindromo.\n");
    } else {
        printf("A string nao e um palindromo.\n");
    }

    return 0;
}