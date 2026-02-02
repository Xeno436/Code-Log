#include <iostream>
using namespace std;
int const maxn = 107;
int t, n, a;
bool v[maxn];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        a = 0;
        for (int i = 1, o; i <= n; ++i)
        {
            scanf("%d", &o);
            if (!v[o])
            {
                v[o] = true;
                ++a;
            }
        }
        printf("%d", a * 2 - 1);
        if (t)
            printf("\n");
        for (int i = 1; i < maxn; ++i)
            v[i] = false;
    }
}