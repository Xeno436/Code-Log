#include <iostream>
using namespace std;
#define ll long long
ll const maxn = 1e6 + 7;
ll n, q;
ll a[maxn], d[maxn], tl[maxn], tr[maxn];
ll lb(ll x)
{
    return x & -x;
}
void build()
{
    for (ll i = 1; i <= n; ++i)
    {
        d[i] = a[i] - a[i - 1];
        tl[i] += d[i];
        tr[i] += d[i] * i;
        if (i + lb(i) <= n) // 33pts
        {
            tl[i + lb(i)] += tl[i];
            tr[i + lb(i)] += tr[i];
        }
    }
}
void mod(ll x, ll k)
{
    ll l = k * x;
    while (x <= n)
    {
        tl[x] += k;
        tr[x] += l;
        x += lb(x);
    }
}
ll qua(ll x) // x * (r + 1) - x * i;
{
    ll ans = 0, r = x;
    while (x > 0)
    {
        ans = ans + tl[x] * (r + 1ll) - tr[x];
        x -= lb(x);
    }
    return ans;
}
int main()
{
    scanf("%lld%lld", &n, &q);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        // mod(i, a[i] - a[i - 1]);
    }
    build();
    for (ll i = 1, o, x, y, z; i <= q; ++i)
    {
        scanf("%lld%lld", &o, &x);
        if (o == 1)
        {
            scanf("%lld%lld", &y, &z);
            mod(x, z);
            mod(y + 1ll, -z);
        }
        else
        {
            scanf("%lld", &y);
            printf("%lld\n", qua(y) - qua(x - 1ll));
        }
        // for (int j = 1; j <= n; ++j)
        // printf("%lld %lld*", tl[j], tr[j]);
        // printf("\n");
    }
    return 0;
}