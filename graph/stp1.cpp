// shortest path
#include <iostream>
using namespace std;
int const maxn = 5e3 + 7;
int n, m, s;
int d[maxn][maxn];
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                d[i][j] = 1e9 + 7;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        if (w < d[u][v])
            d[u][v] = w;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    for (int i = 1; i <= n; ++i)
        printf("%d ", d[s][i]);
    return 0;
}