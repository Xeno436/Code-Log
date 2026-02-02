/*
mul 9
digit
digit (9)
add
*/
#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
ll t, n, m;
ll l, r, mid;
void solve()
{
    l = 1, r = 16;
    scanf("%lld", &n);
    printf("mul 9\n");
    fflush(stdout);
    scanf("%lld", &m);
    printf("digit\n");
    fflush(stdout);
    scanf("%lld", &m);
    printf("digit\n");
    fflush(stdout);
    scanf("%lld", &m);

    printf("add %lld\n", n - 9);
    fflush(stdout);
    scanf("%lld", &m);

    printf("!\n");
    fflush(stdout);
    scanf("%lld", &m);
}
int main()
{
    scanf("%lld", &t);
    for (int i = 1; i <= t; ++i)
        solve();
    return 0;
}
/*
现有一个初始数x属于[1, 1e9](你不知道具体是什么)和一个目标数y(你知道)
你有一下四种操作
1. add a(a可以为负数), 令b = x + a, 若1 <= b <= 1e18 则令x = b
2. mul a(a为正整数), 令b = x * a, 若1 <= b <= 1e18 则令x = b
3. div a(a为正整数), 若b被a整除, 令b = x / a, 若1 <= b <= 1e18 则令x = b
4. digit, 将x更新为各位数字之和(例如12345 -> 15, 8372 -> 20)
求出理论最小操作数,使得x等于y
*/