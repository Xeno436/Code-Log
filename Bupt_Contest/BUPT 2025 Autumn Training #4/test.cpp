#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;
inline int read()
{
    int aa = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        aa = aa * 10 + ch - '0', ch = getchar();
    return aa * f;
}
const int M = 1e4 + 10;
int n;
long double b[M];
double a[M];
main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (a[1] = 1; a[1] <= 1e4; a[1]++)
    {
        int x = a[1], d = 0;
        long double res = a[1] * a[1];
        for (int j = 2; j <= n; j++)
        {
            a[j] = round((a[1] * b[j]) / b[1]), res += a[j] * a[j];
            if (x != 1)
                x = __gcd((int)a[j], x);
        }
        res = sqrt(res);
        for (int j = 1; j <= n; j++)
            if (abs(((int)a[j]) / res - b[j]) > 1e-6 || a[j] > 1e4)
            {
                d = 1;
                break;
            }
        if (x == 1 && !d)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << a[i];
                if (i != n)
                    cout << '\n';
            }
            return 0;
        }
    }
}