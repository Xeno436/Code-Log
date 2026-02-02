#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 1e5 + 7;
string a, b;
int al, bl;
bool check(int x)
{
    if (x < 0 or (al - 2) - x < 0)
        return false;
    // cout << x << ' ';
    if ((al - 2 - x) + (bl - 1) == x /* and (a[x + 1] - '0') * (b[0] - '0') <= 9*/)
        return true;
    if ((al - 2 - x) + (bl - 1) + 1 == x /*and (a[x + 1] - '0') * (b[0] - '0') >= 10*/)
        return true;
    return false;
}
int main()
{
    cin >> a >> b;
    al = a.length(), bl = b.length();
    int m = (al - 2 + bl - 1) >> 1;
    for (int i = m - 2; i <= m + 2; ++i)
        if (check(i))
        {
            for (int j = 0; j <= i; ++j)
                cout << a[j];
            cout << ' ';
            for (int j = i + 1; j < al; ++j)
                cout << a[j];
            return 0;
        }
}