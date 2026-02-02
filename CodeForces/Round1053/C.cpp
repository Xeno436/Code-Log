#include <iostream>
using namespace std;
#define ll long long
ll const maxn = 2e5 + 7;
ll t, n, x, y;
ll a[maxn << 1], tim[maxn], ans[maxn];
void solve()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n * 2; ++i)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= n; ++i)
        tim[i] = a[i + 1] - a[i];
    for (ll i = n * 2; i > n + 1; --i)
        tim[n * 2 - i + 1] += a[i] - a[i - 1];
    ans[n] = 0;
    for (ll i = 1; i <= n; ++i)
        ans[n] += i * tim[i];
    for (ll i = n - 1; i >= 1; --i)
    {
        ans[i] = ans[i + 1] - 2 * tim[i + 1];
        tim[i - 1] += tim[i + 1];
    }
    for (ll i = 1; i <= n; ++i)
    {
        printf("%lld", ans[i]);
        if (i != n)
            printf(" ");
    }
}
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        solve();
        if (t)
            printf("\n");
    }
}
