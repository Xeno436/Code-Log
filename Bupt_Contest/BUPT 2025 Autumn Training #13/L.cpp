#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll const q = 998244353, maxn = 1e5 + 7;
ll fac[maxn];
ll t, n, m;
ll pow(ll x, ll y)
{
    // cout << x << ' ' << y << endl;
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % q;
        x = x * x % q;
        y >>= 1;
    }
    // cout << res << endl;
    return res;
}
int main()
{
    fac[0] = 1;
    for (ll i = 1; i < maxn; ++i)
        fac[i] = fac[i - 1] * i % q;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        ll res = fac[n - 1] * pow(fac[m - 1], q - 2) % q * pow(fac[n - m], q - 2) % q * fac[n] % q;
        printf("%lld\n", res);
    }
    return 0;
}