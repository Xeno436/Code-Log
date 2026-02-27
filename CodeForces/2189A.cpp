#include <algorithm>
#include <iostream>
using namespace std;
int const maxn = 1e2 + 7;
int t, n, a, b, x, y, c;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        x = y = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &c);
            if (c <= a)
                ++x;
            else if (c <= b)
                ++y;
        }
        if (x >= y) {
            printf("%d\n", y + ((x - y) / 2));
        } else
            printf("%d\n", x);
    }
    return 0;
}