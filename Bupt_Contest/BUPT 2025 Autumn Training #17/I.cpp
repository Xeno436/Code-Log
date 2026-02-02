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
const int M = 1e6 + 10;
int n, T, m;
int dep[M], col[M], siz[M];
vector<int> s[M], t[4], k[4];
inline void dfs(int now, int fa)
{
    siz[now] = 1;
    t[dep[now] % 4].push_back(now);
    if (dep[now] & 1)
        col[now] = 0;
    else
        col[now] = 1;
    for (int i = 0; i < s[now].size(); i++)
    {
        int v = s[now][i];
        if (v == fa)
            continue;
        dep[v] = dep[now] + 1;
        dfs(v, now);
        siz[now] += siz[v];
    }
    if (siz[now] == 1)
        k[dep[now] % 4].push_back(now);
}
main()
{
    T = read();
    while (T--)
    {
        n = read() * 2;
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            s[u].push_back(v),
                s[v].push_back(u);
        }
        dfs(1, 1);
        int mx = (t[1].size() + t[3].size() - (t[0].size() + t[2].size()));
        mx = abs(mx) / 2;
        bool flag = 1;
        // printf("%d %d %d %d\n", k[1].size(), k[2].size(), k[3].size(), k[4].size());
        if (t[0].size() + t[2].size() < t[1].size() + t[3].size())
        {
            if (k[1].size() > k[3].size())
            {
                if (k[1].size() < mx)
                {
                    flag = 0;
                }
                else
                    for (int i = 0; i < mx; i++)
                        col[k[1][i]] = 1;
            }
            else
            {
                if (k[3].size() < mx)
                {
                    flag = 0;
                }
                else
                    for (int i = 0; i < mx; i++)
                        col[k[3][i]] = 1;
            }
        }
        else if (t[0].size() + t[2].size() > t[1].size() + t[3].size())
        {
            if (k[0].size() > k[2].size())
            {
                if (k[0].size() < mx)
                {
                    flag = 0;
                }
                else
                    for (int i = 0; i < mx; i++)
                        col[k[0][i]] = 0;
            }
            else
            {
                if (k[2].size() < mx)
                {
                    flag = 0;
                }
                else
                    for (int i = 0; i < mx; i++)
                        col[k[2][i]] = 0;
            }
        }
        if (flag)
        {
            for (int i = 1; i <= n; i++)
                cout << col[i] << " ";
            cout << '\n';
        }
        else
        {
            puts("-1");
        }
        for (int i = 0; i <= n; i++)
            s[i].clear(), dep[i] = col[i] = siz[i] = 0;
        for (int i = 0; i < 4; ++i)
            t[i].clear(), k[i].clear();
    }
}
/*
1
6
1 2
1 3
1 4
1 5
2 6
6 7
6 8
6 9
6 10
7 11
11 12
*/