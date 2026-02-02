#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int const maxn = 1e4 + 7, maxm = 5e4 + 7;
int n, m;
vector<int> adj[maxn], adv[maxn];
// adj存图, adv存连通分量的元素
vector<int> stu;
int dfn[maxn], low[maxn], cnt, mot;
int tar[maxn];
bool ins[maxn], vis[maxn], mem[maxn];
void tarjan(int u)
{
    vis[u] = ins[u] = true;
    stu.push_back(u);
    low[u] = dfn[u] = ++cnt;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        mot++;
        while (stu.back() != u)
        {
            tar[stu.back()] = mot;
            adv[mot].push_back(stu.back());
            ins[stu.back()] = false;
            stu.pop_back();
        }
        tar[stu.back()] = mot;
        adv[mot].push_back(stu.back());
        ins[stu.back()] = false;
        stu.pop_back();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            tarjan(i);
    for (int u = 1; u <= n; ++u)
        for (int v : adj[u])
            if (tar[u] != tar[v])
                mem[tar[u]] = true;

    int ans = 0, cnt0 = 0;
    for (int i = 1; i <= mot; ++i)
        if (!mem[i])
        {
            ++cnt0;
            ans = adv[i].size();
        }
    if (cnt0 == 1)
        printf("%d", ans);
    else
        printf("0");
    return 0;
}