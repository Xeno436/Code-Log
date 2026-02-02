#include <bits/stdc++.h>
#define mp make_pair
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
const int M = 1e5 + 10;
int W, m, n = 1, ans;
int w[M], f[M];
priority_queue<int, vector<int>, greater<int>> q[M];
// priority_queue<int, vector<int>> q[M];
vector<int> s[M];
inline void build(int x, int fa)
{
    if (!x)
        return;
    for (int i = 1; i <= x; i++)
    {
        s[fa].push_back(++n);
        w[n] = read();
        build(read(), n);
    }
}
inline void dfs(int now)
{
    for (int i = 0; i < s[now].size(); i++)
    {
        int v = s[now][i];
        dfs(v);
        q[now].push(f[v]);
    }
    while (q[now].size())
    {
        if (f[now] + q[now].top() <= W)
            f[now] += q[now].top(), q[now].pop();
        else
            // f[now] = (f[now] + q[now].top()) % W, ans++, q[now].pop();
            ans += (f[now] + q[now].top()) / W, f[now] = (f[now] + q[now].top()) % W, q[now].pop();
    }
    if (w[now] + f[now] > W)
        ans += (f[now] + w[now]) / W, f[now] = (f[now] + w[now]) % W;
    else
        f[now] += w[now];
    if (now == 1 && f[now])
        ans++;
}
main()
{
    W = read();
    w[n] = read(), build(read(), n);
    dfs(1);
    cout << ans;
}