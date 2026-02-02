#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 8e3 + 7;
int n, q;
int arr[maxn];
struct num
{
    int idx, val;
} tab[maxn];
bool cmp(num a, num b)
{
    if (a.val == b.val)
        return a.idx < b.idx;
    return a.val < b.val;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
        tab[i] = {i, arr[i]};
    }
    sort(tab + 1, tab + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        arr[tab[i].idx] = i;
    for (int i = 1, o, x, y, j; i <= q; ++i)
    {
        scanf("%d%d", &o, &x);
        if (o == 1)
        {
            scanf("%d", &y);
            j = arr[x];
            tab[j].val = y;
            while (j < n and (tab[j].val > tab[j + 1].val or (tab[j].val == tab[j + 1].val and tab[j].idx > tab[j + 1].idx)))
            {
                arr[tab[j].idx] = j + 1, arr[tab[j + 1].idx] = j;
                swap(tab[j].val, tab[j + 1].val);
                swap(tab[j].idx, tab[j + 1].idx);
                j++;
            }
            while (j > 1 and (tab[j].val < tab[j - 1].val or (tab[j].val == tab[j - 1].val and tab[j].idx < tab[j - 1].idx)))
            {
                arr[tab[j].idx] = j - 1, arr[tab[j - 1].idx] = j;
                swap(tab[j].val, tab[j - 1].val);
                swap(tab[j].idx, tab[j - 1].idx);
                j--;
            }
        }
        else
        {
            printf("%d\n", arr[x]);
        }
    }
}
/*
3 9 5 8 0 7 2 5 3 4

10 7
3 3 5 2 0 7 2 5 6 4

1 2 9
1 4 8
1 9 3
2 2
1 2 5
1 2 0
2 4
2  6
3         3         5         2         0         7         2         5         6         4
584395437 584395437 797929861 522203818 381935688 862314366 522203818 797929861 835048540 589968305
1 2 9
1 2 991541492
1 4 8
1 4 883341961
1 9 3
1 9 584395437
2 2
1 2 5
1 2 797929861
1 2 0
1 2 280980536
2 4
1 9 1
1 9 471602987
1 4 3
1 4 584395437
1 8 -1
1 8 379023047


*/