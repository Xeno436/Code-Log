#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll a, b;
ll solve(ll x)
{
    ll res = 0;
    if (x == 0)
        return 0;
    ll l = 1, r = x;
    while (l <= r)
    {
        res += x / l;
        if (l < r and x / l + 1 <= r)
        {
            res += (r - max(l + 1, (x / l + 1)) + 1) * (l - 1);
            // printf("%d %d\n", (r - (x / l + 1) + 1), (l - 1));
            r = x / l;
        }
        ++l;
    }
    return res;
}
int main()
{
    scanf("%lld%lld", &a, &b);
    printf("%lld", solve(b) - solve(a - 1));
}
/*
 5 2
 6 15 9 666 1
 8 4
 13 30 27 20 11 30 19 10
 1000000000000 1000000000000
 999999999999 999999999999
 */