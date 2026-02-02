#include <iostream>
using namespace std;
int const maxn = 107;
int t, n;
int a[maxn], l, r, c;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    l = 1, r = n, c = 1;
    while (l != r)
    {
        if (a[l] != c and a[r] != c)
        {
            printf("NO\n");
            return;
        }
        if (a[l] == c)
        {
            l++;
        }
        if (a[r] == c)
        {
            r--;
        }
        c++;
    }
    printf("YES\n");
}
int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        solve();
    return 0;
}