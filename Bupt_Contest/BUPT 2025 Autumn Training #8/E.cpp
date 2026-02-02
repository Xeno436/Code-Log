#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
ll const maxn = 3e5 + 7;
ll n;
double r, a, b;
double ru[maxn], cu[maxn], tmp[maxn << 1];
struct st
{
    double idx;
    ll t;
} s[maxn << 1];
bool cmp(st a, st b)
{
    if (a.idx - b.idx < 1e-6)
        return a.t > b.t;
    return a.idx < b.idx;
}
int main()
{
    cin >> n >> r >> a >> b;
    double f = a * a + b * b;
    for (ll i = 1, c, d; i <= n; ++i)
    {
        cin >> c >> d;
        double x = c, y = d;
        if (r * r < (b * x - a * y) * (b * x - a * y) / f)
            continue;
        double len = sqrt(r * r - (b * x - a * y) * (b * x - a * y) / f);
        double x0 = a * a / f * x + a * b / f * y;
        double y0 = a * b / f * x + b * b / f * y;
        double dis = sqrt(x0 * x0 + y0 * y0);
        if (x0 < 0 or ((x0 - 0) < 1e-6 and y0 < 0))
            dis = -dis;
        s[i * 2 - 1].idx = dis - len, s[i * 2 - 1].t = 1;
        s[i * 2].idx = dis + len, s[i * 2].t = -1;
        // ru[i] = tmp[i * 2 - 1] = dis - len;
        // cu[i] = tmp[i * 2] = dis + len;
    }
    sort(s + 1, s + 2 * n + 1, cmp);
    ll ans = 0;
    for (ll i = 1, cnt = 0; i <= n * 2; ++i)
    {
        // cout << s[i].idx << ' ' << s[i].t << endl;
        cnt += s[i].t;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
/*
 7 5 0 1 -1 -1
 1 -1
 0 0
 2 3
 3 4
 10 10
 2 12

  3 1 1 0
 0 0
 2 0
 4 0

  4 1 1 0
 0 0
 1 1
 1 -1
 2 0
*/