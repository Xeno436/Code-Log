#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;
int const maxn = 607;
int t, n;
char c;
int f[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
bool check(pair<int, int> p)
{
    printf("? %d %d\n", p.first, p.second);
    fflush(stdout);
    cin >> c;
    return c == 'B';
}

set<pair<int, int>> s[2], v, e[2];
set<pair<int, int>>::iterator it;
pair<int, int> p;
bool flag, b, d, tag, cd;
int main()
{
    scanf("%d%d", &t, &n);
    while (t--)
    {
        s[0].clear(), s[1].clear(), v.clear();
        s[b = check({0, 0})].insert({0, 0});
        v.insert({0, 0});
        tag = false;
        while (s[0].size() < n and s[1].size() < n)
        {
            // cout << s[0].size() << ' ' << s[1].size() << endl;
            if (!tag)
            {
                e[b].clear();
                cd = 0;
                for (it = s[b].begin(); it != s[b].end(); ++it)
                {
                    for (int j = 0; j < 8; ++j)
                    {
                        p = {it->first + f[j][0], it->second + f[j][1]};
                        if (v.find(p) == v.end())
                        {
                            s[d = check(p)].insert(p);
                            v.insert(p);
                            if (d != b)
                            {
                                tag = true;
                            }
                            cd = true;
                            break;
                        }
                    }
                    if (cd)
                        break;
                }
                continue;
            }
            e[0].clear(), e[1].clear(), flag = false;
            for (it = s[0].begin(); it != s[0].end(); ++it)
            {
                for (int j = 0; j < 8; ++j)
                {
                    p = {it->first + f[j][0], it->second + f[j][1]};
                    if (v.find(p) == v.end() and e[0].find(p) == e[0].end())
                    {
                        e[0].insert(p);
                    }
                }
            }
            for (it = s[1].begin(); it != s[1].end(); ++it)
            {
                for (int j = 0; j < 8; ++j)
                {
                    p = {it->first + f[j][0], it->second + f[j][1]};
                    if (e[0].find(p) != e[0].end())
                    {
                        s[check(p)].insert(p);
                        v.insert(p);
                        flag = true;
                        break;
                    }
                    if (v.find(p) == v.end() and e[1].find(p) == e[1].end())
                    {
                        e[1].insert(p);
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                continue;
            if (e[0].empty())
            {
                it = e[1].begin();
                s[d = check(*it)].insert(*it);
                v.insert(*it);
                s[0].clear();
                b = 1;
                tag = 0;
                if (d != b)
                    tag = 1;
            }
            else if (e[1].empty())
            {
                it = e[0].begin();
                s[d = check(*it)].insert(*it);
                v.insert(*it);
                s[1].clear();
                b = 0;
                tag = 0;
                if (d != b)
                    tag = 1;
            }
            else
            {
                it = e[0].begin();
                s[d = check(*it)].insert(*it);
                v.insert(*it);
            }
        }
        printf("! ");
        if (s[0].size() == n)
        {
            printf("W ");
            for (it = s[0].begin(); it != s[0].end(); ++it)
            {
                printf("%d %d ", it->first, it->second);
            }
        }
        else if (s[1].size() == n)
        {
            printf("B ");
            for (it = s[1].begin(); it != s[1].end(); ++it)
            {
                printf("%d %d ", it->first, it->second);
            }
        }
        printf("\n");
        fflush(stdout);
    }
} //