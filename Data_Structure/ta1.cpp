#include <iostream>
#include <algorithm>
using namespace std;
long long const maxn = 1e6 + 7;
long long n, q;
long long a[maxn], c[maxn];
long long lowbit(long long x)
{
    return x & -x;
}
void mod(long long x, long long k)
{
    while (x <= n)
    {
        c[x] += k;
        x += lowbit(x);
    }
}
long long qua(long long x)
{
    long long sum = 0;
    while (x > 0)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
void build()
{
    for (long long i = 1; i <= n; ++i)
    {
        c[i] += a[i];
        c[i + lowbit(i)] += c[i];
    }
}
int main()
{
    scanf("%lld%lld", &n, &q);
    for (long long i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    build();
    for (long long i = 1, o, x, y; i <= q; ++i)
    {
        scanf("%lld%lld%lld", &o, &x, &y);
        if (o == 1)
        {
            mod(x, y);
        }
        else
        {
            printf("%lld\n", qua(y) - qua(x - 1));
        }
    }
    return 0;
}