// segment tree
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define mid l + (r - l >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
ll const maxn = 5e5 + 7;
ll id[maxn << 2], arr[maxn];
void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        id[p] = l;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    if (arr[id[ls]] >= arr[id[rs]])
        id[p] = id[ls];
    else
        id[p] = id[rs];
}
ll query(ll p, ll l, ll r, ll L, ll R)
{
    if (L <= l and r <= R)
        return id[p];
    ll res = -5e10, idx, tmp;
    if (L <= mid)
    {
        tmp = query(ls, l, mid, L, R);
        if (arr[tmp] > res)
        {
            res = arr[tmp];
            idx = tmp;
        }
    }
    if (mid + 1 <= R)
    {
        tmp = query(rs, mid + 1, r, L, R);
        if (arr[tmp] > res)
        {
            res = arr[tmp];
            idx = tmp;
        }
    }
    return idx;
}
ll n, K, L, R, ans;
struct seg
{
    ll f, l, r, a, id;
    bool operator<(const seg &b) const
    {
        return a < b.a;
    }
};
priority_queue<seg> q;
int main()
{
    scanf("%lld%lld%lld%lld", &n, &K, &L, &R);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &arr[i]);
        arr[i] = arr[i - 1] + arr[i];
    }
    build(1, 1, n);
    for (ll i = 1, id, l, r; i <= n; ++i)
    {
        l = i + L - 1;
        r = min(n, i + R - 1);
        if (l <= r)
        {
            id = query(1, 1, n, l, r);
            q.push({i, l, r, arr[id] - arr[i - 1], id});
        }
    }
    seg t;
    for (ll i = 1, id; i <= K; ++i)
    {
        t = q.top();
        // printf("%d %d %d %d\n", t.f, t.id, t.l, t.r);
        q.pop();
        ans += t.a;
        if (t.l != t.id)
        {
            id = query(1, 1, n, t.l, t.id - 1);
            q.push({t.f, t.l, t.id - 1, arr[id] - arr[t.f - 1], id});
        }
        if (t.id != t.r)
        {
            id = query(1, 1, n, t.id + 1, t.r);
            q.push({t.f, t.id + 1, t.r, arr[id] - arr[t.f - 1], id});
        }
    }
    printf("%lld", ans);
    return 0;
}
/*
4 3 1 3
3
2
-6
8
*/