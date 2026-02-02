#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll const maxn = 2e5 + 7;
ll t, n;
ll a[maxn];
ll x, y;
ll mn, mx;
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        x = y = 0;
        mn = 2e9 + 2e5 + 7;
        mx = -mn;
        if (n % 2)
            x = n - 1;
        else
            x = n - 2;
        for (ll i = 1; i <= n; ++i)
        {
            scanf("%lld", &a[i]);
            if (i % 2)
            {
                y += a[i];
                mn = min(mn, 2 * a[i] + i);
                x = max(x, mx - 2 * a[i] + i);
                // printf("%lld ", 2 * a[i] - i - mx);
            }
            else
            {
                y -= a[i];
                x = max(x, 2 * a[i] + i - mn);
                mx = max(mx, 2 * a[i] - i);
                // printf("%lld ", 2 * a[i] + i - mn);
            }
        }
        // printf("%lld", y);
        x += y;
        printf("%lld", x);
        if (t)
            printf("\n");
    }
}
