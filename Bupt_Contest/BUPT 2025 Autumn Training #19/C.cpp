#include <iostream>
using namespace std;
int const maxn = 5e5 + 7;
int a[maxn], t, n;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int x = 1;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            if (a[i] > a[x])
                x = i;
        }
        for (int i = 1; i <= n; ++i)
            if (a[i] == a[x])
                printf("%d ", i);
        puts(" ");
    }
}