#include <iostream>
#include <algorithm>
#include <cstring>
int const maxn = 17;
int a, b;
int dp[maxn][2];
int s[maxn], tot;
int dfs(int u, bool f6, bool lim, bool f0)
{

    if (u == 0)
        return 1;
    if (f0 == 0 and lim == 0 and dp[u][f6] != -1)
        return dp[u][f6];
    int res = 0;
    for (int i = 0; i <= 9; ++i)
    {
        if (i == 4 or (f6 and i == 2) or (lim and i > s[u]))
            continue;
        res += dfs(u - 1, i == 6, lim and i == s[u], f0 and i == 0);
        // if (f0 and i == 0)
        //     res += dfs(u - 1, 0, lim and i == s[u], 1);
        // else if (lim and i == s[u])
        //     res += dfs(u - 1, i == 6, 1, 1);
        // else
        //     res += dfs(u - 1, )
    }
    if (f0 == 0 and lim == 0)
        dp[u][f6] = res;
    // printf("%d %d %d %d %d\n", u, f6, lim, f0, res);
    return res;
}
int solve(int x)
{
    // puts("*");
    memset(dp, -1, sizeof(dp));
    tot = 0;
    while (x)
    {
        s[++tot] = x % 10;
        x /= 10;
    }
    return dfs(tot, 0, 1, 1);
}
int main()
{
    while (true)
    {
        scanf("%d%d", &a, &b);
        if (a == 0 and b == 0)
            return 0;
        printf("%d\n", solve(b) - solve(a - 1));
    }
}