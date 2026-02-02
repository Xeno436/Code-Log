#include <iostream>
#include <algorithm>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + (r - l >> 1))
using namespace std;
int const maxn = 1e5 + 7, maxm = maxn << 2;
int n, m;
int arr[maxn];
int sum[maxm], tag[maxm], siz[maxm];
int lum[2][maxm], rum[2][maxm], num[2][maxn];
void push_up(int p, int l, int r)
{
    sum[p] = sum[ls] + sum[rs];
    for (int i = 0; i <= 1; ++i)
    {
        lum[i][p] = lum[i][ls];
        if (lum[i][ls] == siz[ls])
            lum[i][p] += lum[i][rs];
        rum[i][p] = rum[i][rs];
        if (rum[i][rs] == siz[rs])
            rum[i][p] += rum[i][ls];
        num[i][p] = max(max(num[i][ls], num[i][rs]), rum[i][ls] + lum[i][rs]);
    }
}
void interval_modify(int p, int l, int r, int O)
{
    tag[p] = O;
    if (O == 0)
    {
        sum[p] = 0;
        lum[0][p] = rum[0][p] = num[0][p] = siz[p];
        lum[1][p] = rum[1][p] = num[1][p] = 0;
    }
    else if (O == 1)
    {
        sum[p] = siz[p];
        lum[0][p] = rum[0][p] = num[0][p] = 0;
        lum[1][p] = rum[1][p] = num[1][p] = siz[p];
    }
    else
    {
        sum[p] = siz[p] - sum[p];
        swap(lum[0][p], lum[1][p]);
        swap(rum[0][p], rum[1][p]);
        swap(num[0][p], num[1][p]);
    }
}
void push_down(int p, int l, int r)
{
    if (tag[p] == -1)
        return;
    interval_modify(ls, l, mid, tag[p]);
    interval_modify(rs, mid + 1, r, tag[p]);
    tag[p] = -1;
}
void build(int p, int l, int r)
{
    tag[p] = -1;
    siz[p] = r - l + 1;
    if (l == r)
    {
        sum[p] = arr[l];
        lum[arr[l]][p]++;
        rum[arr[l]][p]++;
        num[arr[l]][p]++;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p, l, r);
}
void modify(int p, int l, int r, int L, int R, int O)
{
    if (L <= l and r <= R)
    {
        interval_modify(p, l, r, O);
        return;
    }
    push_down(p, l, r);
    if (L <= mid)
        modify(ls, l, mid, L, R, O);
    if (mid + 1 <= R)
        modify(rs, mid + 1, r, L, R, O);
    push_up(p, l, r);
}
int quary_sum(int p, int l, int r, int L, int R)
{
    // printf("%d %d %d\n", p, l, r);
    if (L <= l and r <= R)
    {
        // printf("%d %d %d %d\n", p, l, r, sum[p]);
        return sum[p];
    }
    push_down(p, l, r);
    int tmp = 0;
    if (L <= mid)
        tmp += quary_sum(ls, l, mid, L, R);
    if (mid + 1 <= R)
        tmp += quary_sum(rs, mid + 1, r, L, R);
    // printf("%d %d %d %d\n", p, l, r, tmp);
    return tmp;
}
int lax, ans;
void quary_length(int p, int l, int r, int L, int R)
{
    // printf("%d %d %d\n", p, l, r);
    if (L <= l and r <= R)
    {
        // printf("%d %d %d %d %d %d\n", p, l, r, num[1][p], lax, lum[1][p]);
        ans = max(ans, max(num[1][p], lax + lum[1][p]));
        if (rum[1][p] == siz[p])
            lax += rum[1][p];
        else
            lax = rum[1][p];
        return;
    }
    push_down(p, l, r);
    if (L <= mid)
        quary_length(ls, l, mid, L, R);
    if (mid + 1 <= R)
        quary_length(rs, mid + 1, r, L, R);
}
void init()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    build(1, 1, n);
}
void solve()
{
    for (int i = 1, o, l, r; i <= m; ++i)
    {
        scanf("%d%d%d", &o, &l, &r);
        l++, r++;
        if (o <= 2)
            modify(1, 1, n, l, r, o);
        else if (o == 3)
        {
            printf("%d\n", quary_sum(1, 1, n, l, r));
        }
        else
        {
            lax = ans = 0;
            quary_length(1, 1, n, l, r);
            printf("%d\n", ans);
        }
        // printf("%d %d %d#", sum[5], sum[12], 1);
    }
}
int main()
{
    init();
    // printf("%d %d %d#", lum[1][2], num[0][2], 1);
    solve();
    return 0;
}
/*
10 10
0 0 0 1 1 0 1 0 1 1
4 0 4

4 0 9

1 0 2
3 0 5
2 2 2
4 0 4
0 3 6
2 3 7
4 2 8
1 0 5
0 5 6
3 3 9

1 1 1 1 1 0
1 1 0 1 1 0
1-10
1-5 6-10
1-3 4-5 6-8 9-10
        6-7
*/