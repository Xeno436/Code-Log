#include <iostream>
#include <algorithm>
#include <ctime>
#include <tuple>
#define mp make_pair
using namespace std;
int const maxn = 1e5 + 7;
int ls[maxn], rs[maxn], siz[maxn], pri[maxn], val[maxn], cnt[maxn];
int rt, tot, n;
void push_up(int p)
{
    siz[p] = siz[ls[p]] + siz[rs[p]] + cnt[p];
}
pair<int, int> split_val(int p, int v)
{
    if (p == 0)
        return {0, 0};
    // 把比较修正为：当节点值 <= v 时，当前节点属于左子树（<= v）
    if (val[p] <= v)
    {
        auto tmp = split_val(rs[p], v);
        rs[p] = tmp.first;
        push_up(p);
        return {p, tmp.second};
    }
    else
    {
        auto tmp = split_val(ls[p], v);
        ls[p] = tmp.second;
        push_up(p);
        return {tmp.first, p};
    }
}
tuple<int, int, int> split_rk(int p, int r)
{
    if (p == 0)
        return {0, 0, 0};
    int lr, mr, rr;
    if (r <= siz[ls[p]])
    {
        tie(lr, mr, rr) = split_rk(ls[p], r);
        ls[p] = rr;
        push_up(p);
        return {lr, mr, p};
    }
    else if (r <= siz[ls[p]] + cnt[p])
    {
        lr = ls[p], rr = rs[p];
        ls[p] = rs[p] = 0;
        push_up(p);
        return {lr, p, rr};
    }
    else
    {
        tie(lr, mr, rr) = split_rk(rs[p], r - siz[ls[p]] - cnt[p]);
        rs[p] = lr;
        push_up(p);
        return {p, mr, rr};
    }
}
int merge(int p, int q)
{
    if (p == 0 or q == 0)
        return p ^ q;
    if (pri[p] < pri[q])
    {
        int tmp = merge(rs[p], q);
        rs[p] = tmp;
        push_up(p);
        return p;
    }
    else
    {
        int tmp = merge(p, ls[q]);
        ls[q] = tmp;
        push_up(q);
        return q;
    }
}
void insert(int v)
{
    auto t2 = split_val(rt, v);
    auto t1 = split_val(t2.first, v - 1);
    if (t1.second == 0)
    {
        t1.second = ++tot;
        ls[tot] = rs[tot] = 0;
        pri[tot] = rand();
        cnt[tot] = siz[tot] = 1;
        val[tot] = v;
    }
    else
    {
        ++cnt[t1.second];
        push_up(t1.second);
    }
    rt = merge(merge(t1.first, t1.second), t2.second);
}
void erase(int v)
{
    auto t2 = split_val(rt, v);
    auto t1 = split_val(t2.first, v - 1);
    if (siz[t1.second] == 1)
    {
        if (t2.first == t1.second)
            t2.first = 0;
        t1.second = 0;
    }
    else
    {
        --cnt[t1.second];
        push_up(t1.second);
    }
    rt = merge(merge(t1.first, t1.second), t2.second);
}
int qrank(int &p, int v)
{
    auto tmp = split_val(p, v - 1);
    int ans = siz[tmp.first] + 1;
    p = merge(tmp.first, tmp.second);
    return ans;
}
int qval(int &p, int r)
{
    int rl, rm, rr;
    tie(rl, rm, rr) = split_rk(p, r);
    int ans = val[rm];
    merge(merge(rl, rm), rr);
    return ans;
}
int pre(int v)
{
    auto tmp = split_val(rt, v - 1);
    int ans = qval(tmp.first, siz[tmp.first]);
    merge(tmp.first, tmp.second);
    return ans;
}
int nxt(int v)
{
    auto tmp = split_val(rt, v);
    int ans = qval(tmp.second, 1);
    merge(tmp.first, tmp.second);
    return ans;
}
int main()
{
    srand(121383);
    scanf("%d", &n);
    int o, x;
    while (n--)
    {
        scanf("%d", &o);
        if (o == 1)
        {
            scanf("%d", &x);
            insert(x);
        }
        if (o == 2)
        {
            scanf("%d", &x);
            erase(x);
        }
        if (o == 3)
        {
            scanf("%d", &x);
            printf("%d\n", qrank(rt, x));
        }
        if (o == 4)
        {
            scanf("%d", &x);
            printf("%d\n", qval(rt, x));
        }
        if (o == 5)
        {
            scanf("%d", &x);
            printf("%d\n", pre(x));
        }
        if (o == 6)
        {
            scanf("%d", &x);
            printf("%d\n", nxt(x));
        }
    }
}