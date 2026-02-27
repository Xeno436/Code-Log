#include <algorithm>
#include <iostream>
using namespace std;
int const maxn = 2e5 + 7, inf = 1e9 + 7;
int t, n;
int a[maxn], b[maxn];
int ans, mx, mn;
int main() {
    scanf("%d", &t);
    while (t--) {
        ans = inf, mx = -1, mn = inf;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
            a[i] = b[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            if (a[i] != b[i]) ans = min(ans, max(mx - a[i], a[i] - mn));
        }
        if (ans == inf) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}