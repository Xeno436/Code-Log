// BAC
#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#define ll long long
#define ull unsigned long long
using namespace std;
ll const maxn = 5e3 + 7;
ll n, m;
ll ab(ll x)
{
    if (x < 0)
        x = -x;
    return x;
}
ll psl;
void swap(ll u, ll v)
{
    psl = u, u = v, v = psl;
}
ll x[maxn], y[maxn], a[maxn];
ll e[maxn][maxn];
struct edge
{
    ll u, v;
    bool operator<(edge const &c) const
    {
        ll x = e[u][v] * a[c.u] * a[c.v], y = e[c.u][c.v] * a[u] * a[v];
        if (x == y)
            if (u == c.u)
                return v > c.v;
            else
                return u > c.u;
        return x > y;
    }
} tmp;
bool vis[maxn];
priority_queue<edge> q;
int main()
{
    scanf("%lld", &n);
    m = n;
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld%lld", &x[i], &y[i]);
        a[i] = 1;
    }
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= n; ++j)
        {
            // e[i][j] = (ab(x[i] - x[j]) + ab(y[i] - y[j]));
            // e[i][j] = e[i][j] * e[i][j];
            e[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (i < j)
                q.push({i, j});
        }
    for (ll p = 1; p < n; ++p)
    {
        while (true)
        {
            tmp = q.top();
            q.pop();
            if (!vis[tmp.u] and !vis[tmp.v])
                break;
        }
        ++m;
        ll u = tmp.u, v = tmp.v;
        a[m] = a[u] + a[v];
        printf("%d\n", a[m]);
        // prllf("%d %d %d\n", u, v, e[u][v]);
        vis[u] = vis[v] = true;
        for (ll i = 1; i < m; ++i)
        {
            if (vis[i])
                continue;
            e[i][m] = e[m][i] = e[i][u] + e[i][v];
            // assert(e[i][u] + e[i][v] == e[u][i] + e[v][i]);
            q.push({i, m});
        }
    }
    return 0;
}
/*
4
0 0
0 -1
0 1
0 2
*/