#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 1107;
bool vis[maxn];
int t, n, m, x;
char a[maxn], b[maxn];
bool dfs(int x, bool o)
{
    // printf("%d %d\n", x, o);
    int k;
    for (int i = 0; i < n; ++i)
    {
        k = x ^ (1 << i);
        if (!vis[k])
        {
            vis[k] = true;
            bool tmp = dfs(k, o ^ 1);
            vis[k] = false;
            if (tmp == o)
                return o;
        }
    }
    return o ^ 1;
}
void solve()
{
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &n, &m);
    cin >> a >> b;
    x = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == b[i])
            x += (1 << i);
    vis[x] = true;
    for (int j = 1; j <= m; ++j)
    {
        cin >> a;
        int y = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == '=')
                y += (1 << i);
        }
        vis[y] = true;
    }
    // for (int i = 0; i < 1 << n; ++i)
    //     printf("%d ", vis[i]);
    if (dfs(x, 0))
        puts("Bob");
    else
        puts("Alice");
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
 3
 2 2
 12
 89
 =.
 ==
 3 1
 204
 101
 .==
 3 2
 000
 000
 ...
 ==.
*/