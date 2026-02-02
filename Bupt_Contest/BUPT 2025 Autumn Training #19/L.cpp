#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 2e2 + 7;
int t, n, m;
string s, r[maxn << 1];
int a[maxn][maxn];
int c[maxn << 1][2];
// int d[maxn];
int res = 0;
bool check(bool o)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == o)
                return false;
    return true;
}
void solve(bool o)
{
    // for (int j = 1; j <= n; ++j)
    // {
    //     d[j] = 0;
    //     for (int i = 1; i <= n; ++i)
    //         if (a[i][j] == o)
    //             d[j] = i;
    // }
    bool flag = 0;
    while (true)
    {
        if (check(o))
            return;
        res++;
        a[1][1] ^= 1;
        for (int j = 1, i = 1, k; j <= m; ++j)
        {
            if (j == m and i == 1)
                flag = true;
            if (j == m)
            {
                while (i < n)
                {
                    r[res].push_back('D');
                    i++;
                    a[i][j] ^= 1;
                }
                break;
            }
            for (k = n; k >= 1; --k)
                if (a[k][j] == o)
                    break;
            if (k == 0)
            {
                r[res].push_back('R');
                a[i][j + 1] ^= 1;
                continue;
            }
            while (i < k)
            {
                r[res].push_back('D');
                i++;
                a[i][j] ^= 1;
            }
            r[res].push_back('R');
            a[i][j + 1] ^= 1;
        }
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            cin >> s;
            for (int j = 1; j <= m; ++j)
            {
                a[i][j] = (s[j - 1] == 'W');
                c[i + j][a[i][j]]++;
            }
        }
        bool flag[2] = {0, 0};
        for (int i = 3; i <= n + m; ++i)
        {
            if ((c[i][0] - c[2][0]) % 2)
                flag[0] = 1;
            if ((c[i][1] - c[2][1]) % 2)
                flag[1] = 1;
            // cout << c[i][1] << ' ';
        }
        // cout << flag[0] << flag[1] << endl;
        if (flag[0] and flag[1])
        {
            puts("NO");
        }
        else
        {
            puts("YES");
            res = 0;
            if (flag[0] == 0)
                solve(0);
            else
                solve(1);
            printf("%d\n", res);
            for (int i = 1; i <= res; ++i)
            {
                cout << r[i] << endl;
                r[i].clear();
            }
        }
        for (int i = 2; i <= n + m; ++i)
            c[i][0] = c[i][1] = 0;
    }
    return 0;
}