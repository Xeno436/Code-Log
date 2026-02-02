#include <cstdio>
using namespace std;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    int i;
    for (i = 1; i <= a; i++)
        ans++;
    for (i = 1; i <= b; i++)
        ans++;
    ans++;
    printf("%d\n", ans);
    return 0;
}