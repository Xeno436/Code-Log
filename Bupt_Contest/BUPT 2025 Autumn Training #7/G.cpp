#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const maxn = 3e5 + 7;
ll gcd(ll m, ll n)
{
    if (m % n != 0)
        return 1;
    else
        return gcd(n, m % n);
}
ll num[maxn] = {0};  //????????
ll num2[maxn] = {0}; //??????
int main()
{
    ll k, n;
    scanf("%lld%lld", &n, &k);

    num[1] = 1;
    num2[1] = 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (num[i] == 0 && gcd(1, i) == 1)
        {
            res++;
            num2[i] = 1;
            for (ll p = 1; i * p <= n; p++)
            {
                num[i * p] = 1;
            }
        }
        if (res >= k)
        {
            // for(ll i2 = i; i2 <= n ; i2++) num[i2] = 1;
            printf("YES\n");
            printf("1");
            for (ll i2 = 2; i2 <= n; i2++)
            {
                if (num2[i2] == 1)
                {
                    if (k)
                    {
                        k--;
                        printf(" %lld", i2);
                    }
                }
            }
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}