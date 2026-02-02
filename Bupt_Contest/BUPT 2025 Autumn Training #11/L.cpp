#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll const maxn = 2e5 + 7;
ll t, n;
ll a[maxn], b[maxn];
ll res[maxn];
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (ll i = 1; i <= n; ++i)
        {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for (ll i = 1; i <= n; ++i)
            b[i] = b[i - 1] + a[i];
        ll j = n;
        for (ll i = n; i >= 3; --i)
        {
            while (j - i + 1 >= 1 and b[j - 1] - b[j - i] <= a[j])
                j--;
            if (j - i + 1 >= 1)
                res[i] = b[j] - b[j - i];
        }
        for (int i = 1; i <= n; ++i)
            printf("%lld ", res[i]);
        printf("\n");
        for (ll i = 1; i <= n; ++i)
            res[i] = 0;
    }
    return 0;
}
/*
 7
 5
 1 2 3 4 5
 5
 1 2 4 8 16
 5
 2 2 2 2 2
 4
 1 4 10 7
 2
 1 2
 3
 2 3 4
 4
 3 1 2 6
*/