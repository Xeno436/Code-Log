#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
ll const maxn = 5e5 + 7, maxw = 32, maxm = 2e7 + 7;
ll n, k;
ll a[maxn];
ll son[maxm][2], siz[maxm], tot;
void insert(ll x)
{
    ll u = 1;
    ++siz[u];
    for (ll i = maxw - 1, y; i >= 0; --i)
    {
        y = x >> i;
        if (!son[u][y & 1])
            son[u][y & 1] = ++tot;
        u = son[u][y & 1];
        ++siz[u];
    }
}
ll query(ll x, ll rk)
{
    ll u = 1, res = 0;
    for (ll i = maxw - 1, y; i >= 0; --i)
    {
        y = x >> i;
        y = y & 1;
        // printf("%lld %lld\n", siz[son[u][y ^ 1]], rk);
        if (siz[son[u][y ^ 1]] >= rk)
        {
            u = son[u][y ^ 1];
            res += 1ll << i;
        }
        else
        {
            rk -= siz[son[u][y ^ 1]];
            u = son[u][y];
        }
    }
    return res;
}
struct seg
{
    ll f, a, rk;
    bool operator<(const seg &b) const
    {
        return a < b.a;
    }
} t;
priority_queue<seg> q;
ll ans;
void init()
{
    tot = 1;
    scanf("%lld%lld", &n, &k);
    insert(0);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        a[i] = a[i - 1] ^ a[i];
        insert(a[i]);
    }
    // for (ll i = 1; i <= 4; ++i)
    // {
    //     printf("(%d)\n", query(a[4], i));
    // }
    q.push({0, query(0, 1), 1});
    for (ll i = 1; i <= n; ++i)
    {
        q.push({i, query(a[i], 1), 1});
    }
    for (ll p = 1; p <= k * 2; ++p)
    {
        t = q.top();
        q.pop();
        ans += t.a;
        // printf("%lld %lld %lld\n", t.f, t.rk, t.a);
        q.push({t.f, query(a[t.f], t.rk + 1), t.rk + 1});
    }
    printf("%lld", ans >> 1);
}
int main()
{
    init();
    return 0;
}
/*
4 3
1 2 3 4
*/