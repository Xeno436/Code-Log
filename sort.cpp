#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int const maxn = 1e5 + 7;
bool thereis[2] = {false, false};
int ans[maxn], tot;
void choose(int *p, int plen, int *q, int qlen, size_t _count);

void choose(int *p, int plen, int *q, int qlen, size_t _count)
{
    int c[plen];
    bool notboth[plen];
    for (int i = 0; i <= plen - 1; ++i)
        c[i] = 0, notboth[i] = true;
    for (int i = 0; i <= plen - 1; ++i)
    {
        for (int j = 0; j <= qlen - 1; ++j)
            if (p[i] == q[j])
            {
                notboth[i] = false;
                break;
            }
        if (!notboth[i])
            continue;
        c[i] = p[i];
        thereis[_count] = true;
    }
    for (int i = 0; i <= plen - 1; ++i)
    {
        bool appear = false;
        for (int j = 0; j <= i - 1; ++j)
            if (p[i] == p[j])
            {
                appear = true;
                break;
            }

        if (notboth[i] && !appear)
        {
            ans[++tot] = c[i];
        }
    }
}

int main()
{
    int m, n;
    scanf("%d", &m);
    int a[m];
    for (int i = 0; i <= m - 1; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &n);
    int b[n];
    for (int i = 0; i <= n - 1; ++i)
        scanf("%d", &b[i]);
    choose(a, m, b, n, 0);
    choose(b, n, a, m, 1);
    for (int i = 1; i <= tot; ++i)
    {
        printf("%d", ans[i]);
        if (i != tot)
            printf(" ");
    }
    return 0;
}