#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
ll const maxn = 2e5 + 7;
ll t, n, k;
struct gloves {
    ll a, b;
} g[maxn];
bool cmp(gloves a, gloves b) {
    // if ((a.a + a.b) == (b.a + b.b)) return a.a < b.a;
    // return (a.a + a.b) > (b.a + b.b);
    return a.b > b.b;
}
int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &k);
        for (int i = 1; i <= n; ++i) scanf("%lld", &g[i].a);
        for (int i = 1; i <= n; ++i) scanf("%lld", &g[i].b);
        for (int i = 1; i <= n; ++i)
            if (g[i].a < g[i].b) swap(g[i].a, g[i].b);
        sort(g + 1, g + n + 1, cmp);
        // for (int i = 1; i <= n; ++i) printf("%lld %lld\n", g[i].a, g[i].b);
        ll ans = 1;
        for (int i = 1; i < k; ++i) ans += g[i].b;
        for (int i = 1; i <= n; ++i) ans += g[i].a;
        printf("%lld\n", ans);
    }
    return 0;
}