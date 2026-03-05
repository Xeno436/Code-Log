#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int const maxn = 5e4 + 7, maxm = 1e5 + 7;
int t, n, m;
vector<int> s[maxn];
int v[maxm], u[maxn];
bool flag;
int main() {
    scanf("%d", &t);
    while (t--) {
        flag = true;
        scanf("%d%d", &n, &m);
        for (int i = 1, l; i <= n; ++i) {
            scanf("%d", &l);
            for (int j = 1, k; j <= l; ++j) {
                scanf("%d", &k);
                s[i].push_back(k);
                v[k]++;
            }
        }
        for (int i = 1; i <= m; ++i)
            if (v[i] == 0) flag = false;
        for (int i = 1; i <= n; ++i) {
            for (int x : s[i]) {
                if (v[x] == 1) u[i] = 1;
            }
        }
        if (!flag) {
            puts("NO");
        } else {
            int o = 0;
            for (int i = 1; i <= n; ++i) o += 1 - u[i];
            if (o <= 1)
                puts("NO");
            else
                puts("YES");
        }
        for (int i = 1; i <= n; ++i) {
            s[i].clear();
            u[i] = 0;
        }
        for (int i = 1; i <= m; ++i) v[i] = 0;
    }
    return 0;
}