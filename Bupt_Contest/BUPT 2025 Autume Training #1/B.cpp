#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll const maxn = 47;
ll t, n, m, k;
bool b[maxn];
char c[maxn], d;
void output(ll k)
{
    if (k / n == 0)
        cout << c[k % n];
    else
    {
        output(k / n);
        cout << c[k % n];
    }
}
int trans(char c)
{
    if ('0' <= c and c <= '9')
        return c - '0';
    else
        return 10 + c - 'A';
}
char snart(int x)
{
    if (0 <= x and x <= 9)
        return '0' + x;
    else
        return 'A' + (x - 10);
}
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &n, &k, &m);
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; ++i)
            b[i] = 1;
        for (int i = 1; i <= m; ++i)
        {
            cin >> d;
            b[trans(d)] = 0;
        }
        int j = 0;
        for (int i = 0; i < n; ++i)
            if (b[i])
                c[j++] = snart(i);
        n = j;
        output(k);
        puts("");
    }
    return 0;
}