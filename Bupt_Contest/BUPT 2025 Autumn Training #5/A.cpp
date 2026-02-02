#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll const maxn = 1e5 + 7, mod = 998244353;
ll t, n, m1, m2;
ll fac[maxn] = {1};
ll ans, res;
struct node
{
    ll a, b;
} x[maxn];
bool cmp(node a, node b)
{
    if (a.a == b.a)
        return a.b > b.b;
    return a.a < b.a;
}
void solve()
{
    scanf("%lld%lld%lld", &n, &m1, &m2);
    ans = 1, res = 1;
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &x[i].a);
        x[i].b = x[i].a % m2, x[i].a = x[i].a % m1;
        // cout << x[i].a << ' ' << x[i].b << endl;
    }
    sort(x + 1, x + n + 1, cmp);
    ll l = 1;
    for (ll i = 1; i <= n; ++i)
    {
        // cout << x[i].a << ' ' << x[i].b << endl;
        if (x[i].a != x[l].a or x[i].b != x[l].b)
        {
            // printf("%d*%d\n", i, l);
            ans = (ans * fac[i - l]) % mod;
            if (x[i].a < x[l].a or x[i].b > x[l].b)
            {
                res = 0;
                break;
            }
            l = i;
        }
    }
    ans = ans * fac[n - l + 1] % mod;
    printf("%lld\n", ans * res);
}
int main()
{
    scanf("%lld", &t);
    fac[0] = 1;
    for (ll i = 1; i < maxn; ++i)
        fac[i] = fac[i - 1] * i % mod;
    // cout << fac[1] << fac[2];
    while (t--)
    {
        solve();
    }
}
/*
3
 5 2 3
 1 2 3 4 10
 4 2 4
 1 2 3 4
 3 8 9
 1 1 1
*/