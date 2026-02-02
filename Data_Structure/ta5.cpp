// 全局第k小
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll const maxn = 1e5 + 7;
ll n, m, len;
ll a[maxn], t[maxn];
struct oper
{
    bool type;
    ll x, k;
} o[maxn];
ll tmp[maxn << 1ll];
void uni()
{
    for (ll i = 1; i <= n; ++i)
        tmp[i] = a[i];
    len = n;
    for (ll i = 1; i <= m; ++i)
        if (o[i].type)
            tmp[++len] = o[i].k;
    printf("%lld\n", len);
    sort(tmp + 1, tmp + len + 1);
    len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
    for (ll i = 1; i <= n; ++i)
        a[i] = lower_bound(tmp + 1, tmp + len, a[i]) - tmp;
    for (ll i = 1; i <= m; ++i)
        if (o[i].type)
            o[i].k = lower_bound(tmp + 1, tmp + len, o[i].k) - tmp;
    for (int i = 1; i <= len; ++i)
        printf("%lld ", tmp[i]);
    printf("\n");
}
ll lb(ll x)
{
    return x & -x;
}
void mod(ll x, ll k)
{
    if (x == 0)
        return;
    for (ll i = x; i <= len; i += lb(i))
        t[i] += k;
}
ll qua(ll k)
{
    ll sum = 0;
    ll x = 0, i = 1;
    while (i << 1 <= len)
        i = i << 1;
    while (true)
    {
        printf("%lld %lld %lld\n", x, i, sum);
        while (i and sum + t[x + i] >= k)
        {
            i = i >> 1;
        }
        if (i == 0)
        {
            printf("%lld %lld %lld %lld\n", x, i, sum, k);
            if (sum != k)
                x++;
            // return x;
            return tmp[x];
        }
        sum += t[x + i];
        x += i;
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= m; ++i)
    {
        scanf("%d", &o[i].type);
        if (o[i].type)
            scanf("%lld%lld", &o[i].x, &o[i].k);
        else
            scanf("%lld", &o[i].k);
    }
    uni();
    for (ll i = 1; i <= n; ++i)
        mod(a[i], 1);
    printf("%lld\n", t[2]);
    for (ll i = 1; i <= m; ++i)
    {
        if (o[i].type)
        {
            mod(a[o[i].x], -1);
            mod(o[i].k, 1);
            a[o[i].x] = o[i].k;
            printf("%lld\n", t[2]);
        }
        else
        {
            printf("%lld\n", qua(o[i].k));
        }
    }
    return 0;
}
/*
5 5
2 5 4 8 7
0 2
1 3 2
0 2
1 5 3
0 3

4
2
3
*/