#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 107;
int t, n, a, b, c, d, x;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
        if (a > c)
            a = n - a, c = n - c;
        if (b > d)
            b = n - b, d = n - d;
        // now a <= c and b <= d
        if (b == d)
            x = c;
        else if (a == c)
            x = d;
        else
        {
            x = max(c, d);
            // if (b + c - 1 >)
            //     x = max(x, n - d);
            // if (c - a < d - b - 1)
            //     x = max(x, n - c);
        }
        printf("%d", x);
        if (t)
            printf("\n");
    }
}