#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
int const maxn = 32007, maxm = 67;
int n, m, dp[maxn], pre[maxn];
int val[maxm], wei[maxm];
struct item
{
    int v, w, f;
    int s[2], c;
} ite[maxm], tmp;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &ite[i].v, &ite[i].w, &ite[i].f);
        if (ite[i].f)
        {
            ite[ite[i].f].s[ite[ite[i].f].c++] = i;
        }
    }
    int v, w;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = n; j >= 1; --j)
        {
            if (ite[i].f)
                continue;
            v = ite[i].v * ite[i].w;
            w = ite[i].v;
            if (j - w >= 0)
                dp[j] = max(dp[j], dp[j - w] + v);
            if (ite[i].c >= 1)
            {
                v = ite[i].v * ite[i].w + ite[ite[i].s[0]].v * ite[ite[i].s[0]].w;
                w = ite[i].v + ite[ite[i].s[0]].v;
                if (j - w >= 0)
                {
                    dp[j] = max(dp[j], dp[j - w] + v);
                    printf("%d ", dp[j]);
                }
            }
            if (ite[i].c >= 2)
            {
                v = ite[i].v * ite[i].w + ite[ite[i].s[1]].v * ite[ite[i].s[1]].w;
                w = ite[i].v + ite[ite[i].s[1]].v;
                if (j - w >= 0)
                    dp[j] = max(dp[j], dp[j - w] + v);
                v = ite[i].v * ite[i].w + ite[ite[i].s[0]].v * ite[ite[i].s[0]].w + ite[ite[i].s[1]].v * ite[ite[i].s[1]].w;
                w = ite[i].v + ite[ite[i].s[0]].v + ite[ite[i].s[1]].v;
                if (j - w >= 0)
                    dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    printf("%d\n", dp[n]);
}