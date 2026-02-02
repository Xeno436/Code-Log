// ac
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
const int M = 5e3 + 10;
int n, d, ans;
int a[M], b[M];
main()
{
    n = read(), d = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 1; j <= n; j++)
            b[j] = max(a[j], a[i]), b[j] = min(b[j], a[i] + d);
        for (int j = 2; j <= n; j++)
            res += abs(b[j] - b[j - 1]);
        ans = max(ans, res);
    }
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 1; j <= n; j++)
            b[j] = max(a[j], a[i] - d), b[j] = min(b[j], a[i]);
        for (int j = 2; j <= n; j++)
            res += abs(b[j] - b[j - 1]);
        ans = max(ans, res);
    }
    cout << ans;
}