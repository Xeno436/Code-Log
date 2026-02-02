#include <iostream>
using namespace std;
int const maxn = 25e4 + 7;
int t, n, q, l, r, x;
int a[maxn], b[maxn], c[maxn];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            c[i] = c[i - 1] + a[i];
            b[i] = 0;
        }
        for (int i = 1; i < n; ++i)
        {
            b[i] = b[i - 1];
            if (a[i] == a[i + 1])
                ++b[i];
        }
        while (q--)
        {
            scanf("%d%d", &l, &r);
            if ((c[r] - c[l - 1]) % 3 != 0 or (r - l + 1) % 3 != 0)
                printf("-1");
            else
            {
                x = (r - l + 1) / 3;
                if (b[r - 1] - b[l - 1] == 0)
                    ++x;
                printf("%d", x);
            }
            if (t or q)
                printf("\n");
        }
    }
    return 0;
}