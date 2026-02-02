#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll const maxn = 2e5 + 7;
ll t, n, m, ans;
ll a[maxn], b[maxn];
void solve()
{
    scanf("%lld%lld", &n, &m);
    ans = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]), ans += a[i];
    sort(a + 1, a + n + 1);
    for (int j = 1; j <= m; ++j)
        scanf("%lld", &b[j]);
    sort(b + 1, b + m + 1);
    int i = n, j = 1;
    while (i and j <= m)
    {
        if (i - b[j] < 0 or j > m)
            break;
        i = i - b[j];
        // printf("%lld ", i + 1);
        ans -= a[i + 1];
        j++;
    }
    printf("%lld\n", ans);
}
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}