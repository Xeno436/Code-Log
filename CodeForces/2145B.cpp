#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int t, n, m;
int a[3];
string s;
int main() {
    scanf("%d", &t);
    while (t--) {
        a[0] = a[1] = a[2] = 0;
        scanf("%d%d", &n, &m);
        cin >> s;
        for (int i = 0; i < m; ++i) a[s[i] - '0']++;
        for (int i = 1; i <= a[0]; ++i) putchar('-');
        m = n - a[0] - a[1];
        if (a[2] >= m)
            for (int i = 1; i <= m; ++i) putchar('-');
        else if (a[2] * 2 >= m)
            for (int i = 1; i <= m; ++i) putchar('?');
        else {
            for (int i = 1; i <= a[2]; ++i) putchar('?');
            for (int i = 1; i <= m - a[2] * 2; ++i) putchar('+');
            for (int i = 1; i <= a[2]; ++i) putchar('?');
        }
        for (int i = 1; i <= a[1]; ++i) putchar('-');
        puts("");
    }
    return 0;
}
// 14min