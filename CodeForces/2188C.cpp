#include <iostream>
#define m (l + (r - l >> 1))
using namespace std;
int const maxn = 2e5 + 7, inf = 1e9 + 7;
int t, n, a[maxn], b[maxn];
bool flag;
int ans, mx, mn;
void sol(int a, int b)
{
    // printf("%d %d\n", a, b);
    int x = mx - a;
    if (x < b - mn)
        x = b - mn;
    if (x < a - b)
        x = a - b;
    if (ans > x)
        ans = x;
}
void sort(int l, int r)
{
    if (l == r)
        return;
    sort(l, m), sort(m + 1, r);
    for (int i = l; i <= r; ++i)
        b[i] = a[i];
    if (b[m] > b[m + 1])
        sol(b[m], b[m + 1]);
    int i = l, j = l, k = m + 1;
    while (j <= m and k <= r)
    {
        if (b[j] > b[k])
            a[i++] = b[k++];
        else
            a[i++] = b[j++];
    }
    while (j <= m)
        a[i++] = b[j++];
    while (k <= r)
        a[i++] = b[k++];
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ans = inf, mx = 0, mn = inf;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            if (a[i] > mx)
                mx = a[i];
            if (a[i] < mn)
                mn = a[i];
        }
        sort(1, n);
        if (ans == inf)
            puts("-1");
        else
            printf("%d\n", ans);
        // for (int i = 1; i <= n; ++i)
        //     printf("%d ", a[i]);
        // printf("\n");
    }
}