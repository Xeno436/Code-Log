#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int po[8];
string s;
bool dfs(int x, int sum, int tim)
{
    // cout << x << ' ' << s[x] << endl;
    if (s[x] == 'y')
    {
        int t = 0, i;
        for (i = x - 4; i >= 0 and '0' <= s[i] and s[i] <= '9'; i--)
        {
            t += (s[i] - '0') * po[x - 4 - i];
        }
        if (i == -1)
        {
            t = 0;
            for (i = x - 4; i >= 0 and '0' <= s[i] and s[i] <= '9' and t < 300; i--)
            {
                t += (s[i] - '0') * po[x - 4 - i];
                if (i == x - 5 and t == 0)
                    continue;
                if (t < 300 and i - 1 >= 1)
                {
                    if (dfs(i - 1, sum + 1, tim + t))
                    {
                        printf(" %d 1 try", t);
                        return true;
                    }
                }
            }
            if (dfs(x - 4, sum, tim))
            {
                printf(" 1 try");
                return true;
            }
        }
        else if (s[x - 4] < '0' or s[x - 4] > '9')
        {
            if (dfs(x - 4, sum, tim))
            {
                printf(" 1 try");
                return true;
            }
        }
        else if (t < 300)
        {
            if (dfs(i, sum + 1, tim + t))
            {
                printf(" %d 1 try", t);
                return true;
            }
        }
    }
    else if (s[x] == 's')
    {
        int u = 0;
        for (int j = x - 5; j >= x - 6; --j)
        {
            // cout << j << '*';
            u += (s[j] - '0') * po[x - 5 - j];
            // cout << s[0];
            if (j == x - 5 and (s[j] == '0' or s[j] == '1'))
                continue;
            int t = 0, i;
            for (i = j - 1; i >= 0 and '0' <= s[i] and s[i] <= '9'; i--)
            {
                // cout << i << ' ' << s[i] << endl;
                t += (s[i] - '0') * po[j - 1 - i];
            }
            // cout << x << ' ' << j << ' ' << i << ' ' << endl;
            if (i == -1)
            {
                t = 0;
                for (i = j - 1; i >= 0 and '0' <= s[i] and s[i] <= '9' and t < 300; i--)
                {
                    t += (s[i] - '0') * po[j - 1 - i];
                    if (i == j - 2 and t == 0)
                        continue;
                    if (t < 300 and i - 1 >= 1)
                    {
                        if (dfs(i - 1, sum + 1, tim + t + 20 * (u - 1)))
                        {
                            printf(" %d %d tries", t, u);
                            return true;
                        }
                    }
                }
                if (dfs(j - 1, sum, tim))
                {
                    printf(" %d tries", u);
                    return true;
                }
            }
            else if (s[j - 1] < '0' or s[j - 1] > '9')
            {
                if (dfs(j - 1, sum, tim))
                {
                    printf(" %d tries", u);
                    return true;
                }
            }
            else if (t < 300)
            {
                if (dfs(i, sum + 1, tim + t + 20 * (u - 1)))
                {
                    printf(" %d %d tries", t, u);
                    return true;
                }
            }
        }
    }
    else
    {
        int a = sum, b = tim;
        // cout << x << ' ' << a << ' ' << b << endl;
        if (!tim)
            if (x <= -1 or s[x] != '0')
                return false;
            else
                x--;
        else
            while (tim)
            {
                // cout << x << endl;
                if (x <= -1 or (s[x] - '0') != tim % 10)
                    return false;
                x--, tim /= 10;
            }
        if (!sum)
            if (x <= -1 or s[x] != '0')
                return false;
            else
                x--;
        else
            while (sum)
            {
                if (x <= -1 or (s[x] - '0') != sum % 10)
                    return false;
                x--, sum /= 10;
            }
        if (x == -1)
        {
            printf("%d %d", a, b);
        }
        return x == -1;
    }
    return false;
}
int main()
{
    po[0] = 1;
    for (int i = 1; i < 8; ++i)
        po[i] = po[i - 1] * 10;
    scanf("%d%d", &n, &m);
    while (n--)
    {
        cin >> s;
        dfs(s.length() - 1, 0, 0);
        printf("\n");
    }
}