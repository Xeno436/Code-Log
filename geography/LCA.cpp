#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int const maxn = 4e4 + 7, maxm = 18;
int t, n, m;
int fa[maxn][maxm], cost[maxn][maxm], deep[maxn];
struct edge
{
    int v, w;
};
vector<edge> e[maxn];
void dfs(int u, int f)
{
    fa[u][0] = f;
    deep[u] = deep[f] + 1;
    for (int i = 1; i < maxm; ++i)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        cost[u][i] = cost[fa[u][i - 1]][i - 1] + cost[u][i - 1];
    }
    int v, w;
    for (edge t : e[u])
    {
        v = t.v, w = t.w;
        if (v == f)
            continue;
        cost[v][0] = w;
        dfs(v, u);
    }
}
int lca(int x, int y)
{
    int t, c = 0;
    if (deep[x] > deep[y])
    {
        t = x;
        x = y;
        y = t;
    }
    t = deep[y] - deep[x];
    for (int i = 0; t; ++i, t >>= 1)
    {
        if (t & 1)
        {
            c += cost[y][i];
            y = fa[y][i];
        }
    }
    if (x == y)
        return c;
    for (int i = maxm - 1; i >= 0; --i)
        if (fa[x][i] != fa[y][i])
        {
            c += cost[x][i] + cost[y][i];
            x = fa[x][i], y = fa[y][i];
        }
    c += cost[x][0] + cost[y][0];
    x = fa[x][0], y = fa[y][0];
    return c;
}
void solve()
{
    memset(fa, 0, sizeof(fa));
    memset(cost, 0, sizeof(cost));
    memset(deep, 0, sizeof(deep));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    int u, v, w;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}