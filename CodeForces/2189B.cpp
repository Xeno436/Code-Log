#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
ll t, n, m, a, b, c, mx;
int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        mx = 0;
        while (n--) {
            scanf("%lld%lld%lld", &a, &b, &c);
            m -= (b - 1) * a;
            if ((a * b - c) > mx) mx = a * b - c;
        }
        if (m <= 0) {
            puts("0");
            continue;
        }
        if (mx <= 0) {
            puts("-1");
            continue;
        }
        printf("%lld\n", (m + mx - 1) / mx);
    }
    return 0;
}