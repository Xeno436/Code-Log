#include <algorithm>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;
ll t, x, y, mn, ax, ay;
void upd(ll _x, ll _y) {
    // cout << _x << ' ' << _y << endl;
    if ((_x & _y) == 0 and abs(x - _x) + abs(y - _y) < mn) {
        mn = abs(x - _x) + abs(y - _y);
        ax = _x, ay = _y;
    }
}
int main() {
    scanf("%lld", &t);
    while (t--) {
        mn = 1ll << 33;
        scanf("%lld%lld", &x, &y);
        ax = x, ay = y;
        ll i;
        for (i = 29; i >= 0; --i) {
            if (x & (1 << i) and y & (1 << i)) {
                upd((x >> i << i) + (1ll << i), y);
                upd(x, (y >> i << i) + (1ll << i));
                upd(x >> i << i, (y >> i << i) - 1);
                upd((x >> i << i) - 1, y >> i << i);
            }
        }
        printf("%lld %lld\n", ax, ay);
    }
    return 0;
}