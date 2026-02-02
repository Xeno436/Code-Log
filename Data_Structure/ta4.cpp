#include <iostream>
using namespace std;
#define ll long long
ll const maxn = 4100;
ll n, m;
ll t[4][maxn][maxn];
ll lb(ll x)
{
    return x & -x;
}
void mod(ll o, ll x, ll y, ll k)
{
    for (ll i = x; i <= n; i += lb(i))
        for (ll j = y; j <= m; j += lb(j))
            t[o][i][j] += k;
}
void mod(ll x, ll y, ll k)
{
    if (x * y == 0)
        return;
    mod(0, x, y, k);
    mod(1, x, y, k * x);
    mod(2, x, y, k * y);
    mod(3, x, y, k * x * y);
}
ll qua(ll o, ll x, ll y)
{
    ll ans = 0;
    for (ll i = x; i > 0; i -= lb(i))
        for (ll j = y; j > 0; j -= lb(j))
            ans += t[o][i][j];
    return ans;
}
ll qua(ll x, ll y)
{

    if (x * y == 0)
        return 0ll;

    return qua(0, x, y) * (x + 1) * (y + 1) + qua(3, x, y) - qua(1, x, y) * (y + 1) - qua(2, x, y) * (x + 1);
}

int main()
{
    scanf("%lld%lld", &n, &m);
    ll o, a, b, c, d, x;
    while (scanf("%lld", &o) != EOF)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        if (o == 1)
        {
            // scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
            scanf("%lld", &x);
            mod(c + 1, d + 1, x);
            mod(a, b, x);
            mod(a, d + 1, -x);
            mod(c + 1, b, -x);
        }
        else
        {
            // scanf("%lld%lld", &a, &b);
            // c = a, d = b;
            // printf("%lld %lld %lld %lld ", qua(c, d), qua(a - 1, b - 1), qua(a - 1, d), qua(c, b - 1));
            printf("%lld\n", qua(c, d) + qua(a - 1, b - 1) - qua(a - 1, d) - qua(c, b - 1));
        }
    }
}