#include <iostream>
using namespace std;
#define ll long long
ll const maxn = 2e3 + 7, q = 1e9 + 7;
ll t, n, ans;
ll a[maxn];
ll d[maxn][maxn][maxn];
void solve()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    ans = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
                d[i][j][k] = 0;
    d[0][0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
            {
                if (!d[i][j][k])
                    continue;
                d[i + 1][j][k] = (d[i + 1][j][k] + d[i][j][k]) % q;
                if (a[i + 1] >= j)
                    d[i + 1][a[i + 1]][k] = (d[i + 1][a[i + 1]][k] + d[i][j][k]) % q;
                if (j > a[i + 1] and a[i + 1] >= k)
                    d[i + 1][j][a[i + 1]] = (d[i + 1][j][a[i + 1]] + d[i][j][k]) % q;
            }
    // printf("%lld %lld %lld %lld %lld\n", d[4][]);
    for (int j = 0; j <= n; ++j)
        for (int k = 0; k <= n; ++k)
            ans = (ans + d[n][j][k]) % q;
    printf("%lld\n", ans);
}
int main()
{
    scanf("%lld", &t);
    while (t--)
        solve();
    return 0;
}