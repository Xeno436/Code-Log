#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll const maxn = 2e5 + 7, mod = 998244353;
ll t, n, m;
ll fac[maxn], ifa[maxn];
ll arr[maxn], ans;
ll pow(ll x, ll a)
{
    ll y = 1;
    while (a)
    {
        if (a & 1)
            y = y * x % mod;
        x = x * x % mod;
        a >>= 1;
    }
    return y;
}
void init()
{
    fac[0] = ifa[0] = 1;
    for (ll i = 1; i < maxn; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        ifa[i] = pow(fac[i], mod - 2);
    }
}
ll conbination(ll a, ll b)
{
    return fac[a] * ifa[b] % mod * ifa[a - b] % mod;
}
void solve()
{
    ans = 1;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]);
    m = (n + 1) / 2;
    ll a = 0, b = 2;
    if (n & 1)
        --b;
    for (ll i = m + 1; i <= n; ++i)
        if (arr[i])
        {
            printf("0");
            return;
        }
    for (ll i = m; i >= 1; --i)
    {
        a = arr[i];
        if (a > b)
        {
            printf("0");
            return;
        }
        ans = ans * conbination(b, a) % mod;
        b += 2;
        b -= arr[i];
        // printf("%lld ", b);
    }
    if (b > 2)
    {
        printf("0");
    }
    else
        printf("%lld", ans);
}
int main()
{
    init();
    scanf("%lld", &t);
    while (t--)
    {
        solve();
        if (t)
            printf("\n");
    }
    return 0;
}