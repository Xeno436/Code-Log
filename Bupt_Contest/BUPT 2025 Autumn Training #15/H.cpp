#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll n, k, x;
ll a[40] = {1};
vector<ll> s;
int main()
{
    for (ll i = 1; i < 40; ++i)
        a[i] = a[i - 1] * 2;
    scanf("%lld%lld", &n, &k);
    while (n--)
    {
        scanf("%lld", &x);
        if (x % 4)
        {
            puts("-1");
            continue;
        }
        s.clear();
        bool lim = true;
        ll i = k + 1;
        while (x and i >= 2)
        {
            if (i > k - s.size() + 1)
                i = k - s.size() + 1;
            lim = ((k - s.size()) == (i - 1));
            if (x >= (i - 2) * a[i])
            {
                if (lim and x > (i - 1) * a[i] - 4)
                {
                    x -= (i - 1) * a[i] - 4;
                    s.push_back(a[i]);
                }
                else if (!lim and x > (i - 1) * a[i])
                {
                    x -= (i - 1) * a[i];
                    s.push_back(a[i]);
                }
                else
                {
                    x = 0;
                    s.push_back(a[i]);
                    break;
                }
            }
            else
            {
                i--;
            }
        }
        if (x)
        {
            puts("-1");
            continue;
        }
        printf("%lld", s.size());
        for (ll a : s)
        {
            printf(" %lld", a);
        }
        printf("\n");
    }
    return 0;
}