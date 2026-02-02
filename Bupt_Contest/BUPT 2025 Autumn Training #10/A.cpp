#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll const maxn = 2e5 + 7;
ll n, k;
ll a[maxn];
ll len, lea, leb;
bool check(ll x)
{
    len = lea = leb = 0;
    for (ll i = 1; i <= x; ++i)
    {
        len += a[i] / 3;
        lea += (a[i] % 3 == 1);
        leb += (a[i] % 3 == 2);
    }
    while (lea and leb)
    {
        ++len;
        --lea, --leb;
    }
    while (lea >= 2)
    {
        ++len;
        lea -= 2;
    }
    len += lea + leb;
    return len <= k;
}
int main()
{
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    if (n == 2)
    {
        if (k == 1)
            printf("1");
        else
            printf("2");
        return 0;
    }
    if (k == 1)
    {
        printf("1");
        return 0;
    }
    k -= 2;
    n -= 2;
    ll l = 0, r = n;
    while (r - l >= 5)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    for (ll i = r; i >= l; --i)
        if (check(i))
        {
            printf("%lld", i + 2);
            break;
        }
    return 0;
}