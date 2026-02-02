#include <iostream>
using namespace std;
int const maxn = 1e5 + 7;
int t, n, m;
int a[maxn];
void solve(int t)
{
    scanf("%d%d", &n, &m);
    bool flag = false;
    scanf("%d", &a[1]);
    for (int i = 2; i <= m; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] <= a[i - 1])
            flag = true;
    }
    if (flag)
    {
        printf("1");
    }
    else
        printf("%d", n - a[m] + 1);
    if (t)
        printf("\n");
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        solve(t);
    }
    return 0;
}