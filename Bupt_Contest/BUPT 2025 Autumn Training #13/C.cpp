#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int const maxn = 2e5 + 7;
vector<int> e[maxn], f[maxn], g[maxn];
int t, n, m;
int ans[maxn];
int fa[maxn], d[maxn];
bool flag;
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
struct edge
{
    int a, b;
} xn[maxn << 2];
int tot;
bool cmp(edge a, edge b)
{
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}
int vis[maxn], res;
bool vmp[maxn];
int cu[maxn];
void topu()
{
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = ++res;
        for (auto v : g[u])
        {
            cu[v]--;
            if (cu[v] == 0)
                q.push(v);
        }
    }
}
int main()
{

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            e[i].clear(), f[i].clear(), g[i].clear(), fa[i] = i, d[i] = 0, vis[i] = 0, vmp[i] = 0, cu[i] = 0;
        flag = false;
        tot = res = 0;
        ans[1] = ans[n] = 1;
        for (int i = 1, u, v; i <= m; ++i)
        {
            scanf("%d%d", &u, &v);
            if (v == 1 or u == n)
                continue;
            e[u].push_back(v);
            f[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (f[i].empty())
                continue;
            int u = f[i][0];
            for (auto v : f[i])
            {
                // cout << v << ' ' << u << '&';
                fa[find(v)] = find(u);
                // cout << find(v) << ' ' << find(u) << endl;
            }
        }
        for (int i = 1; i <= n; ++i)
            find(i);
        // printf("%d ", fa[i]);
        for (int u = 1; u <= n; ++u)
        {
            for (auto v : e[u])
            {
                // cout << fa[u] << '&' << fa[v] << endl;
                xn[++tot] = {fa[u], fa[v]};
            }
        }
        sort(xn + 1, xn + tot + 1, cmp);
        for (int i = 1; i <= tot; ++i)
        {
            if (xn[i].a != xn[i - 1].a or xn[i].b != xn[i - 1].b)
            {
                // cout << xn[i].a << ' ' << xn[i].b << endl;
                g[xn[i].b].push_back(xn[i].a);
                cu[xn[i].a]++;
            }
        }
        topu();
        for (int u = 1; u <= n; ++u)
        {
            // cout << vis[u] << ' ';
            for (auto v : e[u])
            {
                ans[v] = -vis[fa[v]] + vis[fa[u]];
                if (ans[v] == 0)
                    flag = true;
            }
        }
        if (flag)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
            for (int i = 1; i <= n; ++i)
                printf("%d ", ans[i]);
            printf("\n");
        }
    }
}