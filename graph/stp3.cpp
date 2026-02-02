#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int const maxn = 1e5 + 7;
int n, m, s;
int val[maxn << 2], poi[maxn << 2];
void push_up(int p)
{
    if (val[p << 1] < val[p << 1 | 1])
    {
        val[p] = val[p << 1];
        poi[p] = poi[p << 1];
    }
    else
    {
        val[p] = val[p << 1 | 1];
        poi[p] = poi[p << 1 | 1];
    }
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        val[p] = 1e9 + 7;
        poi[p] = l;
        return;
    }
    int mid = l + (r - l >> 1);
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}
void mod(int p, int l, int r, int P, int K)
{
    if (l == r)
    {
        val[p] = K;
        return;
    }
    int mid = l + (r - l >> 1);
    if (l <= P and P <= mid)
        mod(p << 1, l, mid, P, K);
    if (mid + 1 <= P and P <= r)
        mod(p << 1 | 1, mid + 1, r, P, K);
    push_up(p);
}
// qua return val[1];
struct edge
{
    int v, w;
};
vector<edge> e[maxn];
int dis[maxn];
void solve()
{
    build(1, 1, n);
    for (int i = 1; i <= n; ++i)
        dis[i] = 1e9 + 7;
    dis[s] = 0;
    mod(1, 1, n, s, 0);
    for (int i = 1, u, v, w; i <= n; ++i)
    {
        u = poi[1];
        mod(1, 1, n, u, 1e9 + 7);
        for (edge t : e[u])
        {
            v = t.v, w = t.w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                mod(1, 1, n, v, dis[v]);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
    }
    solve();
    for (int i = 1; i <= n; ++i)
        printf("%d ", dis[i]);
}