// Attraction theory
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll const maxn = 4e5 + 7, mod = 998244353;
ll t, n, ans;
ll fac[maxn], inf[maxn], ins[maxn];
ll a[maxn], pre[maxn];
ll tx, ty, tz;
ll inv(ll x)
{
    tx = 1, tz = x, ty = mod - 2;
    while (ty)
    {
        if (ty & 1)
            tx = tx * tz % mod;
        tz = tz * tz % mod;
        ty = ty >> 1ll;
    }
    return tx;
}
ll cal(ll x, ll y)
{
    // printf("%lld %lld ", x, y);
    x = x + y;
    if (x >= 1 and y >= 1 and y <= x)
    {
        // printf("%lld\n", fac[x - 1] * inf[fac[y - 1]] % mod * inf[fac[x - y]] % mod);
        return fac[x - 1] * ins[y - 1] % mod * ins[x - y] % mod;
    }
    puts("0");
    return 0;
}
ll add(ll x, ll y)
{
    return (x + y) % mod;
}
ll sub(ll x, ll y)
{
    return (x + mod - y) % mod;
}
void solve()
{
    scanf("%lld", &n);
    pre[0] = 0;
    ans = 0;
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        a[i] = a[i] % mod;
        pre[i] = 0;
    }
    if (n == 1)
        pre[1] = 1;
    else
        pre[1] = n + 1, pre[2] = mod - n - 1;
    // for (ll i = 1; i <= n; ++i)
    // {
    //     if (pre[i] >= 990000000)
    //         printf("%lld ", pre[i] - mod);
    //     else
    //         printf("%lld ", pre[i]);
    // }
    // puts("");
    for (ll len = 2, x, y, z; len < n; ++len)
    {
        // printf("\n%lld -> ", len);
        if ((n - len) % 2 == 0)
        {
            z = cal(n - len >> 1ll, len);
            x = z * (n - len >> 1ll) % mod * inf[len] % mod;
            // printf("*%lld*", 3 * inf[3] % mod);
            y = add(x * 2 % mod, z);
            pre[1] = add(pre[1], y);
            pre[n - len + 2] = sub(pre[n - len + 2], y);
            pre[len + 1] = sub(pre[len + 1], y);
            // printf("(%lld) %lld %lld %lld)", len, z, x, y);

            z = cal(n - len - 2 >> 1ll, len);
            x = z * (n - len - 2 >> 1ll) % mod * inf[len] % mod;
            // printf("(%lld) ", x);
            x = x * 2 % mod;
            y = add(x, z);
            pre[1] = add(pre[1], y);
            pre[n - len + 2] = sub(pre[n - len + 2], y);
            pre[len + 1] = sub(pre[len + 1], y);

            // z = z * 2 % mod;
            // pre[1] = add(pre[1], z);
            // pre[2] = sub(pre[2], z);
            // pre[n - len + 1] = add(pre[n - len + 1], z);
            // pre[n - len + 2] = sub(pre[n - len + 2], z);
            // pre[len + 1] = sub(pre[len + 1], z);
            // pre[len + 2] = add(pre[len + 2], z);
            pre[1] = add(pre[1], z);
            pre[2] = sub(pre[2], z);
            // pre[n - len + 1] = add(pre[n - len + 1], z);
            pre[n - len + 2] = sub(pre[n - len + 2], z);
            pre[n - len + 3] = add(pre[n - len + 3], z);
            // pre[len + 1] = sub(pre[len + 1], z);
            // pre[len + 2] = add(pre[len + 2], z);
            pre[len] = add(pre[len], z);
            pre[len + 1] = sub(pre[len + 1], z);
        }
        else
        {
            z = cal(n - len >> 1ll, len);
            x = z * (n - len - 1 >> 1ll) % mod * inf[len] % mod;
            // printf("(%lld) ", x);
            y = add(x * 2 % mod, z);
            y = y * 2 % mod;
            pre[1] = add(pre[1], y);
            pre[n - len + 2] = sub(pre[n - len + 2], y);
            pre[len + 1] = sub(pre[len + 1], y);

            // z = z * 2 % mod;
            // printf("%lld %lld %lld\n", z, x, y);
            pre[1] = add(pre[1], z);
            pre[2] = sub(pre[2], z);
            // pre[n - len + 1] = add(pre[n - len + 1], z);
            pre[n - len + 2] = sub(pre[n - len + 2], z);
            pre[n - len + 3] = add(pre[n - len + 3], z);
            // pre[len + 1] = sub(pre[len + 1], z);
            // pre[len + 2] = add(pre[len + 2], z);
            pre[len] = add(pre[len], z);
            pre[len + 1] = sub(pre[len + 1], z);
        }
        // for (ll i = 1; i <= n; ++i)
        // {
        //     if (pre[i] >= 990000000)
        //         printf("%lld ", pre[i] - mod);
        //     else
        //         printf("%lld ", pre[i]);
        // }
        // puts("");
    }
    for (ll i = 1; i <= n; ++i)
        pre[i] = add(pre[i], pre[i - 1]);
    for (ll i = 1; i <= n; ++i)
        pre[i] = add(pre[i], pre[i - 1]);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i)
        ans = add(ans, pre[i] * a[i] % mod);
    printf("%lld", ans);
    return;
}
void init()
{
    fac[0] = inf[0] = ins[0] = 1;
    for (ll i = 1; i < maxn; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        ins[i] = inv(fac[i]);
    }
    for (ll i = 1; i < maxn; ++i)
        inf[i] = inv(i);
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
}