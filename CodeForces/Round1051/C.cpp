#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int const maxn = 2e5 + 7;
int t, n, cnt;
int d[maxn], ans[maxn];
vector<int> edge[maxn];
queue<int> q;
void sort()
{
    for (int i = 1; i <= n; ++i)
        if (d[i] == 0)
            q.push(i);
    int u;
    while (!q.empty())
    {
        u = q.front();
        ans[u] = ++cnt;
        q.pop();
        for (int v : edge[u])
        {
            // printf("%d ", v);
            d[v]--;
            if (d[v] == 0)
                q.push(v);
        }
        // printf("\n");
    }
}
/*
1 2
5 1
2 4
2 3
*/
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        d[i] = 0, edge[i].clear();
    cnt = 0;
    for (int i = 1, u, v, x, y; i < n; ++i)
    {
        scanf("%d%d%d%d", &u, &v, &x, &y);
        if (x < y)
        {
            // printf("%d %d\n", u, v);
            edge[u].push_back(v);
            d[v]++;
        }
        else
        {
            // printf("%d %d\n", v, u);
            edge[v].push_back(u);
            d[u]++;
        }
    }
    sort();
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
}
int main()
{
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}