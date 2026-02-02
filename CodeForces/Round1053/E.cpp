#include <iostream>
#include <algorithm>
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + (r - l >> 1))
using namespace std;
ll const maxn = 2e5 + 7, inf = 2e14 + 7;
ll t, n, sum;
ll v[maxn], a[maxn], b[maxn];
ll val[maxn], tmp[maxn], idx[maxn];
ll dp[maxn];
ll tag[maxn << 2], mni[maxn << 2];
void push_up(ll p, ll l, ll r)
{
    mni[p] = min(mni[ls], mni[rs]);
}
void push_down(ll p, ll l, ll r)
{
    mni[ls] += tag[p];
    mni[rs] += tag[p];
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
void build(ll p, ll l, ll r)
{
    tag[p] = 0;
    if (l == r)
    {
        mni[p] = dp[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p, l, r);
}
void modify(ll p, ll l, ll r, ll L, ll R, ll K)
{
    // if (K == 5 - inf and L == 2)
    // {
    //     printf("%lld %lld %lld\n", p, l, r);
    // }
    if (L <= l and r <= R)
    {
        mni[p] += K;
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
ll query(ll p, ll l, ll r, ll L, ll R)
{
    // if (L == R and L == 2)
    // {
    //     printf("%lld*%lld*%lld*%lld\n", p, l, r, mni[p]);
    //     if (l == r)
    //         return mni[p];
    // }
    if (L <= l and r <= R)
        return mni[p];
    push_down(p, l, r);
    ll ans = 2e16 + 7;
    if (L <= mid)
        ans = min(ans, query(ls, l, mid, L, R));
    if (mid + 1 <= R)
        ans = min(ans, query(rs, mid + 1, r, L, R));
    return ans;
}
void solve()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", &v[i]);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        val[i] = v[a[i]];
        tmp[a[i]] = i;
    }
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &b[i]);
        idx[i] = tmp[b[i]];
        sum += v[i];
    }
    dp[0] = 0;
    for (ll i = 1; i <= n; ++i)
        dp[i] = inf;
    build(1, 0, n);
    for (ll i = 1, k, v; i <= n; ++i)
    {
        // for (ll j = 0; j <= n; ++j)
        //     printf("%lld-%lld ", j, query(1, 0, n, j, j));
        // printf("\n");
        k = idx[i], v = val[idx[i]];
        // if (i == 2)
        // {
        //     printf("(%lld %lld)", query(1, 0, n, 0, k), query(1, 0, n, k, k));
        //     printf("*%lld %lld*\n", mni[5], tag[5]);
        // }
        modify(1, 0, n, k, k, query(1, 0, n, 0, k) - query(1, 0, n, k, k));
        // printf("*%lld %lld*\n", mni[5], tag[5]);
        modify(1, 0, n, 0, k - 1, v);
    }
    // printf("%lld %lld\n", query(1, 0, n, 0, n), sum);
    printf("%lld", sum - query(1, 0, n, 0, n));
    sum = 0;
}
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        solve();
        if (t)
            printf("\n");
    }
    return 0;
}