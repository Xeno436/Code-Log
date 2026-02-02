#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 5e2 + 7;
int n;
int x[2], y[2];
int tab[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int vis[maxn][maxn][2];
void dfs(int a, int b, int o) // 当前在o
{
    vis[a][b][o] = true;
    int X = x[o], Y = y[o];
    for (int i = 0, c, d; i < 4; ++i)
    {
        c = a + tab[i][0] * X;
        d = b + tab[i][1] * Y;
        if (1 <= c and c <= n and 1 <= d and d <= n and vis[c][d][o ^ 1] == 0)
        {
            // printf("%d %d %d %d %d\n", a, b, c, d, o);
            dfs(c, d, o ^ 1);
        }
    }
    swap(X, Y);
    for (int i = 0, c, d; i < 4; ++i)
    {
        c = a + tab[i][0] * X;
        d = b + tab[i][1] * Y;
        if (1 <= c and c <= n and 1 <= d and d <= n and vis[c][d][o ^ 1] == 0)
        {
            // printf("%d %d %d %d %d\n", a, b, c, d, o);
            dfs(c, d, o ^ 1);
        }
    }
}
int main()
{
    scanf("%d%d%d%d%d", &n, &x[0], &y[0], &x[1], &y[1]);
    dfs(1, 1, 0);
    dfs(1, 1, 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            ans += (vis[i][j][0] | vis[i][j][1]);
            // cout << (vis[i][j][0] | vis[i][j][1]) << ' ';
        }
        // cout << endl;
    }

    printf("%d", ans);
    return 0;
}