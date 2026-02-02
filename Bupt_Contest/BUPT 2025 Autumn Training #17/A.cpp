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
int T, n, m, flag;
int vis[M];
vector<int> s[M];
struct node
{
    int x, id;
} a[M], b[M];
inline bool cmp(node A, node B) { return A.x < B.x; }
struct girl
{
    int x, y, id;
    girl(int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id)
    {
    }
    bool operator<(const girl &g) const
    {
        if (y == g.y)
            return x > g.x;
        return y > g.y;
    }
} g[M], tmp;
priority_queue<girl> q;
main()
{
    T = read();
    while (T--)
    {
        n = read() * 3;
        for (int i = 1; i <= n; i++)
            a[i].x = read(), b[i].x = read(), a[i].id = b[i].id = i, g[i] = girl(a[i].x, b[i].x, i);
        sort(a + 1, a + 1 + n, cmp), sort(b + 1, b + 1 + n, cmp);
        for (int i = 1, j = 1; i <= n; i++)
            if (!vis[b[i].id])
            {
                vis[b[i].id] = 1;
                m++;
                s[m].push_back(b[i].id);
                while (a[j].x <= b[i].x && j <= n)
                {
                    if (!vis[a[j].id])
                        q.push(g[a[j].id]);
                    j++;
                }
                while (s[m].size() < 3 and !q.empty())
                {
                    tmp = q.top();
                    q.pop();
                    if (!vis[tmp.id])
                        s[m].push_back(tmp.id), vis[tmp.id] = 1;
                }
                // while (a[j].x <= b[i].x && j <= n && s[m].size() < 3)
                // {
                //     if (!vis[a[j].id])
                //         s[m].push_back(a[j].id), vis[a[j].id] = 1;
                //     j++;
                // }
                if (s[m].size() != 3)
                    flag = 1;
            }
        if (flag)
            cout << "No" << '\n';
        else
        {
            cout << "Yes" << '\n';
            for (int i = 1; i <= m; i++)
            {
                for (int j = 0; j < 3; j++)
                    cout << s[i][j] << " ";
                cout << '\n';
            }
        }
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        for (int i = 1; i <= m; i++)
            s[i].clear();
        m = flag = 0;
        while (!q.empty())
            q.pop();
    }
}