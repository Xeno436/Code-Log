#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int const maxn = 3e4 + 7, maxm = 2e5 + 7;
int n, q;
// struct edge
// {
//     int v, w;
// };
vector<int> e[maxn];
int dep[maxn], siz[maxn], son[maxn], fat[maxn];
int top[maxn], dfn[maxn], rnk[maxn], cnt;
void dff(int u, int f)
{
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    fat[u] = f;
    for (int v : e[u])
    {
        if (v == f)
            continue;
        dff(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs(int u, int t)
{
    top[u] = t, dfn[u] = ++cnt, rnk[cnt] = u;
    if (son[u])
        dfs(son[u], t);
    for (int v : e[u])
        if (v != son[u] and v != fat[u])
            dfs(v, v);
}
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + (r - l >> 1))
int b[maxn];
int mxn[maxn << 2], sum[maxn << 2];
void push_up(int p, int l, int r)
{
    if (mxn[ls] >= mxn[rs])
        mxn[p] = mxn[ls];
    else
        mxn[p] = mxn[rs];
    sum[p] = sum[ls] + sum[rs];
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        mxn[p] = sum[p] = b[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p, l, r);
}
void modify(int p, int l, int r, int X, int K)
{
    if (l == r)
    {
        mxn[p] = sum[p] = K;
        return;
    }
    if (X <= mid)
        modify(ls, l, mid, X, K);
    else
        modify(rs, mid + 1, r, X, K);
    push_up(p, l, r);
}
int quary_max(int p, int l, int r, int L, int R)
{
    if (L <= l and r <= R)
        return mxn[p];
    int ans = -maxn, tmp;
    if (L <= mid)
    {
        tmp = quary_max(ls, l, mid, L, R);
        if (tmp > ans)
            ans = tmp;
    }
    if (mid + 1 <= R)
    {
        tmp = quary_max(rs, mid + 1, r, L, R);
        if (tmp > ans)
            ans = tmp;
    }
    return ans;
}
int quary_sum(int p, int l, int r, int L, int R)
{
    if (L <= l and r <= R)
        return sum[p];
    int ans = 0;
    if (L <= mid)
        ans += quary_sum(ls, l, mid, L, R);
    if (mid + 1 <= R)
        ans += quary_sum(rs, mid + 1, r, L, R);
    return ans;
}
int quary_max(int u, int v)
{
    int t, ans = -maxn;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            t = u, u = v, v = t;
        t = quary_max(1, 1, n, dfn[top[u]], dfn[u]);
        if (t > ans)
            ans = t;
        u = fat[top[u]];
    }
    if (dep[u] < dep[v])
        t = u, u = v, v = t;
    t = quary_max(1, 1, n, dfn[v], dfn[u]);
    if (t > ans)
        ans = t;
    return ans;
}
int quary_sum(int u, int v)
{
    int t, ans = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            t = u, u = v, v = t;
        ans += quary_sum(1, 1, n, dfn[top[u]], dfn[u]);
        u = fat[top[u]];
    }
    if (dep[u] < dep[v])
        t = u, u = v, v = t;
    ans += quary_sum(1, 1, n, dfn[v], dfn[u]);
    return ans;
}
void init()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dff(1, 0);
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[dfn[i]]);
    build(1, 1, n);
}
void solve()
{
    scanf("%d", &q);
    char s[10];
    int u, v;
    while (q--)
    {
        scanf("%s%d%d", &s, &u, &v);
        // printf("*");
        // printf("%s", s);
        // printf("*");
        if (s[1] == 'H')
            modify(1, 1, n, dfn[u], v);
        else if (s[1] == 'M')
        {
            printf("%d\n", quary_max(u, v));
        }
        else if (s[1] == 'S')
        {
            printf("%d\n", quary_sum(u, v));
        }
    }
}
int main()
{
    init();
    solve();
}