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
int n, m = 1;
vector<int> s[60];
main()
{
    n = read();
    if (!n)
    {
        cout << "0";
        return 0;
    }
    while (n)
    {
        s[m].push_back(n & 1);
        n >>= 1;
        if (s[m].size() == 7)
            m++;
    }
    if (s[m].size() == 0)
        m--;
    while (s[m].size() < 7)
    {
        s[m].push_back(0);
    }
    for (int i = m; i >= 1; i--)
    {
        int res = 0;
        if (i != 1)
            res += (1 << 7);
        for (int j = 0; j < s[i].size(); j++)
            res += s[i][j] * (1 << j);
        cout << res;
        if (i != 1)
            cout << " ";
    }
}