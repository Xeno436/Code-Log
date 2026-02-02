#include <iostream>
#include <algorithm>
using namespace std;
int maxn = 1e5 + 7;
int t, n, m, k, s;
int tra[10] = {-2, -1, 0, 1, 0, 1, 2};
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &n, &m, &k, &s);
        int c = 0, d = 0;
        for (int i = 1; i <= n; ++i)
        {
            int a = 0, b = 0;
            for (int j = 1, x; j <= m; ++j)
            {
                scanf("%d", &x);
                a += x, b += tra[x + 3];
            }
            if (a >= k)
                c++;
            else if (b >= k)
                d++;
        }
        // cout << c << ' ' << d << endl;
        printf("%d\n", c + min(s, d));
    }
    return 0;
}
/*
 2
 5 3 2 1
 -3 0 3
 2 -2 -1
 1 1 1
 0 0 0
 -1 -1 -1
 3 2 -1 1
  -1 -2 -3 -3
 1 -3
*/