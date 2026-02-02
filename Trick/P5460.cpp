#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)
ll const maxn = 4e5 + 7;
ll n;
ll tag[maxn << 2], siz[maxn << 2];
struct seg
{
    ll l, r, y, o;
} s[maxn];
bool cmp(seg a, seg b)
{
    return a.y < b.y;
}
ll tmp[maxn << 1], tot;
void push_up(ll u, ll l, ll r)
{
    if (!tag[u])
    {
        if (l == r)
            siz[u] = 0;
        else
            siz[u] = siz[ls] + siz[rs];
    }
}
void update(ll u, ll l, ll r, ll L, ll R, ll O)
{
    if (L <= l and r <= R)
    {
        tag[u] += O;
        if (tag[u])
        {
            siz[u] = tmp[r + 1] - tmp[l];
        }
        else
        {
            siz[u] = 0;
        }
        push_up(u, l, r);
        return;
    }
    if (L <= mid)
        update(ls, l, mid, L, R, O);
    if (mid + 1 <= R)
        update(rs, mid + 1, r, L, R, O);
    push_up(u, l, r);
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1, x1, y1, x2, y2; i <= n; ++i)
    {
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        s[i].l = s[i + n].l = x1, s[i].r = s[i + n].r = x2;
        s[i].y = y1, s[i + n].y = y2;
        s[i].o = 1, s[i + n].o = -1;
        tmp[++tot] = x1, tmp[++tot] = x2;
    }
    sort(s + 1, s + n * 2 + 1, cmp);
    sort(tmp + 1, tmp + tot + 1);
    tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
    ll y = 0, ans = 0;
    for (ll i = 1; i <= n * 2; ++i)
    {
        s[i].l = lower_bound(tmp + 1, tmp + tot + 1, s[i].l) - tmp;
        s[i].r = lower_bound(tmp + 1, tmp + tot + 1, s[i].r) - tmp;
        ans += (s[i].y - y) * siz[1];
        // printf("%lld %lld %lld\n", s[i].y, y, siz[1]);
        update(1, 1, tot - 1, s[i].l, s[i].r - 1, s[i].o);
        y = s[i].y;
    }
    printf("%lld", ans);
    return 0;
}