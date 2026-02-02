#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 1e5 + 7;
int n, m;
int a[maxn];
int o[maxn];
int cnt, cns;
bool cmp(int a, int b)
{
    return a > b;
}
void print(int i)
{
    if (o[i] == 0)
    {
        printf("%d", a[i]);
    }
    else if (o[i] == 1)
    {
        printf("(1+2)");
    }
    else if (o[i] == 2)
    {
        printf("(1+1+1)");
    }
    else if (o[i] == 3)
    {
        printf("2");
    }
    else if (o[i] == 4)
    {
        printf("(1+1)");
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        if (x == 1)
            cnt++;
        else if (x == 2)
            cns++;
        else
            a[++m] = x;
    }
    sort(a + 1, a + m + 1, cmp);
    while (cnt >= 2 or cns >= 1)
    {
        // cout << cnt << cns << endl;
        if (cnt and cns)
        {
            cns--, cnt--;
            a[++m] = 3;
            o[m] = 1;
        }
        else if (cnt >= 3)
        {
            cnt -= 3;
            a[++m] = 3;
            o[m] = 2;
        }
        else if (cns)
        {
            cns--;
            a[++m] = 2;
            o[m] = 3;
        }
        else if (cnt >= 2)
        {
            cnt -= 2;
            a[++m] = 2;
            o[m] = 4;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (i != m or (i == m and cnt == 0))
            print(i);
        else
        {
            printf("(");
            print(i);
            printf("+1)");
        }
        if (i != m)
            printf("*");
    }
    return 0;
}