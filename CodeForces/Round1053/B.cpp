#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 2e5 + 7;
int t, n, m, k;
struct person
{
    int idx, upp;
} per[maxn], tmp;
string s;
int pre[maxn], nxt[maxn], idx[maxn], cnt;
person jump(person x, bool o)
{
    // printf("*%d %d ", x.idx, x.upp);
    if (o and x.idx + 1 == idx[x.upp])
    {
        while (idx[x.upp] + 1 == idx[nxt[x.upp]])
            x.upp = nxt[x.upp];
        x.idx = idx[x.upp];
        x.upp = nxt[x.upp];
    }
    if (idx[x.upp] == x.idx + 1)
        x.upp = nxt[x.upp];
    // printf("%d %d*\n", x.idx + 1, x.upp);
    return {x.idx + 1, x.upp};
}
void solve(int t)
{
    cnt = 0;
    scanf("%d%d", &n, &m);
    cin >> s;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &idx[++cnt]);
        nxt[cnt - 1] = cnt;
        pre[cnt] = cnt - 1;
    }
    nxt[0] = 1;
    pre[1] = 0;
    nxt[m] = m + 1;
    pre[m + 1] = m;
    idx[m + 1] = 1e9 + 7;
    cnt = m + 1;
    per[0] = {1, 1};
    if (idx[1] == 1)
        per[0].upp = nxt[per[0].upp];
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            per[1] = jump(per[0], bool(s[i - 1] - 'A'));
        }
        else
        {
            per[i - 1] = jump(per[i - 2], bool(s[i - 2] - 'A'));
            per[i] = jump(per[i - 1], bool(s[i - 1] - 'A'));
        }
        if (per[i].idx == idx[pre[per[i].upp]])
            continue;
        idx[++cnt] = per[i].idx;
        // printf("%d ", per[i].idx);
        pre[cnt] = pre[per[i].upp];
        nxt[pre[per[i].upp]] = cnt;
        nxt[cnt] = per[i].upp;
        pre[per[i].upp] = cnt;
        per[i - 1].upp = pre[per[i - 1].upp];
        while (per[i - 1].idx >= idx[per[i - 1].upp])
            per[i - 1].upp = nxt[per[i - 1].upp];
        // 更新链表
    }
    printf("%d\n", cnt - 1);
    int k = nxt[0];
    while (idx[k] != 1e9 + 7)
    {
        // printf("%d ", k);
        printf("%d", idx[k]);
        if (idx[nxt[k]] != 1e9 + 7)
            printf(" ");
        k = nxt[k];
    }
    for (int i = 0; i <= cnt; ++i)
        pre[i] = nxt[i] = idx[i] = 0;
    for (int i = 0; i <= n; ++i)
        per[i] = {0, 0};
    cnt = 0;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        solve(t);
        if (t)
            printf("\n");
    }
    return 0;
}