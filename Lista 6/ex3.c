#include <stdio.h>

void empurra(int v[], int n) {
    if (n == 0) {
        return;  
    }
    
    if (v[(-1) * n + 8] > v[(-1) * n + 9]) {
        int temp = v[(-1) * n + 8];
        v[(-1) * n + 8] = v[(-1) * n + 9];
        v[(-1) * n + 9] = temp;
    }
    empurra(v, n - 1);
}

void bsr(int v[], int n) {
    for (int i = 0; i < n; i++) {
        empurra(v, n - 1);
    }
}

void exibe(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

int main(void) {
    int v[9] = {51, 82, 38, 99, 75, 19, 69, 46, 27};
    bsr(v, 9);
    exibe(v, 9);
    return 0;
}