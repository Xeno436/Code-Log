#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 1e2 + 7;
int t, n;
int a[maxn];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int o = 1, p = 1;
        for (int i = 1; i <= n; ++i)
        {
            a[i] = p;
            p += o * (n - i);
            o = -o;
        }
        for (int i = n; i >= 1; --i)
            printf("%d ", a[i]);
        printf("\n");
    }
}