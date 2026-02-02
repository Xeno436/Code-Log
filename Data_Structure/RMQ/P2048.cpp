// Persistent segment tree
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
ll const maxn = 5e5 + 7;
ll rt[maxn], ls[maxn << 5], rs[maxn << 5], sz[maxn << 5], tot;
ll build(ll l, ll r)
{
    ll u = ++tot;
    if (l == r)
        return u;
    ll mid = l + r >> 1;
    ls[u] = build(l, mid);
    rs[u] = build(mid + 1, r);
    return u;
}
ll insert(ll u, ll l, ll r, ll K)
{
    ll v = ++tot;
    ls[v] = ls[u], rs[v] = rs[u], sz[v] = sz[u] + 1;
    if (l == r)
        return v;
    ll mid = l + r >> 1;
    if (K <= mid)
        ls[v] = insert(ls[u], l, mid, K);
    if (mid + 1 <= K)
        rs[v] = insert(rs[u], mid + 1, r, K);
    return v;
}
ll query(ll u, ll v, ll l, ll r, ll R)
{
    if (l == r)
        return l;
    ll s = sz[rs[v]] - sz[rs[u]];
    // printf("%d %d %d %d\n", l, r, s, R);
    ll mid = l + r >> 1;
    if (s < R)
        return query(ls[u], ls[v], l, mid, R - s);
    else
        return query(rs[u], rs[v], mid + 1, r, R);
}
ll n, m, K, L, R, ans;
ll arr[maxn], tmp[maxn];
void init()
{
    scanf("%lld%lld%lld%lld", &n, &K, &L, &R);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &arr[i]);
        tmp[i] = arr[i] = arr[i - 1] + arr[i];
    }
    sort(tmp + 1, tmp + n + 1);
    m = unique(tmp + 1, tmp + n + 1) - tmp - 1;
    rt[0] = build(1, m);
    for (ll i = 1; i <= n; ++i)
    {
        arr[i] = lower_bound(tmp + 1, tmp + m + 1, arr[i]) - tmp;
        rt[i] = insert(rt[i - 1], 1, m, arr[i]);
    }
}
struct seg
{
    ll f, l, r, a, rk;
    bool operator<(const seg &b) const
    {
        return a < b.a;
    }
};
priority_queue<seg> q;
void solve()
{
    for (ll i = 1, l, r; i <= n; ++i)
    {
        l = i + L - 1;
        r = min(n, i + R - 1);
        // printf("%d %d\n", l, r);
        if (l <= r)
            q.push({i, l, r, tmp[query(rt[l - 1], rt[r], 1, m, 1)] - tmp[arr[i - 1]], 1});
    }
    seg s;
    // printf("%d %d\n", tmp[1], tmp[2]);
    for (ll p = 1; p <= K; ++p)
    {
        s = q.top();
        q.pop();
        // printf("%d %d %d %d %d\n", s.f, s.l, s.r, s.a, s.rk);
        ans += s.a;
        if (s.r - s.l + 1 >= s.rk + 1)
        {
            s.a = tmp[(query(rt[s.l - 1], rt[s.r], 1, m, ++s.rk))] - tmp[arr[s.f - 1]];
            q.push(s);
        }
    }
    printf("%lld", ans);
    // 3 5 -1 7
}
int main()
{
    init();
    solve();
    return 0;
}
