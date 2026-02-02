#include <iostream>
#include <algorithm>
#include <cstring>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + (r - l >> 1))
#define ll long long
ll const maxn = 1e5 + 7;
ll n, m;
ll a[maxn], t[maxn << 2], tag[maxn << 2];
void push_up(ll p, ll l, ll r)
{
    t[p] = t[ls] + t[rs];
}
void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        t[p] = a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p, l, r);
}
void push_down(ll p, ll l, ll r)
{
    tag[ls] += tag[p], tag[rs] += tag[p];
    t[ls] += tag[p] * (mid - l + 1), t[rs] += tag[p] * (r - mid);
}
void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        t[p] = a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p, l, r);
}

void push_down(ll p, ll l, ll r)
{
    tag[ls] += tag[p], tag[rs] += tag[p];
    t[ls] += tag[p] * (mid - l + 1), t[rs] += tag[p] * (r - mid);
}
void modify(ll p, ll l, ll r, ll L, ll R, ll K)
{
    if (L <= l and r <= R)
    {
        tag[p] += K;
        t[p] += K * (r - l + 1);
        return;
    }
    push_down(p, l, r);
    if (L <= mid)
        modify(ls, l, mid, L, R, K);
    if (mid + 1 <= R)
        modify(rs, mid + 1, r, L, R, K);
    push_up(p, l, r);
}
ll query(ll p, ll l, ll r, ll L, ll R)
{
    if (L <= l and r <= R)
    {
        return t[p];
    }
    push_down(p, l, r);
    ll res = 0;
    if (L <= mid)
        res += query(ls, l, mid, L, R);
    if (mid + 1 <= R)
        res += query(rs, mid + 1, r, L, R);
    return res;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    for (ll i = 1, o, x, y, k; i <= m; ++i)
    {
        scanf("%lld%lld%lld", &o, &x, &y);
        if (o == 1)
        {
            scanf("%lld", &k);
            modify(1, 1, n, x, y, k);
        }
        else
            printf("%lld\n", query(1, 1, n, x, y));
    }
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
*/