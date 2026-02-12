#include <cstring>
#include <iostream>
using namespace std;
int const maxn = 2e5 + 7;
int t, n;
string s;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cin >> s;
        // if (n == 1 and s[0] == '0')
        // {
        //     puts("");
        // }
        int l = 0, r = -1, t, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ans++;
                t = r - l + 1;
                if (l != 0) t--;
                if (r != n - 1) t--;
                // printf("%d %d %d\n", l, r, t);
                ans += (t + 2) / 3;
                l = i + 1, r = i;
            } else {
                r++;
            }
        }
        t = r - l + 1;
        if (l != 0) t--;
        if (r != n - 1) t--;
        // printf("%d %d %d\n", l, r, t);
        ans += (t + 2) / 3;
        printf("%d\n", ans);
    }
}