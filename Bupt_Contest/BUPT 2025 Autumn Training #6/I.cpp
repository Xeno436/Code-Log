#include <iostream>
#include <algorithm>
#define ll long long
#define mid (l + (r - l >> 1))
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
ll const maxn = 4e5 + 7;
ll n, m, x[maxn], y[maxn], t[maxn];
ll res[maxn], k, ans, s;
struct seg
{
    ll pre[maxn << 2], sum[maxn << 2][4], tag[maxn << 2];
    ll tmp[4];
    void mod(ll p, ll k)
    {
        sum[p][(pre[p] + 1) % 4] += k;
    }
    void add_tag(ll p, ll o)
    {
        if (o < 0)
            o += 4;
        tag[p] += o;
        for (ll i = 0; i < 4; ++i)
            tmp[i] = sum[p][(i + o) % 4];
        for (ll i = 0; i < 4; ++i)
            sum[p][i] = tmp[i];
    }
    void push_up(ll p)
    {
        for (ll i = 0; i < 4; ++i)
            sum[p][i] = sum[ls][i] + sum[rs][i];
    }
    void push_down(ll p)
    {
        add_tag(ls, tag[p]);
        add_tag(rs, tag[p]);
        tag[p] = 0;
    }
    void modify(ll p, ll l, ll r, ll x, ll k, ll o) // in x pos, add k * o
    {
        if (l == r)
        {
            mod(p, k * o);
            return;
        }
        push_down(p);
        if (x <= mid)
        {
            modify(ls, l, mid, x, k, o);
            add_tag(rs, o);
        }
        else
        {
            modify(rs, mid + 1, r, x, k, o);
        }
    }
} s1, s2;
void init()
{
    scanf("%lld%lld", &n, &m);
    k = n + m;
    for (ll i = 1; i <= n; ++i)
        scanf("%lld%lld", &x[i], &y[i]), ans += y[i];
    for (ll i = 1; i <= m; ++i)
        scanf("%lld%lld%lld", &t[i], &x[n + i], &y[n + i]);
    for (ll i = 1; i <= k; ++i)
        res[i] = x[i] - y[i];
    sort(res + 1, res + k + 1);
    k = unique(res + 1, res + k + 1) - res - 1;
}
void query()
{
    ll sum = ans;
    sum += s1.sum[1][1] + s1.sum[1][0];
    if (s % 2 == 0)
    {
        sum += s2.sum[1][1] + s2.sum[1][3];
    }
    else
    {
        sum += s2.sum[1][2] + s2.sum[1][0];
    }
    printf("%lld\n", sum);
}
void solve()
{
    for (ll i = 1, u; i <= n; ++i)
    {
        u = lower_bound(res + 1, res + k + 1, x[i] - y[i]) - res;
        if (x[i] - y[i] <= 0)
            s1.modify(1, 1, k, u, x[i], 1), s++;
        else
            s2.modify(1, 1, k, u, x[i], 1);
    }
    query();
    for (ll i = 1, u, v; i <= m; ++i)
    {
        ans += y[n + 1] - y[t[i]];
        u = lower_bound(res + 1, res + k + 1, x[t[i]] - y[t[i]]) - res;
        if (x[t[i]] - y[t[i]] <= 0)
            s1.modify(1, 1, k, u, x[t[i]], -1), s--;
        else
            s2.modify(1, 1, k, u, x[t[i]], -1);
        v = lower_bound(res + 1, res + k + 1, x[n + i] - y[n + i]) - res;
        if (x[n + i] - y[n + i] <= 0)
            s1.modify(1, 1, k, v, x[i], 1), s++;
        else
            s2.modify(1, 1, k, v, x[i], 1);
        query();
    }
}
int main()
{
    init();
    solve();
    return 0;
}