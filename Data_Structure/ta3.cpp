#include <iostream>
using namespace std;
#define ll long long
ll const maxn = 4100;
ll n, m, q;
ll t[maxn][maxn];
ll lb(ll x)
{
    return x & -x;
}
void mod(ll x, ll y, ll k)
{
    for (ll i = x; i <= n; i += lb(i))
    {
        for (ll j = y; j <= m; j += lb(j))
        {
            t[i][j] += k;
        }
    }
}
ll qua(ll x, ll y)
{
    ll ans = 0;
    for (ll i = x; i > 0; i -= lb(i))
    {
        for (ll j = y; j > 0; j -= lb(j))
        {
            ans += t[i][j];
        }
    }
    return ans;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    ll a, b, c, d, e;
    while (scanf("%lld", &a) != EOF)
    {
        scanf("%lld%lld%lld", &b, &c, &d);
        if (a == 1)
        {
            mod(b, c, d);
        }
        else
        {
            scanf("%lld", &e);
            // printf("%lld %lld %lld %lld ", qua(b, c), qua(d, e), qua(b, e), qua(d, c));
            printf("%lld\n", qua(d, e) + qua(b - 1, c - 1) - qua(b - 1, e) - qua(d, c - 1));
        }
    }
    return 0;
}