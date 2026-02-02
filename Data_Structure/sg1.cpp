#include <iostream>
using namespace std;
#define ll long long
#define mid (l + (r - l >> 1))
#define ls (p << 1)
#define rs (p << 1 | 1)
ll const maxn = 1e5 + 7;
ll n, m;
ll a[maxn];
ll t[maxn << 2], y[maxn << 2];
void push_down(ll p, ll l, ll r)
{
    if (l == r)
        return;
    y[ls] += y[p];
    y[rs] += y[p];
    t[ls] += y[p] * (mid - l + 1);
    t[rs] += y[p] * (r - mid);
    y[p] = 0;
}
void push_up(ll p, ll l, ll r)
{
    t[p] = t[ls] + t[rs];
}
ll cnt = 0;
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
void mod(ll p, ll l, ll r, ll L, ll R, ll k)
{
    if (L <= l and r <= R)
    {
        t[p] += k * (r - l + 1);
        if (l != r)
            y[p] += k;
        return;
    }
    push_down(p, l, r);
    if (L <= mid)
        mod(ls, l, mid, L, R, k);
    if (mid + 1 <= R)
        mod(rs, mid + 1, r, L, R, k);
    push_up(p, l, r);
}
ll qua(ll p, ll l, ll r, ll L, ll R)
{
    if (L <= l and r <= R)
        return t[p];
    push_down(p, l, r);
    ll ans = 0;
    if (L <= mid)
        ans += qua(ls, l, mid, L, R);
    if (mid + 1 <= R)
        ans += qua(rs, mid + 1, r, L, R);
    return ans;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    ll o, x, y, k;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%lld%lld%lld", &o, &x, &y);
        if (o == 1)
        {
            scanf("%lld", &k);
            mod(1, 1, n, x, y, k);
        }
        else
        {
            printf("%lld\n", qua(1, 1, n, x, y));
        }
    }
    return 0;
}