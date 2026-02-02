#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
ll const maxn = 2e3 + 7, inf = 2e15 + 7;
ll t, n;
ll a[maxn], b[maxn];
ll dp[maxn][maxn][2];
ll siz[maxn], fa[maxn][2], fb[maxn][2], fc[maxn][2][2];
vector<ll> e[maxn];
void dfs(ll u, ll f)
{
    // printf("%d %d\n", u, f);
    if (u != 1 and e[u].size() == 1)
    {
        siz[u] = 1;
        dp[u][0][0] = a[u];
        dp[u][0][1] = dp[u][1][0] = dp[u][1][1] = 0;
        return;
    }
    // printf("%d %d\n", u, f);
    siz[u] = 0;
    for (auto v : e[u])
    {
        if (v == f)
            continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
    ll res = 0, o = 0;
    fa[0][o ^ 1] = fb[0][o ^ 1] = fc[0][o ^ 1][0] = fc[0][o ^ 1][1] = 0;
    for (auto v : e[u])
    {
        if (v == f)
            continue;
        for (ll i = 0; i <= res + siz[v]; ++i)
            fa[i][o] = fb[i][o] = fc[i][o][0] = fc[i][o][1] = inf;
        for (ll i = 0; i <= res; ++i)
            for (ll j = 0; j <= siz[v]; ++j)
            {
                fa[i + j][o] = min(fa[i + j][o], fa[i][o ^ 1] + dp[v][j][0]);
                fb[i + j][o] = min(fb[i + j][o], fb[i][o ^ 1] + min(dp[v][j][0], dp[v][j][1]));
                fc[i + j][o][0] = min(fc[i + j][o][0], fc[i][o ^ 1][0] + dp[v][j][0]);
                fc[i + j][o][1] = min(fc[i + j][o][1], min(fc[i][o ^ 1][1] + dp[v][j][0], fc[i][o ^ 1][0] + dp[v][j][1]));
            }
        res += siz[v];
        o ^= 1;
    }
    for (ll i = 0; i <= siz[u]; ++i)
    {
        dp[u][i][0] = min(fa[i][o ^ 1], a[u] + fb[i][o ^ 1]);
        dp[u][i][1] = min(fc[i][o ^ 1][0], fc[i][o ^ 1][1]);
    }
    // printf("%d %d %d\n", u, dp[u][0][0], dp[u][0][1]);
}
void init()
{
    memset(dp, 0x7f, sizeof(dp));
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &b[i]);
    for (ll i = 1, a, b; i < n; ++i)
    {
        scanf("%lld%lld", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     printf("%d ", i);
    //     for (auto v : e[i])
    //         printf("%d ", v);
    //     printf("\n");
    // }
}
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        init();
        dfs(1, 0);
        ll ans = inf;
        for (ll i = 0; i <= siz[1]; ++i)
        {
            ans = min(ans, b[i] + min(dp[1][i][0], dp[1][i][1]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}