// 尝试用线段树实现平衡树
#include <iostream>
#include <algorithm>
#define mid (l + (r - l >> 1))
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
int const maxn = 1e5 + 7;
int n;
int arr[maxn], tmp[maxn];
int opt[maxn], opr[maxn], cnt;
int siz[maxn << 2], fst[maxn << 2], lst[maxn << 2];
void push_up(int p, int l, int r)
{
    fst[p] = fst[ls];
    if (fst[ls] == 0)
        fst[p] = fst[rs];
    lst[p] = lst[rs];
    if (lst[rs] == 0)
        lst[p] = lst[ls];
    siz[p] = siz[ls] + siz[rs];
}
void insert_num(int p, int l, int r, int K)
{

    if (l == r)
    {
        siz[p]++;
        fst[p] = lst[p] = l;
        return;
    }
    if (K <= mid)
        insert_num(ls, l, mid, K);
    else
        insert_num(rs, mid + 1, r, K);
    push_up(p, l, r);
}
void delete_num(int p, int l, int r, int K)
{
    if (l == r)
    {
        siz[p]--;
        if (siz[p] == 0)
        {
            fst[p] = lst[p] = 0;
        }
        return;
    }
    if (K <= mid)
        delete_num(ls, l, mid, K);
    else
        delete_num(rs, mid + 1, r, K);
    push_up(p, l, r);
}
int search_rank(int p, int l, int r, int K)
{
    if (l == r)
        return 1;
    if (K <= mid)
        return search_rank(ls, l, mid, K);
    else
        return siz[ls] + search_rank(rs, mid + 1, r, K);
}
int rank_ans; // init per quest
int search_num(int p, int l, int r, int R)
{
    if (l == r)
        return l;
    if (rank_ans + siz[ls] >= R)
    {
        return search_num(ls, l, mid, R);
    }
    else
    {
        rank_ans += siz[ls];
        return search_num(rs, mid + 1, r, R);
    }
}
int search_pre(int p, int l, int r, int K)
{
    if (fst[rs] == K)
    {
        return lst[ls];
    }
    if (l == r)
        return l;
    if (K <= mid)
    {
        return search_pre(ls, l, mid, K);
    }
    else
        return search_pre(rs, mid + 1, r, K);
}
int search_nxt(int p, int l, int r, int K)
{
    if (lst[ls] == K)
    {
        return fst[rs];
    }
    if (l == r)
        return l;
    if (K <= mid)
        return search_nxt(ls, l, mid, K);
    else
        return search_nxt(rs, mid + 1, r, K);
}
void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &opt[i], &opr[i]);
        if (opt[i] != 4)
        {
            tmp[++cnt] = opr[i];
        }
    }
    sort(tmp + 1, tmp + cnt + 1);
    cnt = unique(tmp + 1, tmp + cnt + 1) - tmp - 1;
    for (int i = 1; i <= n; ++i)
        if (opt[i] != 4)
            opr[i] = lower_bound(tmp + 1, tmp + cnt + 1, opr[i]) - tmp;
    printf("%d\n", cnt);
}
void solve()
{

    for (int i = 1; i <= n; ++i)
    {
        printf("%d\n", i);
        if (opt[i] == 1)
        {
            insert_num(1, 1, cnt, opr[i]);
        }
        else if (opt[i] == 2)
        {
            delete_num(1, 1, cnt, opr[i]);
        }
        else if (opt[i] == 3)
        {
            printf("%d\n", search_rank(1, 1, cnt, opr[i]));
        }
        else if (opt[i] == 4)
        {
            rank_ans = 0;
            printf("%d\n", tmp[search_num(1, 1, cnt, opr[i])]);
        }
        else if (opt[i] == 5)
        {
            printf("%d\n", tmp[search_pre(1, 1, cnt, opr[i])]);
        }
        else
        {
            printf("$");
            printf("%d\n", tmp[search_nxt(1, 1, cnt, opr[i])]);
        }
    }
}
int main()
{
    init();
    solve();
}