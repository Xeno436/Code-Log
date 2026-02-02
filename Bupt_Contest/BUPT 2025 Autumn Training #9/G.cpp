#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int maxn = 1e5 + 7;
ll t, n, k, m;
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &n, &k, &m);
        ll a = n / k;
        ll b = n - a;
        ll c = 1;
        a--;
        if (b >= m)
        {
            c += m;
        }
        else
        {
            c += b;
            m -= b;
            if (a > m)
            {
                a -= m;
                c += m;
            }
            else
            {
                c += a;
                a = 0;
            }
        }
        printf("%lld\n", c + a / 2);
    }
    return 0;
}
/*
2
 4 1 0
 5 3 1
*/