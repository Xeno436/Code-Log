#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll const maxn = 5e5 + 7;
ll n, m;
ll a[maxn], t[maxn];
ll tmp[maxn];
void uni()
{
    m = n;
    for (ll i = 1; i <= n; ++i)
        tmp[i] = a[i];
    sort(tmp + 1, tmp + m + 1);
    m = unique(tmp + 1, tmp + m + 1) - tmp - 1;
    for (ll i = 1; i <= n; ++i)
        a[i] = lower_bound(tmp + 1, tmp + m + 1, a[i]) - tmp;
}
ll lb(ll x)
{
    return x & -x;
}
void mod(ll x, ll k)
{
    for (ll i = x; i <= n; i += lb(i))
        t[i] += k;
}
ll qua(ll x)
{
    if (!x)
        return 0;
    ll ans = 0;
    for (ll i = x; i > 0; i -= lb(i))
        ans += t[i];
    return ans;
}
ll solve()
{
    ll ans = 0;
    for (ll i = n; i >= 1; --i)
    {
        ans += qua(a[i] - 1);
        mod(a[i], 1);
    }
    return ans;
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    uni();
    printf("%lld", solve());
    return 0;
}