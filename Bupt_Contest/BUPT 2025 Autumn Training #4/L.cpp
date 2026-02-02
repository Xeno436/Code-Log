// AC
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define mp make_pair
int const maxn = 107;
using namespace std;
int n = 98;
int draw[maxn];
struct node
{
    int a, b;
} tmp[17];
int ts;
bool cmp(node a, node b)
{
    return a.a < b.a;
}
vector<int> drop[4];
set<int> hand;
set<int>::iterator it;
int ab(int x)
{
    if (x < 0)
        x = -x;
    return x;
}
int main()
{
    for (int i = 1; i <= n; ++i)
        scanf("%d", &draw[i]);
    for (int i = 1; i <= 8; ++i)
        hand.insert(i);
    drop[0].push_back(1);
    drop[1].push_back(1);
    drop[2].push_back(100);
    drop[3].push_back(100);
    int t = 9;
    while (true)
    {
        int f = -1, p, tot = 0;
        ts = 0;
        for (it = hand.begin(); it != hand.end(); ++it)
        {
            int j = *it;
            tmp[++ts] = {j, draw[j]};
        }
        sort(tmp + 1, tmp + ts + 1, cmp);
        for (int i = 1; i <= ts; ++i)
        {
            for (int k = 0; k < 4; ++k)
                if ((k <= 1 and drop[k].back() - 10 == tmp[i].b) or (k >= 2 and drop[k].back() + 10 == tmp[i].b))
                {
                    f = tmp[i].a, p = k;
                    break;
                }
        }
        if (f != -1)
        {
            ++tot;
            drop[p].push_back(draw[f]);
            hand.erase(f);
        }
        //
        f = -1;
        ts = 0;
        for (it = hand.begin(); it != hand.end(); ++it)
        {
            int j = *it;
            tmp[++ts] = {j, draw[j]};
        }
        sort(tmp + 1, tmp + ts + 1, cmp);
        for (int i = 1; i <= ts; ++i)
        {
            for (int k = 0; k < 4; ++k)
                if ((k <= 1 and drop[k].back() - 10 == tmp[i].b) or (k >= 2 and drop[k].back() + 10 == tmp[i].b))
                {
                    f = tmp[i].a, p = k;
                    break;
                }
        }
        if (f != -1)
        {
            ++tot;
            drop[p].push_back(draw[f]);
            hand.erase(f);
        }
        if (tot == 2)
        {
            if (t <= 98)
                hand.insert(t++);
            if (t <= 98)
                hand.insert(t++);
            continue;
        }
        int mx = maxn;
        ts = 0;
        for (it = hand.begin(); it != hand.end(); ++it)
        {
            int j = *it;
            tmp[++ts] = {j, draw[j]};
        }
        sort(tmp + 1, tmp + ts + 1, cmp);
        for (int i = 1; i <= ts; ++i)
        {
            for (int k = 0; k < 4; ++k)
                if ((ab(tmp[i].b - drop[k].back()) < mx) and
                    ((k <= 1 and drop[k].back() < tmp[i].b) or
                     (k >= 2 and drop[k].back() > tmp[i].b)))
                {
                    mx = ab(tmp[i].b - drop[k].back());
                    f = tmp[i].a, p = k;
                }
        }
        if (mx != maxn)
        {
            ++tot;
            drop[p].push_back(draw[f]);
            hand.erase(f);
        }
        if (tot == 2)
        {
            if (t <= 98)
                hand.insert(t++);
            if (t <= 98)
                hand.insert(t++);
            continue;
        }
        f = -1;
        ts = 0;
        for (it = hand.begin(); it != hand.end(); ++it)
        {
            int j = *it;
            tmp[++ts] = {j, draw[j]};
        }
        sort(tmp + 1, tmp + ts + 1, cmp);
        for (int i = 1; i <= ts; ++i)
        {
            for (int k = 0; k < 4; ++k)
                if ((k <= 1 and drop[k].back() - 10 == tmp[i].b) or (k >= 2 and drop[k].back() + 10 == tmp[i].b))
                {
                    f = tmp[i].a, p = k;
                    break;
                }
        }
        if (f != -1)
        {
            ++tot;
            drop[p].push_back(draw[f]);
            hand.erase(f);
        }
        if (tot == 2)
        {
            if (t <= 98)
                hand.insert(t++);
            if (t <= 98)
                hand.insert(t++);
            continue;
        }
        // 4
        mx = maxn;
        ts = 0;
        for (it = hand.begin(); it != hand.end(); ++it)
        {
            int j = *it;
            tmp[++ts] = {j, draw[j]};
        }
        sort(tmp + 1, tmp + ts + 1, cmp);
        for (int i = 1; i <= ts; ++i)
        {
            for (int k = 0; k < 4; ++k)
                if ((ab(tmp[i].b - drop[k].back()) < mx) and
                    ((k <= 1 and drop[k].back() < tmp[i].b) or
                     (k >= 2 and drop[k].back() > tmp[i].b)))
                {
                    mx = ab(tmp[i].b - drop[k].back());
                    f = tmp[i].a, p = k;
                }
        }
        if (mx != maxn)
        {
            ++tot;
            drop[p].push_back(draw[f]);
            hand.erase(f);
        }
        if (tot == 2)
        {
            if (t <= 98)
                hand.insert(t++);
            if (t <= 98)
                hand.insert(t++);
            continue;
        }
        // printf("!");
        for (int k = 0; k < 4; ++k)
        {
            for (int i : drop[k])
            {
                printf("%d ", i);
            }
            printf("\n");
        }
        ts = 0;
        for (it = hand.begin(); it != hand.end(); ++it)
        {
            int j = *it;
            tmp[++ts] = {j, draw[j]};
        }
        sort(tmp + 1, tmp + ts + 1, cmp);
        for (int i = 1; i <= ts; ++i)
            printf("%d ", tmp[i].b);
        printf("\n");
        for (int i = t; i <= 98; ++i)
            printf("%d ", draw[i]);
        return 0;
    }
    return 0;
}
/*
 96 69 40 94 35 7 53 88 10 89 47 37 16 61 24 46 90 6 33 25 63 73 26 81 2 45
 77 75 48 57 66 34 59 92 44 11 31 18 9 52 91 50 8 98 5 64 86 62 83 4 19
 3 27 97 28 36 23 76 58 30 38 12 39 78 41 56 80 67 70 99 13 42 17 49 84
 22 32 29 54 71 51 74 79 95 72 15 87 21 65 68 60 85 55 43 93 20 82 14

 87 31 58 56 82 93 9 68 65 41 26 64 3 11 5 84 24 46 16 30 14 85 52 12 91 75
 96 17 47 37 76 69 78 49 25 28 48 81 95 63 34 43 27 74 80 62 53 83 40 71
 72 35 23 21 51 66 55 61 67 32 38 29 60 39 4 18 20 77 7 94 59 42 79 10
 92 97 57 2 86 33 89 90 88 19 22 99 45 44 73 70 50 6 15 98 54 13 36 8
*/