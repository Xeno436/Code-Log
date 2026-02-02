#include <iostream>
using namespace std;
int const maxn = 1e4 + 7, maxk = 1e2 + 7;
int n, k;
int ans;
int a[maxn], t[2][maxk];
int lb(int x)
{
    return x & -x;
}
void mod(int o, int x, int l)
{
    if (x == 0)
        return;
    for (int i = x; i <= k; i += lb(i))
        t[o][i] += l;
}
int qua(int o, int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lb(i))
        ans += t[o][i];
    return ans;
}
int main()
{
    scanf("%d%d", &n, &k);
    // mod(0, 1, 1);
    // printf("%d ", qua(0, k));
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1; --i)
        if (a[i] != -1)
        {
            ans += qua(1, a[i] - 1);
            mod(1, a[i], 1);
            // printf("%d ", i);
        }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == -1)
        {
            int tmp = maxn, res;
            for (int j = 1; j <= k; ++j)
            {
                res = qua(0, k) - qua(0, j) + qua(1, j - 1);
                // printf("%d %d\n", j, res);
                if (res < tmp)
                    tmp = res;
            }
            ans += tmp;
        }
        else
        {
            mod(0, a[i], 1);
            mod(1, a[i], -1);
        }
    }
    printf("%d", ans);
    return 0;
}