#include <iostream>
#define ll long long
using namespace std;
ll t, n;
ll c[10][2];
bool check(ll a, ll b)
{
    for (int i = 0; i < 10; ++i)
        c[i][0] = c[i][1] = 0;
    while (a)
    {
        // cout << a % 10 << ' ';
        c[a % 10][0]++;
        a /= 10;
    }
    // puts("");
    while (b)
    {
        // cout << b % 10 << ' ';
        c[b % 10][1]++;
        b /= 10;
    }
    // puts("");
    for (int i = 0; i < 10; ++i)
        if (c[i][0] != c[i][1])
            return false;
    return true;
}
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        ll res = 0;
        for (ll i = 2; i < 10; ++i)
            if ((n % i == 0) and check(n, n / i))
            {
                res++;
                // cout << i;
            }
        printf("%lld\n", res);
    }
    return 0;
}