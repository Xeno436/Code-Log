#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int const maxn = 3e5 + 7;
int n;
vector<int> e[maxn];
int rt = 1;
int dep[maxn];
int ans;
void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    if (dep[u] > dep[rt])
        rt = u;
    for (auto v : e[u])
    {
        if (v != f)
            dfs(v, u);
    }
}
void dfi(int u, int f)
{
    int cnt = 0;
    for (auto v : e[u])
    {
        if (v != f)
        {
            dfi(v, u);
            cnt++;
            // cout << v << ' ' << u << endl;
        }
    }
    if (cnt >= 1)
        ans += cnt - 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfi(rt, 0);
    printf("%d", ans);
}