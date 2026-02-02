#include <iostream>
#include <algorithm>
#include <set>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + ((r - l) >> 1))
using namespace std;
int const maxn = 3e5 + 7;
struct ano
{
    int a, b, id;
    ano(int a, int b) : a(a), b(b)
    {
    }
    bool operator<(const ano &x) const
    {
        if (a == x.a)
            return b < x.b;
        return a < x.a;
    }
} g[maxn];
struct bno
{
    int a, b;
    bno(int a, int b) : a(a), b(b)
    {
    }
    bool operator<(const bno &x) const
    {
        if (b == x.b)
            return a < x.a;
        return b < x.b;
    }
};
struct seg
{
    int mni[maxn << 2];
    void build();
};
set<ano> a;
set<bno> b;
int t, n;
int tmp[maxn << 1], m;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        n *= 3;
        m = 2 * n;
        for (int i = 1, x, y; i <= n; ++i)
        {
            scanf("%d%d", &x, &y);
            g[i].a = x, g[i].b = y, g[i].id = i;
            tmp[i] = x;
            tmp[i + n] = y;
        }
        sort(g + 1, g + n + 1);
        sort(tmp + 1, tmp + m + 1);
        m = unique(tmp + 1, tmp + m + 1) - tmp - 1;
        for (int i = 1; i <= n; ++i)
        {
            g[i].a = lower_bound(tmp + 1, tmp + m + 1, g[i].a) - tmp;
            g[i].b = lower_bound(tmp + 1, tmp + m + 1, g[i].b) - tmp;
        }
    }
}