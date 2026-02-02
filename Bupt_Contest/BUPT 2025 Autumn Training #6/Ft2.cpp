// ac
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
ll const maxn = 1e6 + 7;
ll n, m, t, tmp;
ll tab[maxn];
ll a[maxn];
ll dp[10207][107];
vector<ll> v;
bool dfs(ll s, ll x)
{
    // cout << s << ' ' << x << endl;
    if (s == 0)
    {
        if (x == 0)
            return true;
        return false;
    }
    if (s <= 10010 and x <= 100 and dp[s][x] != -1)
        return dp[s][x];
    if (s < x * 2 or s > x * (x + 1))
    {
        if (s <= 10010 and x <= 100)
            dp[s][x] = 0;
        return false;
    }
    for (ll i = min(x, (ll)round(sqrt(s - 2 * x)) + 3); i >= 1; --i)
    {
        if (i * (i + 1) > s or i * (i - 1) > s - 2 * x)
            continue;
        // printf("%lld %lld %lld\n", s, x, i);
        v.push_back(i);
        if (dfs(s - i * (i + 1), x - i))
        {
            if (s <= 10010 and x <= 100)
                dp[s][x] = i;
            return true;
        }
        v.pop_back();
    }
    if (s <= 10010 and x <= 100)
        dp[s][x] = 0;
    return false;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        if ((n * (n + 1) / 2) % 2 == 1 and (m * (m + 1) / 2) % 2 == 1)
        {
            puts("No");
            continue;
        }
        puts("Yes");
        v.clear();
        memset(tab, 0, sizeof(tab));
        if ((n * (n + 1) / 2) % 2 == 0)
        {
            ll s = n * (n + 1) / 2, x = n;
            dfs(n * (n + 1) / 2, n);
            for (auto i : v)
                s -= i * (i + 1), x -= i;
            while (s != 0)
            {
                tmp = dp[s][x];
                v.push_back(tmp);
                s -= tmp * (tmp + 1), x -= tmp;
            }
            // ll sum = 0;
            // for (auto i : v)
            // {
            //    cout << i << ' ';
            // }
            ll t = 1;
            for (auto i : v)
            {
                tab[t] = 1;
                t += i;
            }
            for (ll i = 1; i <= n; ++i)
                a[i] = a[i - 1] ^ tab[i];
            for (ll i = 1; i <= n; ++i)
            {
                for (ll j = 1; j <= m; ++j)
                    printf("%lld ", a[i]);
                puts("");
            }
        }
        else
        {
            ll s = m * (m + 1) / 2, x = m;
            dfs(s, x);
            for (auto i : v)
                s -= i * (i + 1), x -= i;
            while (s != 0)
            {
                tmp = dp[s][x];
                v.push_back(tmp);
                s -= tmp * (tmp + 1), x -= tmp;
            }
            // ll sum = 0;
            // for (auto i : v)
            // {
            //    cout << i << ' ';
            // }
            ll t = 1;
            for (auto i : v)
            {
                tab[t] = 1;
                t += i;
            }
            for (ll i = 1; i <= m; ++i)
                a[i] = a[i - 1] ^ tab[i];
            for (ll i = 1; i <= n; ++i)
            {
                for (ll j = 1; j <= m; ++j)
                    printf("%lld ", a[j]);
                puts("");
            }
        }
    }
}