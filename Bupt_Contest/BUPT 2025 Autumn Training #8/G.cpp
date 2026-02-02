#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int const maxn = 2e5 + 7, maxm = 37;
int n, m, t;
int a[2][maxn], o;
int ans;
int cnt;
bool cmp(int a, int b)
{
    return (a & (1 << cnt)) > (b & (1 << cnt));
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &a[o][i]);
    }
    t = n;
    for (int tot = 29; tot >= 0; --tot)
    {
        cnt = tot;
        sort(a[o] + 1, a[o] + t + 1, cmp);
        // if (tot <= 4)
        // {
        //     cout << tot << endl;
        //     for (int i = 1; i <= t; ++i)
        //         cout << a[o][i] << ' ' << (a[o][i] & (1 << tot)) << ' ';
        //     cout << endl;
        // }
        int res = 0;
        for (int i = 1; i <= t; ++i)
        {
            if (a[o][i] & (1 << cnt))
                res++;
            a[o ^ 1][i] = a[o][i];
        }
        if (res >= m)
            t = res, ans |= (1 << (tot));
        o = o ^ 1;
    }
    printf("%d", ans);
}
/*
 5 2
 6 15 9 666 1
 8 4
 13 30 27 20 11 30 19 10
 */