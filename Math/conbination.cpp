#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll const maxn = 1e5 + 7, mod = 998244353;
ll fac[maxn], ifa[maxn];
ll pow(ll x, ll a)
{
    ll y = 1;
    while (a)
    {
        if (a & 1)
            y = y * x % mod;
        x = x * x % mod;
        a >>= 1;
    }
    return y;
}
void init()
{
    fac[0] = ifa[0] = 1;
    for (ll i = 1; i < maxn; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        ifa[i] = pow(fac[i], mod - 2);
    }
}
ll conbination(ll a, ll b)
{
    return fac[a] * ifa[b] % mod * ifa[a - b] % mod;
}
int main()
{
    init();
    printf("%lld %lld", conbination(5, 2), conbination(6, 3));
}