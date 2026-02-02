#include <iostream>
using namespace std;
int const maxn = 25e4 + 7;
int t, n, q, l, r, x;
int a[maxn], b[maxn], c[maxn];
void dis(int x, int i)
{
    int o = 0, p = 0, s = x % 2;
    c[i] = c[i - 1];
    while (x > 1)
    {
        p += x & 1;
        ++o;
        x >>= 1;
    }
    if (p == 1 and s == 1)
    {
        ++c[i];
    }
    else if (p != 0)
    {
        ++o;
    }
    b[i] = b[i - 1] + o;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            dis(a[i], i);
        }
        // for (int i = 1; i <= n; ++i)
        //     printf("%d %d\n", b[i], c[i]);
        while (q--)
        {
            scanf("%d%d", &l, &r);
            x = b[r] - b[l - 1] + (c[r] - c[l - 1]) / 2;
            printf("%d", x);
            if (t or q)
                printf("\n");
        }
        for (int i = 0; i <= n; ++i)
            b[i] = c[i] = 0;
    }
    return 0;
}