#include <stdio.h>
#include <time.h>
#include <math.h>

#define p(n) (pow(10, n));

// função bsort()
void troca(int v[], int i, int j)
{
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}

void bsort(int v[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (v[j] > v[j + 1])
                troca(v, j, j + 1);
}
// função bsort()

// função msort()
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
// função msort()

void preenche(int v[], int n, int s)
{
    srand(s);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 1000;
}

void exibe(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

int main(void)
{
    int x = p(5);
    int y = p(4);
    int v[x];
    double t, b, m;
    puts("n bsort msort");
    for (int n = y; n <= x; n += y)
    {
        preenche(v, n, 1);
        t = clock();
        bsort(v, n);
        b = (clock() - t) / CLOCKS_PER_SEC;
        preenche(v, n, 1);
        t = clock();
        msort(v, n);
        m = (clock() - t) / CLOCKS_PER_SEC;
        printf("%6d %5.1f %5.1f\n", n, b, m);
    }
    return 0;
}