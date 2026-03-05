#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
ll const maxn = 2e5 + 7;
ll t, n, k;
ll a[maxn];
ll l, r;
bool solve(ll k) {
    if (k == 0) return true;
    if (l >= r) return false;
    if (k >= r - l) {
        swap(a[l], a[r]);
        k -= r - l;
        l++, r--;
        return solve(k);
    }
    swap(a[l], a[l + k]);
    return true;
}
int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &k);
        if (k & 1) {
            puts("NO");
            continue;
        }
        for (ll i = 1; i <= n; ++i) a[i] = i;
        l = 1, r = n;
        if (solve(k / 2)) {
            puts("YES");
            for (ll i = 1; i <= n; ++i) printf("%lld ", a[i]);
            puts("");
        } else
            puts("NO");
    }
    return 0;
}