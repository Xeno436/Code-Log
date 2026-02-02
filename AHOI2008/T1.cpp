#include <iostream>
using namespace std;
int const maxn = 1e5 + 7;
int n, a[maxn], b[maxn], t[maxn], c[maxn];
char op;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    cin >> op;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    // printf("%c", op);
    if (op == '+')
    {
        for (int i = n; i >= 1; --i)
        {
            c[i] += a[i] + b[i];
            // printf("%d ", c[i]);
            if (c[i] >= t[i])
            {
                c[i] -= t[i];
                c[i - 1]++;
            }
        }
    }
    else
    {
        for (int i = n; i >= 1; --i)
        {
            c[i] += a[i] - b[i];
            if (c[i] < 0)
            {
                c[i] += t[i];
                c[i - 1]--;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d", c[i]);
        if (i != n)
            printf(" ");
    }
    printf("\n");
    return 0;
}
/*
10
3 2 5 9 8 5 7 4 7 9
1 1 2 7 0 4 2 4 2 6
+
2 1 4 8 9 1 3 0 2 8

 5
*/