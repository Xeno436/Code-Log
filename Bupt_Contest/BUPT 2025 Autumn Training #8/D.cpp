#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, k;
int a[4], b[4];
string s;
void change()
{
    int x = (a[0] ^ a[1] ^ a[2] ^ a[3]);
    if (a[0] >= (x ^ a[0]))
    {
        // cout << a[0] << ' ' << (x ^ a[0]);
        printf("left %d", a[0] - (x ^ a[0]));
        a[0] ^= x;
    }
    else if (a[1] >= (x ^ a[1]))
    {
        printf("right %d", a[1] - (x ^ a[1]));
        a[1] ^= x;
    }
    else if (a[2] >= (x ^ a[2]))
    {
        printf("top %d", a[2] - (x ^ a[2]));
        a[2] ^= x;
    }
    else if (a[3] >= (x ^ a[3]))
    {
        printf("bottom %d", a[3] - (x ^ a[3]));
        a[3] ^= x;
    }
    printf("\n");
    fflush(stdout);
}
void solve()
{
    if ((a[0] ^ a[1] ^ a[2] ^ a[3]) == 0)
    {
        puts("pass");
        fflush(stdout);
    }
    else
    {
        change();
    }
    while (true)
    {
        cin >> s;
        if (s[0] == 'y')
            break;
        int x;
        cin >> x;
        if (s[0] == 'l')
        {
            a[0] -= x;
        }
        else if (s[0] == 'r')
        {
            a[1] -= x;
        }
        else if (s[0] == 't')
        {
            a[2] -= x;
        }
        else if (s[0] == 'b')
        {
            a[3] -= x;
        }
        change();
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    b[0] = n + 1, b[2] = m + 1;
    for (int i = 1, x, y; i <= k; ++i)
    {
        scanf("%d%d", &x, &y);
        b[0] = min(b[0], x);
        b[1] = max(b[1], x);
        b[2] = min(b[2], y);
        b[3] = max(b[3], y);
    }
    a[0] = b[2] - 1, a[1] = m - b[3], a[2] = b[0] - 1, a[3] = n - b[1];
    // printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
    solve();
} /*
  4 6 2
   2 3
   4  4
  */