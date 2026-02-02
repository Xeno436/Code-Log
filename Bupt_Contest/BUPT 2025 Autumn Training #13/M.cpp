#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int aa = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        aa = aa * 10 + ch - '0', ch = getchar();
    return aa * f;
}
const int mod = 1e9 + 7;
const int M1 = 41;
int n, m, N, M, k;
int f[M1][25][1 << 10], a[M1], b[M1];
int inv[M1], fac[M1];
// 考虑到第i位 顶格状态为s 截止到当前位与n的差值在c
inline int ksm(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
inline int C(int x, int y)
{
    if (x < y)
        return 0;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
inline int dfs(int x, int s, int c)
{
    if (c >= (1 << 10) || c < 0)
        return 0;
    if (!x)
        return (c == 0);
    if (f[x][s][c] != -1)
        return f[x][s][c];
    int res = 0;
    if (b[x])
    {
        for (int i = 0; i <= k; ++i)
            for (int j = max(0ll, i + s - k); j <= min(s, i); ++j)
            {
                res = (res + C(s, j) * C(k - s, i - j) % mod * dfs(x - 1, j, (c - i * (k - i)) * 2 + a[x - 1]) % mod) % mod;
                // printf("%lld %lld %lld\n", i, j, dfs(x - 1, j, (c - i * (k - i)) * 2 + a[x - 1]));
            }
    }
    else
    {
        for (int i = 0; i <= k - s; i++)
        {
            res = (res + C(k - s, i) * dfs(x - 1, s, (c - i * (k - i)) * 2 + a[x - 1]) % mod) % mod;
            // printf("*%lld %lld %lld\n", k - s, i, dfs(x - 1, s, (c - i * (k - i)) * 2 + a[x - 1]));
        }
    }
    return f[x][s][c] = res;
}
main()
{
    // 6 2 3
    // n是和，m是上限，k是元素数
    memset(f, -1, sizeof(f));
    N = read(), M = read(), k = read();
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= k; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[k] = ksm(fac[k], mod - 2);
    for (int i = k - 1; i >= 1; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    while (N)
        a[++n] = N & 1, N >>= 1;
    while (M)
        b[++m] = M & 1, M >>= 1;
    int s = 0;
    while (n >= m)
        s = (s << 1) + a[n], n--;
    cout << dfs(m, k, s);
}