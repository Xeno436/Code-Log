#include <bits/stdc++.h>
#define ll long long
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
int n, m;
string s;
int f[110][110];
inline void sot(int x, int y)
{
    if (f[x][y])
        return;
    f[x][y] = 1;
    printf("%d %d\n", x, y);
    fflush(stdout);
    cin >> s;
    if (s[0] == 's')
    {
        m--;
        if (!m)
            exit(0);
        return;
    }
}
inline void hit(int x, int y)
{
    if (f[x][y])
        return;
    f[x][y] = 1;
    printf("%d %d\n", x, y);
    fflush(stdout);
    cin >> s;
    if (s[0] == 'm')
        return;
    if (s[0] == 's')
    {
        m--;
        if (!m)
            exit(0);
        return;
    }
    for (int i = -4; i <= 4; i++)
    {
        int nx = x + i, ny = y + i;
        if (nx >= 1 && nx <= n)
            sot(nx, y);
        if (ny >= 1 && ny <= n)
            sot(x, ny);
    }
}
main()
{
    n = read(), m = read();
    fflush(stdout);
    for (int i = 1, j = 1; i <= n; i++, j = j % 5 + 1)
        for (int k = j; k <= n; k += 4)
        {
            hit(i, k);
            if (!m)
                return 0;
        }
}