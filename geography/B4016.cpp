// 直径
#include <iostream>
#include <vector>
using namespace std;
int const maxn = 1e5 + 7;
int n;
struct edge
{
    int v, w;
};
vector<edge> e[maxn];
int dp[maxn], ans;
void init()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back({v, 1});
        e[v].push_back({u, 1});
    }
}
void solve(int u, int f)
{
    if (e[u].empty())
        return;
    // printf("%d*", u);
    int v, w;
    for (edge t : e[u])
    {
        v = t.v, w = t.w;
        if (v == f)
            continue;
        solve(v, u);
        if (dp[u] + dp[v] + w > ans)
            ans = dp[u] + dp[v] + w;
        if (dp[v] + w > dp[u])
            dp[u] = dp[v] + w;
    }
}
int main()
{
    init();
    // printf("%d\n", e[2].empty());
    solve(1, 0);
    // for (int i = 1; i <= n; ++i)
    //     printf("%d ", dp[i]);
    printf("%d", ans);
    return 0;
}
/*
5
1 2
2 4
4 5
2 3
*/
