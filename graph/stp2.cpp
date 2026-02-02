#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int const maxn = 1e5 + 7;
int n, m, s;
int dis[maxn], cnt[maxn];
bool vis[maxn];
queue<int> q;
struct edge
{
    int v, w;
};
vector<edge> g[maxn];
bool solve()
{
    for (int i = 1; i <= n; ++i)
        dis[i] = 1e9 + 7;
    dis[s] = 0;
    q.push(s);
    vis[s] = true;
    int u, v, w;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = 0;
        for (edge t : g[u])
        {
            v = t.v, w = t.w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                    cnt[v]++;
                    if (cnt[v] >= n)
                        return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
    }
    solve();
    for (int i = 1; i <= n; ++i)
        printf("%d ", dis[i]);
    return 0;
}