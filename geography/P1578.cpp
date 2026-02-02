#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 5e3 + 7;
int L, W, n;
int ans = 0;
struct node
{
    int x, y;
} cow[maxn];
bool cmpx(node a, node b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
bool cmpy(node a, node b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}
void init()
{
    scanf("%d%d%d", &L, &W, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &cow[i].x, &cow[i].y);
}
void solve()
{
    sort(cow + 1, cow + n + 1, cmpx);
    for (int i = 1; i <= n; ++i)
    {
        int up_bound = W, down_bound = 0;
        for (int j = i + 1; j <= n; ++j)
        {
            ans = max(ans, (cow[j].x - cow[i].x) * (up_bound - down_bound));
            if (cow[j].y <= down_bound or up_bound <= cow[j].y)
                continue;
            if (cow[i].y <= cow[j].y)
                up_bound = cow[j].y;
            else
                down_bound = cow[j].y;
        }
        ans = max(ans, (L - cow[i].x) * (up_bound - down_bound));
    }
    for (int i = n; i >= 1; --i)
    {
        int up_bound = W, down_bound = 0;
        for (int j = i - 1; j >= 1; --j)
        {
            ans = max(ans, (cow[i].x - cow[j].x) * (up_bound - down_bound));
            if (cow[j].y <= down_bound or up_bound <= cow[j].y)
                continue;
            if (cow[i].y <= cow[j].y)
                up_bound = cow[j].y;
            else
                down_bound = cow[j].y;
        }
        ans = max(ans, (cow[i].x) * (up_bound - down_bound));
    }
    sort(cow + 1, cow + n + 1, cmpy);
    ans = max(ans, L * cow[1].y);
    for (int i = 2; i <= n; ++i)
    {
        ans = max(ans, L * (cow[i].y - cow[i - 1].y));
    }
    ans = max(ans, L * (W - cow[n].y));
    printf("%d", ans);
}
int main()
{
    init();
    solve();
    return 0;
}