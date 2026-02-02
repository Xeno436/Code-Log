#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
int const maxn = 1e6 + 17;
char c[17], s[maxn];
int lc, ls;
int main()
{
    scanf("%s", c);
    char a = getchar();
    // char b = getchar();
    assert(a == '\n');
    // assert(b == '\r');
    // printf("1");
    cin.getline(s, maxn - 2);
    scanf("%s", c);
    printf("%s", c);
    for (int i = 0; i < 17; ++i)
    {
        if ('A' <= c[i] and c[i] <= 'Z')
            c[i] += 32;
        if (c[i] < 'a' or 'z' < c[i])
        {
            lc = i;
            break;
        }
    }
    for (int i = 0; i < maxn; ++i)
    {
        if ('A' <= s[i] and s[i] <= 'Z')
            s[i] += 32;
        if ((s[i] < 'a' or 'z' < s[i]) and s[i] != ' ')
        {
            ls = i;
            break;
        }
    }
    // printf("%d %d\n", lc, ls);
    // printf("%s %s", c, s);
    int cnt = 0, ans;
    bool vis = false;
    for (int i = 0; i < lc; ++i)
    {
        if (c[i] != s[i])
            break;
        if (i == lc - 1)
        {
            ans = 0;
            cnt++;
            vis = true;
        }
    }
    for (int j = 0; j < ls; ++j)
    {
        if (s[j] == ' ')
        {
            for (int i = 0; i < lc; ++i)
            {
                // printf("%c %c\n", c[i], s[j + i + 1]);
                if (c[i] != s[j + i + 1])
                    break;
                if (i == lc - 1 and (s[j + i + 1 + 1] == ' ' or j + i + 2 == ls))
                {
                    cnt++;
                    if (vis == false)
                    {
                        ans = j + 1;
                        vis = true;
                    }
                }
            }
        }
    }
    if (cnt == 0)
        printf("-1");
    else
        printf("%d %d", cnt, ans);
}