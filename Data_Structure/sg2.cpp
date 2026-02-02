// Todo
// CF786B
/*
线段树需要的操作：
找全局最小
单点修改值
区间改最小值
*/
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define mid (l + (r - l >> 1))
#define ls (p << 1)
#define rs (p << 1 | 1)
ll const maxn = 1e5 + 7, inf = 1e15 + 7;
ll n, q, s;
ll dis[maxn];
ll val[maxn << 2], poi[maxn << 2], tag[maxn << 2];
struct edge
{
    ll p, w;
};
vector<edge> out[maxn << 2];
ll x[71], cnt;
ll rev(ll p)
{
    cnt = 1;
    while (p)
    {
        x[cnt++] = p & 1;
        p >>= 1;
    }
    cnt--;
    p = 0;
    for (ll i = 1; i <= cnt; ++i)
        p = p << 1 | x[i];
    return p >> 1;
}
void push_up(ll p)
{
    ll son = ls;
    if (val[ls] > val[rs])
        son++;
    val[p] = val[son];
    poi[p] = poi[son];
}
void push_down(ll p, ll l, ll r)
{
    if (l == r)
        return;
    if (tag[p] < tag[ls])
    {
        if (tag[p] < val[ls])
            val[ls] = tag[p];
        tag[ls] = tag[p];
    }
    if (tag[p] < tag[rs])
    {
        if (tag[p] < val[rs])
            val[rs] = tag[p];
        tag[rs] = tag[p];
    }
    tag[p] = 0;
}
void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        val[p] = inf;
        poi[p] = l;
        tag[p] = inf;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p);
}
void mod_single(ll p, ll l, ll r, ll P, ll K)
{
    if (l == r)
    {
        val[p] = K;
        return;
    }
    push_down(p, l, r);
    if (P <= mid)
        mod_single(ls, l, mid, P, K);
    else
        mod_single(rs, mid + 1, r, P, K);
    push_up(p);
}
void mod_seg(ll p, ll l, ll r, ll P, ll K)
{
    if (P == 0)
    {
        if (K < tag[p])
        {
            if (K < val[p])
                val[p] = K;
            tag[p] = K;
        }
        return;
    }
    push_down(p, l, r);
    if (P & 1)
        mod_seg(ls, l, mid, P >> 1, K);
    else
        mod_seg(rs, mid + 1, r, P >> 1, K);
    push_up(p);
}
void add_edge(ll p, ll l, ll r, ll L, ll R, edge K)
{
    if (L <= l and r <= R)
    {
        out[p].push_back(K);
        return;
    }
    if (L <= mid)
        add_edge(ls, l, mid, L, R, K);
    if (mid + 1 <= R)
        add_edge(rs, mid + 1, r, L, R, K);
}
void add(ll p, ll l, ll r, ll L, ll R, ll Ls, ll Rs, ll W)
{
    // L and R mean which seg is start
    // Ls and Rs mean which seg is end
    if (L <= l and r <= R)
    {
        add_edge(1, 1, n, Ls, Rs, {p, W});
        return;
    }
    if (L <= mid)
        add(ls, l, mid, L, R, Ls, Rs, W);
    if (mid + 1 <= R)
        add(rs, mid + 1, r, L, R, Ls, Rs, W);
}
void serch(ll p, ll l, ll r, ll U, ll W)
{
    for (edge t : out[p])
        mod_seg(1, 1, n, rev(p), W + t.w);
    if (l == r)
        return;
    if (U <= mid)
        serch(ls, l, mid, U, W);
    else
        serch(rs, mid + 1, r, U, W);
}
void solve()
{
    build(1, 1, n);
    mod_single(1, 1, n, s, 0);
    for (ll i = 1, u; i <= n; ++i)
    {
        dis[u] = val[1];
        u = poi[1];
        mod_single(1, 1, n, u, inf);
        serch(1, 1, n, u, dis[u]);
    }
}
int main()
{
    scanf("%lld%lld%lld", &n, &q, &s);
    for (ll i = 1, t, u, v, l, r, w; i <= q; ++i)
    {
        scanf("%lld", &t);
        if (t == 1)
        {
            scanf("%lld%lld%lld", &u, &v, &w);
            add(1, 1, n, u, u, v, v, w);
        }
        else if (t == 2)
        {
            scanf("%lld%lld%lld%lld", &u, &l, &r, &w);
            add(1, 1, n, u, u, l, r, w);
        }
        else
        {
            scanf("%lld%lld%lld%lld", &l, &r, &v, &w);
            add(1, 1, n, l, r, v, v, w);
        }
    }
    solve();
    printf("*");
    for (ll i = 1; i <= n; ++i)
        if (dis[i] == inf)
            printf("-1 ");
        else
            printf("%lld ", dis[i]);
    return 0;
}
/*
32 16 8 4 2 1
60 111100
15 1111
54 110110
27 11011
*/