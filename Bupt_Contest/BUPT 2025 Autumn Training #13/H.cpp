#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 1e6 + 7;
int t, n, k;
int a[maxn];
bool v[maxn];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            v[a[i]] = true;
        }
        int res = k, tot = 1;
        while (res--)
        {
            while (v[tot])
                tot += 2;
            a[++n] = tot;
            v[tot] = true;
        }
        res = k, tot = 0;
        while (res--)
        {
            while (v[tot])
                tot += 2;
            a[++n] = tot;
            v[tot] = true;
        }
        tot = 0;
        while (v[tot])
            tot++;
        if (tot % 2)
            puts("Bob");
        else
            puts("Alice");
        for (int i = 1; i <= n; ++i)
            v[a[i]] = false;
    }

    return 0;
}
/*
5
 14 5
 7 13 1 6 14 2 16 17 18 19 34 36 20 23
 13 5
 8 10 3 13 14 15 16 17 18 19 20 36 38
 14 5
 14 20 12 6 0 16 8 11 9 17 13 3 5 19
 14 5
 15 7 13 3 1 17 16 14 0 12 4 10 22 53
 14 5
 7 3 4 0 14 15 16 17 18 19 20 21 22 23
*/