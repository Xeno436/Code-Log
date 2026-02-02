#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
#define ll long long
int const maxn = 3e5 + 7;
int n, q;
int a[maxn], b[maxn];
int ans, res;
struct query
{
    char o;
    int a, b;
} c[maxn];
int last;
bool cmp(int a, int b)
{
    return a > b;
}
set<int> s1, s2;
void solve()
{
    for (int i = 1; i <= n; ++i)
        b[a[i]] = i;
    for (int i = last + 1, l, r; i <= q; ++i)
    {
        l = b[c[i].a], r = b[c[i].b];
        // printf("%d %d\n", l, r);
        swap(a[l], a[r]);
        b[c[i].a] = r, b[c[i].b] = l;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (i <= n / 2)
            s1.insert(a[i]);
        else
            s2.insert(a[i]);
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> c[i].o;
        if (c[i].o == 'R')
            last = i;
        if (c[i].o == 'E')
            scanf("%d%d", &c[i].a, &c[i].b);
    }
    if (last == 0)
    {
        solve();
        return 0;
    }
    for (int i = 1, l, r; i <= last; ++i)
    {
        if (c[i].o == 'E')
        {
            l = (s1.find(c[i].a) == s1.end()); // 0 - s1, 1 - s2
            r = (s1.find(c[i].b) == s1.end());
            // printf("%d %d\n", l, r);
            if (l == r)
                continue;
            if (l == 1)
                swap(c[i].a, c[i].b);
            s1.erase(c[i].a);
            s2.insert(c[i].a);
            s2.erase(c[i].b);
            s1.insert(c[i].b);
        }
    }
    int l = n / 2, r = n / 2 + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (*s2.lower_bound(i) == i)
            a[r++] = i;
        if (*s1.lower_bound(i) == i)
            a[l--] = i;
    }
    for (int i = 1; i <= n; ++i)
        b[a[i]] = i;
    for (int i = last + 1; i <= q; ++i)
    {
        l = b[c[i].a], r = b[c[i].b];
        // printf("%d %d\n", l, r);
        swap(a[l], a[r]);
        b[c[i].a] = r, b[c[i].b] = l;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
}
/*
 8 4
 7 2 6 1 8 3 5 4
 R
 E 2 3
 R
 E 1 6

  8 4
 7 2 6 1 8 3 5 4
E 2 3
E 1 6
E 3 6
E 5 7
*/