#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n, m, k;
ll table[10][10];
bool check(int rl, int rr, int cl, int cr)
{
    int o = table[rl][cl];
    for (int i = rl; i <= rr; ++i)
        for (int j = cl; j <= cr; ++j)
            if (table[i][j] != o)
                return false;
    return true;
}
void solve(int x)
{
    for (int i = 0; i < k; ++i)
    {
        table[i / m][i % m] = x & 1;
        x >>= 1;
    }
    int a = 0, b = 0;
    for (int rl = 0; rl < n; ++rl)
        for (int rr = rl; rr < n; ++rr)
            for (int cl = 0; cl < m; ++cl)
                for (int cr = cl; cr < m; ++cr)
                    if (check(rl, rr, cl, cr))
                        a++;
                    else
                        b++;
    if (a == b)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                cout << table[i][j];
            cout << endl;
        }
        cout << endl;
    }
    // cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        k = n * m;
        for (ll i = 0; i < 1 << k; ++i)
            solve(i);
    }
}