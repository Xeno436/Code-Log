#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 10007;
int t, n, u, v, w;
int a[maxn], b[maxn], ans[maxn];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n * n + 1; ++i)
        a[i] = 0;
    u = n * n + 1;
    for (int i = 1; i <= n; ++i)
    {
        printf("? %d", u);
        for (int j = 1; j <= n * n + 1; ++j)
            if (!a[j])
                printf(" %d", j);
        printf("\n");
        fflush(stdout);
        scanf("%d", &w);
        u = u - w;
        for (int j = 1; j <= w; ++j)
        {
            scanf("%d", &b[j]);
            a[b[j]] = i;
        }
        if (w >= n + 1)
        {
            printf("!");
            for (int j = 1; j <= n + 1; ++j)
                printf(" %d", b[j]);
            printf("\n");
            fflush(stdout);
            return;
        }
    }
    for (int i = 1; i <= n * n + 1; ++i)
        if (!a[i])
            a[i] = n + 1;
    int tot = n + 1;
    for (int i = n * n + 1; i >= 1; --i)
        if (a[i] == tot)
            ans[tot--] = i;
    printf("!");
    for (int j = 1; j <= n + 1; ++j)
        printf(" %d", ans[j]);
    printf("\n");
    fflush(stdout);
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
}