#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;
#define ll long long
ll t, a, b, n;
set<ll> s;
ll pow(ll x, ll y)
{
    ll res = 1, o = x;
    while (y)
    {
        if (y % 2)
            res = res * o % a;
        o = o * o % a;
        y >>= 1;
    }
    return res;
}
int main()
{
    // a = 314;
    // cout << pow(159, 312);
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &a, &b, &n);
        if (b % a == 0)
        {
            puts("No");
            continue;
        }
        ll x = n, c = pow(b, a - 2);
        cout << b << a - 2 << c << endl;
        s.clear();
        bool flag = false, res = false;
        while (true)
        {
            if (x % a == 0)
            {
                x /= a;
                res = true;
            }
            else
            {
                ll d = a - (x % a);
                cout << c << ' ' << d << endl;
                printf("%d %d %d %d %d\n", x, n, x + b * (c * d % a), n % b, x % b);
                if (res and x <= n and n <= x + b * (c * d % a) and ((n % b) == (x % b)))
                {
                    puts("Yes");
                    flag = true;
                    break;
                }
                x += b * (c * d % a);
                assert(x % a == 0);
                x /= a;
                res = true;
            }
            cout << x << endl;
            if (s.find(x) != s.end())
                break;
            s.insert(x);
        }
        if (!flag)
            puts("No");
    }
    return 0;
}
/*
1
314 159 2653
*/