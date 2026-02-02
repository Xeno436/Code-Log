#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll const maxn = 1e5 + 7;
ll n, q, r;
vector<ll> e[maxn];
ll dep[maxn], siz[maxn], son[maxn], fat[maxn];
ll top[maxn], dfn[maxn], rnk[maxn], cnt;
void dff(ll u, ll f)
{
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    fat[u] = f;
    for (ll v : e[u])
    {
        if (v == f)
            continue;
        dff(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs(ll u, ll t)
{
    top[u] = t, dfn[u] = ++cnt, rnk[cnt] = u;
    if (son[u])
        dfs(son[u], t);
    for (ll v : e[u])
        if (v != son[u] and v != fat[u])
            dfs(v, v);
}
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + (r - l >> 1))
ll a[maxn], b[maxn];
ll sum[maxn << 2], tag[maxn << 2];
void push_up(ll p, ll l, ll r)
{
    sum[p] = sum[ls] + sum[rs];
}
void push_down(ll p, ll l, ll r)
{
    sum[ls] += tag[p] * (mid - l + 1);
    sum[rs] += tag[p] * (r - (mid + 1) + 1);
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        sum[p] = b[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p, l, r);
}
// segment operations
void modify(ll p, ll l, ll r, ll L, ll R, ll K)
{
    if (L <= l and r <= R)
    {
        sum[p] += K * (r - l + 1);
        tag[p] += K;
        return;
    }
    push_down(p, l, r);
    if (L <= mid)
        modify(ls, l, mid, L, R, K);
    if (mid + 1 <= R)
        modify(rs, mid + 1, r, L, R, K);
    push_up(p, l, r);
}
ll quary_sum(ll p, ll l, ll r, ll L, ll R)
{
    if (L <= l and r <= R)
        return sum[p];
    push_down(p, l, r);
    ll ans = 0;
    if (L <= mid)
        ans += quary_sum(ls, l, mid, L, R);
    if (mid + 1 <= R)
        ans += quary_sum(rs, mid + 1, r, L, R);
    return ans;
}
// path operations
void modify(ll u, ll v, ll K)
{
    ll t;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            t = u, u = v, v = t;
        modify(1, 1, n, dfn[top[u]], dfn[u], K);
        u = fat[top[u]];
    }
    if (dep[u] < dep[v])
        t = u, u = v, v = t;
    modify(1, 1, n, dfn[v], dfn[u], K);
}
ll quary_sum(ll u, ll v)
{
    ll t, ans = 0;
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
// subtree operations
void modify(ll u, ll K)
{
    if (u == r)
        modify(1, 1, n, 1, n, K);
    else if (dfn[u] <= dfn[r] and dfn[r] <= dfn[u] + siz[u] - 1)
    {
        ll v = r;
        while (dfn[top[v]] > dfn[u] + 1)
            v = fat[top[v]];
        if (dfn[top[v]] == dfn[u] + 1)
            v = top[v];
        else
            v = rnk[dfn[u] + 1];
        if (1 <= dfn[v] - 1)
            modify(1, 1, n, 1, dfn[v] - 1, K);
        if (dfn[v] + siz[v] <= n)
            modify(1, 1, n, dfn[v] + siz[v], n, K);
    }
    else
        modify(1, 1, n, dfn[u], dfn[u] + siz[u] - 1, K);
}
ll quary_sum(ll u)
{
    if (u == r)
        return quary_sum(1, 1, n, 1, n);
    else if (dfn[u] <= dfn[r] and dfn[r] <= dfn[u] + siz[u] - 1)
    {
        ll v = r, ans = 0;
        while (dfn[top[v]] > dfn[u] + 1)
            v = fat[top[v]];
        if (dfn[top[v]] == dfn[u] + 1)
            v = top[v];
        else
            v = rnk[dfn[u] + 1];
        if (1 <= dfn[v] - 1)
            ans += quary_sum(1, 1, n, 1, dfn[v] - 1);
        if (dfn[v] + siz[v] <= n)
            ans += quary_sum(1, 1, n, dfn[v] + siz[v], n);
        return ans;
    }
    else
        return quary_sum(1, 1, n, dfn[u], dfn[u] + siz[u] - 1);
}
void init()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (ll i = 2, u; i <= n; ++i)
    {
        scanf("%lld", &u);
        e[u].push_back(i);
        e[i].push_back(u);
    }
    dff(1, 0);
    dfs(1, 1);
    for (ll i = 1; i <= n; ++i)
        b[dfn[i]] = a[i];
    build(1, 1, n);
    r = 1;
}
void solve()
{
    scanf("%lld", &q);
    ll o, u, v, k;
    while (q--)
    {
        scanf("%lld", &o);
        if (o == 1)
        {
            scanf("%lld", &u);
            r = u;
        }
        else if (o == 2)
        {
            scanf("%lld%lld%lld", &u, &v, &k);
            modify(u, v, k);
        }
        else if (o == 3)
        {
            scanf("%lld%lld", &u, &k);
            modify(u, k);
        }
        else if (o == 4)
        {
            scanf("%lld%lld", &u, &v);
            printf("%lld\n", quary_sum(u, v));
        }
        else if (o == 5)
        {
            scanf("%lld", &u);
            printf("%lld\n", quary_sum(u));
        }
    }
}
int main()
{
    init();
    solve();
}