#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 1e5 + 7;
string a[maxn][2], b[maxn << 1];
int t, n, m, flag;
int ton[maxn << 1][2];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        flag = false;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i][0] >> a[i][1];
            b[i] = a[i][0], b[i + n] = a[i][1];
            ton[i][0] = ton[i][1] = ton[i + n][0] = ton[i + n][1] = 0;
        }
        sort(b + 1, b + 2 * n + 1);
        m = unique(b + 1, b + 2 * n + 1) - b - 1;
        for (int i = n, l, r; i >= 1; --i)
        {
            l = lower_bound(b + 1, b + m + 1, a[i][0]) - b;
            r = lower_bound(b + 1, b + m + 1, a[i][1]) - b;
            // cout << l << ' ' << r << endl;
            if (i != n and a[i][0] != a[i + 1][0] and a[i][1] != a[i + 1][1] and (ton[l][0] or ton[r][1]))
            {
                printf("No\n");
                flag = true;
                break;
            }
            ton[l][0]++, ton[r][1]++;
        }
        if (!flag)
            printf("Yes\n");
    }
}