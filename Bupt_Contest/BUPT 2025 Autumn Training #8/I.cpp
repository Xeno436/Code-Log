#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, ans;
string a, b;
int e[4][4];
int ch(char x)
{
    if (x == 'A')
        return 0;
    else if (x == 'T')
        return 1;
    else if (x == 'C')
        return 2;
    else if (x == 'G')
        return 3;
}
int main()
{
    cin >> a >> b;
    n = a.length();
    for (int i = 0; i < n; ++i)
    {
        e[ch(a[i])][ch(b[i])]++;
    }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            if (i != j)
            {
                int x = min(e[i][j], e[j][i]);
                ans += x;
                e[i][j] -= x, e[j][i] -= x;
            }
        }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                if (i != j and j != k and k != i)
                {
                    int x = min(e[i][j], min(e[j][k], e[k][i]));
                    ans += x * 2;
                    e[i][j] -= x, e[j][k] -= x, e[k][i] -= x;
                }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                for (int l = 0; l < 4; ++l)
                    if (i != j and j != k and k != l and l != i)
                    {
                        int x = min(e[i][j], min(e[j][k], min(e[k][l], e[l][i])));
                        ans += x * 3;
                        e[i][j] -= x, e[j][k] -= x, e[k][l] -= x, e[l][i] -= x;
                    }
    cout << ans;
}