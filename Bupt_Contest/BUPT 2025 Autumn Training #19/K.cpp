#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 5e5 + 7;
int T, n;
string s, t;
int sl, tl;
int nxt[maxn][3];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        cin >> s;
        sl = s.length();
        int a[3] = {sl, sl, sl};
        for (int i = sl - 1; i >= 0; --i)
        {
            if (s[i] == 'R')
                a[0] = i;
            else
                a[1] = i;
            if (i != sl - 1 and s[i] == 'L' and s[i + 1] == 'R')
                a[2] = i;
            nxt[i][0] = a[0], nxt[i][1] = a[1], nxt[i][2] = a[2];
        }
        // for (int i = 0; i < sl; ++i)
        //     printf("%d %d %d\n", nxt[i][0], nxt[i][1], nxt[i][2]);
        scanf("%d", &n);
        while (n--)
        {
            cin >> t;
            tl = t.length();
            if (t[0] == 'R' and s[0] != 'R')
            {
                puts("NO");
                continue;
            }
            if (t[tl - 1] == 'L' and s[sl - 1] != 'L')
            {
                puts("NO");
                continue;
            }
            int i = 0, j = 0;
            bool flag = false;
            while (i < tl and j < sl)
            {
                // cout << i << ' ' << j << endl;
                if (t[i] == 'R')
                {
                    if (nxt[j][0] >= sl)
                    {
                        flag = true;
                        break;
                    }
                    i++, j = nxt[j][0] + 1;
                }
                else if (t[i] == 'L' and (i == tl - 1 or t[i + 1] != 'R'))
                {
                    if (nxt[j][1] >= sl)
                    {
                        flag = true;
                        break;
                    }
                    i++, j = nxt[j][1] + 1;
                }
                else
                {
                    if (nxt[j][2] >= sl - 1)
                    {
                        flag = true;
                        break;
                    }
                    // cout << '*';
                    i += 2, j = nxt[j][2] + 2;
                }
                // cout << '*';
            }
            if (flag or i < tl)
                puts("NO");
            else
                puts("YES");
        }
    }
    return 0;
}