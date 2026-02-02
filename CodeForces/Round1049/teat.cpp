#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int aa = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        aa = aa * 10 + ch - '0', ch = getchar();
    return aa * f;
}
const int M = 1e5 + 10;
mt19937 rnd(time(0));
int n, m, ro;
int ch[M][2], sz[M], t1[M], t2[M];
inline void pushup(int rt) { sz[rt] = sz[ch[rt][0]] + sz[ch[rt][1]] + 1; }
inline int cre(int x)
{
    ++m;
    sz[m] = 1;
    t1[m] = x;
    t2[m] = rnd();
    return m;
}
inline void split(int rt, int k, int &x, int &y)
{
    if (!rt)
    {
        x = y = 0;
        return;
    }
    if (t1[rt] <= k)
        x = rt, split(ch[rt][1], k, ch[x][1], y);
    else
        y = rt, split(ch[rt][0], k, x, ch[y][0]);
    pushup(rt);
}
inline void Split(int rt, int k, int &x, int &y)
{
    if (!rt)
    {
        x = y = 0;
        return;
    }
    if (sz[ch[rt][0]] + 1 <= k)
        x = rt, Split(ch[rt][1], k - sz[ch[rt][0]] - 1, ch[x][1], y);
    else
        y = rt, Split(ch[rt][0], k, x, ch[y][0]);
    pushup(rt);
}
inline int merge(int x, int y)
{
    if (!x || !y)
        return x | y;
    if (t2[x] <= t2[y])
    {
        ch[y][0] = merge(x, ch[y][0]), pushup(y);
        return y;
    }
    else
    {
        ch[x][1] = merge(ch[x][1], y), pushup(x);
        return x;
    }
}
inline int find_max(int rt)
{
    if (!ch[rt][1])
        return t1[rt];
    return find_max(ch[rt][1]);
}
inline int find_min(int rt)
{
    if (!ch[rt][0])
        return t1[rt];
    return find_min(ch[rt][0]);
}
main()
{
    n = read();
    while (n--)
    {
        int op = read(), x = read(), r1, r2, r3;
        if (op == 1)
        {
            split(ro, x, r1, r2);
            ro = merge(merge(r1, cre(x)), r2);
        }
        else if (op == 2)
        {
            split(ro, x, r1, r2), split(r1, x - 1, r1, r3);
            r3 = merge(ch[r3][0], ch[r3][1]);
            r1 = merge(r1, r3);
            ro = merge(r1, r2);
        }
        else if (op == 3)
        {
            split(ro, x - 1, r1, r2);
            cout << sz[r1] + 1 << '\n';
            ro = merge(r1, r2);
        }
        else if (op == 4)
        {
            Split(ro, x, r1, r2);
            cout << find_max(r1) << '\n';
            ro = merge(r1, r2);
        }
        else if (op == 5)
        {
            split(ro, x - 1, r1, r2);
            cout << find_max(r1) << '\n';
            ro = merge(r1, r2);
        }
        else
        {
            split(ro, x, r1, r2);
            cout << find_min(r2) << '\n';
            ro = merge(r1, r2);
        }
    }
}