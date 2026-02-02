#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll const maxn = 2e5 + 7;
ll n, c;
ll a[maxn], b[maxn];
int main()
{
    scanf("%lld%lld", &n, &c);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    b[n] = 1;
    sort(a + 1, a + n + 1);
    for (ll i = n - 1; i >= 1; --i)
    {
        b[i] = 1;
        if (a[i] == a[i + 1])
            b[i] = b[i + 1] + 1;
    }

    ll j = 1;
    ll ans = 0;
    for (ll i = 1; i <= n; i += b[i])
    {
        while (a[i] + c > a[j] and j <= n)
            j += b[j];
        // while (a[i] + c < a[j] and j <= n)
        // j++;
        if (a[i] + c == a[j] and j <= n)
        {
            // prllf("%d %d\n", i, j);
            ans += b[i] * b[j];
            // j += b[j];
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
    }
    printf("%lld", ans);
    return 0;
}