#include <iostream>
#include <vector>
using namespace std;
int const maxn = 1e5 + 7;
struct edge
{
    int v, w;
};
vector<edge> e[maxn];
int d1[maxn], d2[maxn], up[maxn];
int n, ans, x, y;
void dfsu(int u, int f)
{
    int v, w;
    for (edge t : e[u])
    {
        v = t.v, w = t.w;
        if (v == f)
            continue;
        dfsu(v, u);
        if (d1[v] + w >= d1[u])
        {
            d2[u] = d1[u];
            d1[u] = d1[v] + w;
        }
        else if (d1[v] + w > d2[u])
            d2[u] = d1[v] + w;
    }
}
void dfsd(int u, int f)
{
    int v, w;
    for (edge t : e[u])
    {
        v = t.v, w = t.w;
        if (v == f)
            continue;
        up[v] = up[u] + w;
        if (d1[v] + w != d1[u])
        {
            if (d1[u] + w > up[v])
                up[v] = d1[u] + w;
        }
        else
        {
            if (d2[u] + w > up[v])
                up[v] = d2[u] + w;
        }
        dfsd(v, u);
    }
}
void solve()
{
    dfsu(1, 0);
    dfsd(1, 0);
    int t;
    for (int i = 1; i <= n; ++i)
    {
        t = d1[i];
        if (up[i] > t)
            t = up[i];
        // printf("%d&%d\n", t, ans);
        if (t < ans)
        {
            ans = t;
            x = i, y = 0;
        }
        else if (t == ans)
            y = i;
    }
    printf("%d", x);
    if (y)
        printf(" %d", y);
    // printf("\n");
}
void init()
{
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        ans += w;
    }
}
int main()
{
    init();
    solve();
    // for (int i = 1; i <= n; ++i)
    //     printf("%d %d\n", d1[i], up[i]);
    return 0;
}
/*
7
1 2 1
1 3 1
2 4 1
2 5 1
3 6 1
4 7 1
*/