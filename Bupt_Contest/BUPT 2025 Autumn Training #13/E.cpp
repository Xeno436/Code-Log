#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define lb(x) (x & -x)
ll const maxn = 5e5 + 7;
ll n, m;
ll ans[maxn];
struct ele
{
    ll v, id;
} e[maxn];
bool cmp(ele a, ele b)
{
    if (a.v == b.v)
        return a.id < b.id;
    return a.v < b.v;
}
ll t[maxn];
void insert(ll x)
{
    while (x <= n)
    {
        t[x]++;
        x += lb(x);
    }
}
ll query(ll x)
{
    ll res = 0;
    while (x >= 1)
    {
        res += t[x];
        x -= lb(x);
    }
    return res;
}
ll tot;
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &e[i].v);
        e[i].id = i;
    }
    sort(e + 1, e + n + 1, cmp);
    for (ll i = 1; i <= n; ++i)
    {
        ans[e[i].id] = e[i].v * (i - 1) - tot + query(e[i].id);
        if (ans[e[i].id] > m)
            ans[e[i].id] = -1;
        insert(e[i].id);
        tot += e[i].v;
    }
    for (ll i = 1; i <= n; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}