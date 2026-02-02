#include <bits/stdc++.h>
#define int long long
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
const int M = 1e5 + 10;
int id[M], a[M];
string s[M];
inline bool cmp(int x, int y) { return a[x] < a[y]; }
main()
{
    a[1] = read(), a[2] = read(), a[3] = read();
    if (!((abs(a[1] - a[2]) <= a[3] && a[3] <= a[1] + a[2]) &&
          (abs(a[1] - a[3]) <= a[2] && a[2] <= a[1] + a[3]) &&
          (abs(a[2] - a[3]) <= a[1] && a[1] <= a[2] + a[3])))
    {
        cout << "No";
        return 0;
    }
    int x = (a[1] + a[2] - a[3]) / 2, y = 1000;
    if ((a[1] + a[2] - a[3]) % 2 != 0 || x < 0 || x > min(a[1], a[2]))
    {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < y; i++)
        s[1] += 'a';
    s[2] = s[1];
    for (int i = 0; i < a[1]; i++)
        s[2][i] = 'b';
    s[3] = s[1];
    for (int i = 0; i < x; i++)
        s[3][i] = 'b';
    for (int i = y - (a[2] - x); i < y; i++)
        s[3][i] = 'b';
    cout << "Yes" << '\n';
    cout << s[1] << '\n';
    cout << s[2] << '\n';
    cout << s[3] << '\n';
}