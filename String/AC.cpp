#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int const maxn = 2e6 + 7, maxm = 26;
int n;
string c[maxn], s;
int cnt, fal[maxn], son[maxn][maxm], idx[maxn], deg[maxn], ans[maxn];
void insert(string a, int x)
{
    int u = 0;
    int len = a.length();
    for (int i = 0; i < len; ++i)
    {
        if (!son[u][a[i] - 'a'])
            son[u][a[i] - 'a'] = ++cnt;
        u = son[u][a[i] - 'a'];
    }
    idx[x] = u;
}
void build()
{
    queue<int> q;
    for (int i = 0; i < maxm; ++i)
        if (son[0][i])
            q.push(son[0][i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < maxm; ++i)
        {
            if (son[u][i])
            {
                q.push(son[u][i]);
                fal[son[u][i]] = son[fal[u]][i];
                ++deg[son[fal[u]][i]];
            }
            else
                son[u][i] = son[fal[u]][i];
        }
    }
}
void match(string s)
{
    int u = 0;
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        u = son[u][s[i] - 'a'];
        ++ans[u];
    }
}
void calculate()
{
    queue<int> q;
    for (int i = 1; i <= cnt; ++i)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();

        q.pop();
        ans[fal[u]] += ans[u];
        --deg[fal[u]];
        if (deg[fal[u]] == 0)
            q.push(fal[u]);
    }
}
void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        insert(c[i], i);
    }
    build();
    cin >> s;
}
void solve()
{
    match(s);
    calculate();
    for (int i = 1; i <= n; ++i)
    {
        printf("%d\n", ans[idx[i]]);
    }
}
int main()
{
    init();
    solve();
    return 0;
}