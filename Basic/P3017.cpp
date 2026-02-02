#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 5e2 + 7;
int N, M, n, m;
int a[maxn][maxn], b[maxn][maxn];
int l, r, mid;
int sum(int l, int r, int c, int d)
{
    return b[r][d] - b[l - 1][d] - b[r][c - 1] + b[l - 1][c - 1];
}
bool solve(int x, int l, int r)
{
    int cnt = 0, c = 1, d = 1;
    while (cnt < m and d <= M)
    {
        while (sum(l, r, c, d) < x and d <= M)
            d++;
        if (d > M)
            break;
        cnt++;
        c = d = d + 1;
    }
    if (cnt < m)
        return false;
    return true;
}
bool solve(int x)
{
    int cnt = 0, l = 1, r = 1;
    while (cnt < n and r <= N)
    {
        while (!solve(x, l, r) and r <= N)
            r++;
        if (r > N)
            break;
        cnt++;
        l = r = r + 1;
    }
    if (cnt < n)
        return false;
    return true;
}
int main()
{
    scanf("%d%d%d%d", &N, &M, &n, &m);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            scanf("%d", &a[i][j]);
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
            r += a[i][j];
        }
    while (r - l > 5)
    {
        mid = l + (r - l >> 1);
        if (solve(mid))
            l = mid;
        else
            r = mid;
    }
    while (l < r)
    {
        mid = l + (r - l + 1 >> 1);
        if (solve(mid))
            l = mid;
        else
            r = mid - 1;
    }
    // for (int i = r; i >= l; --i)
    // {
    //     if (solve(i))
    //     {
    //         printf("%d", i);
    //         break;
    //     }
    // }
    printf("%d", l);
    return 0;
}