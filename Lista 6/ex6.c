#include <stdio.h>

void intercala(int v[], int p, int m, int u)
{
    int *w = malloc((u - p + 1) * sizeof(int));
    int i = p, j = m + 1, k = 0;
    while (i <= m && j <= u)
        w[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    while (i <= m)
        w[k++] = v[i++];
    while (j <= u)
        w[k++] = v[j++];
    for (k = 0; k <= u - p; k++)
        v[p + k] = w[k];
    free(w);
}

void ms(int v[], int p, int u)
{
    if (p == u)
        return;
    int m = (p + u) / 2;
    ms(v, p, m);
    ms(v, m + 1, u);
    intercala(v, p, m, u);
}

void msort(int v[], int n)
{
    ms(v, 0, n - 1);
}

void exibe(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

void preenche(int v[], int n, int s)
{
    srand(s);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 1000;
}

int main(void)
{
    int v[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};
    msort(v, 10);
    exibe(v, 10);

    printf("\n");

    int v1[10];
    preenche(v1, 10, 10);
    msort(v1, 10);
    exibe(v1, 10);

    printf("\n");
   
    preenche(v1, 10, 11);
    msort(v1, 10);
    exibe(v1, 10);

    printf("\n");

    preenche(v1, 10, 12);
    msort(v1, 10);
    exibe(v1, 10);

    printf("\n");

    preenche(v1, 10, 13);
    msort(v1, 10);
    exibe(v1, 10);

    printf("\n");
    return 0;
}