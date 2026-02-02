#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int const maxn = 2e4 + 7, maxm = 1e5 + 7;
int n, m;
vector<int> edge[maxn];
void add(int u, int v)
{
    edge[u].push_back(v);
    edge[v].push_back(u);
}
int cur;
int low[maxn], dfn[maxn];
bool vis[maxn];
int tmp;
bool ans[maxn];
void tarjan(int u, int f)
{
    low[u] = dfn[u] = ++cur;
    vis[u] = true;
    int c = 0;
    // bool flag = false;
    // fa[u] = f;
    for (int v : edge[u])
    {
        if (!vis[v])
        {
            c++;
            tarjan(v, u);
            if (f and low[v] >= dfn[u] and !ans[u])
                ans[u] = true, tmp++;
            // if (low[v] > dfn[u])
            // {
            //     isbridge[v] = true;
            //     ++cnt_bridge;
            // }
            low[u] = min(low[u], low[v]);
        }
        else
        {
            if (v != f)
                low[u] = min(low[u], dfn[v]);
            // if (v != f || flag)
            //     low[u] = min(low[u], dfn[v]);
            // else
            //     flag = true;
        }
    }
    if (!f and c > 1) // 桥不需这行
        ans[u] = true, tmp++;
}
int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; ++i)
        low[i] = maxn;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            tarjan(i, 0);
    printf("%d\n", tmp);
    for (int i = 1; i <= n; ++i)
        if (ans[i])
            printf("%d ", i);
    return 0;
}