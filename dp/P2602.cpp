#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll const maxn = 17;
ll a, b;
ll dp[maxn][maxn];
ll s[maxn], tot;
ll cur;
ll dfs(ll u, ll x, bool f0, bool lim)
{
    if (u == 0)
        return x;
    if (f0 == false and lim == false and dp[u][x] != -1)
        return dp[u][x];
    ll up = 9;
    if (lim)
        up = s[u];
    ll res = 0;
    for (ll i = 0; i <= up; ++i)
        res += dfs(u - 1, x + ((i == cur and cur != 0) or (cur == 0 and i == 0 and f0 == 0)),
                   f0 and (i == 0), lim and (i == s[u]));
    if (f0 == 0 and lim == 0)
        dp[u][x] = res;
    return res;
}
ll solve(ll x)
{
    memset(dp, -1, sizeof(dp));
    tot = 0;
    while (x)
    {
        s[++tot] = x % 10;
        x /= 10;
    }
    return dfs(tot, 0, 1, 1);
}
int main()
{
    scanf("%lld%lld", &a, &b);
    for (ll i = 0; i <= 9; ++i)
    {
        cur = i;
        printf("%lld ", solve(b) - solve(a - 1));
    }
    return 0;
}