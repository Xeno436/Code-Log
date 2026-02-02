#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 1e5 + 7;
int n, x, y;
int a[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        if (x >= a[i])
            x++;
        else
            x--;
    for (int i = n; i >= 1; --i)
        if (y >= a[i])
            y++;
        else
            y--;
    printf("%d %d", x, y);
}