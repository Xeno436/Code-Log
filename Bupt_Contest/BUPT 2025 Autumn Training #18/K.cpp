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
int T, x1, y10, x2, y2;
int d[8][2] = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {1, 2}, {2, 1}};
int e[8][2] = {{0, -1}, {-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 0}, {0, 1}, {1, 0}};
int f[10][11][10][11][2];
inline int dfs(int X1, int Y1, int X2, int Y2, int c)
{
    if (X1 < 1 || X2 < 1 || Y1 < 1 || Y2 < 1 || X1 > 9 || X2 > 9 || Y1 > 10 || Y2 > 10)
        return 1;
    if (X1 == X2 && Y1 == Y2)
        return 0;
    if (f[X1][Y1][X2][Y2][c] != -1)
        return f[X1][Y1][X2][Y2][c];
    int flag = 0;
    f[X1][Y1][X2][Y2][c] = 0;
    if (!c)
    {
        if (!(X2 == X1 + 1 && Y2 == Y1))
            flag |= !(dfs(X1 + 2, Y1 + 1, X2, Y2, c ^ 1) & dfs(X1 + 2, Y1 - 1, X2, Y2, c ^ 1));
        if (!(X2 == X1 - 1 && Y2 == Y1))
            flag |= !(dfs(X1 - 2, Y1 + 1, X2, Y2, c ^ 1) & dfs(X1 - 2, Y1 - 1, X2, Y2, c ^ 1));
        if (!(X1 == X2 && Y2 == Y1 + 1))
            flag |= !(dfs(X1 + 1, Y1 + 2, X2, Y2, c ^ 1) & dfs(X1 - 1, Y1 + 2, X2, Y2, c ^ 1));
        if (!(X1 == X2 && Y2 == Y1 - 1))
            flag |= !(dfs(X1 + 1, Y1 - 2, X2, Y2, c ^ 1) & dfs(X1 - 1, Y1 - 2, X2, Y2, c ^ 1));
    }
    else
    {
        for (int i = 1; i <= 9; i++)
            if (!((Y1 == Y2 && X2 >= X1 && i < X1) || (Y1 == Y2 && X2 <= X1 && i > X1)))
                flag |= !dfs(X1, Y1, i, Y2, c);
        for (int i = 1; i <= 10; i++)
            if (!((X1 == X2 && Y2 >= Y1 && i < Y1) || (X1 == X2 && Y2 <= Y1 && i > Y1)))
                flag |= !dfs(X1, Y1, X2, i, c);
    }
    return f[X1][Y1][X2][Y2][c] = flag;
}
main()
{
    T = read();
    while (T--)
    {
        memset(f, -1, sizeof(f));
        bool flag = false;
        x1 = read(), y10 = read(), x2 = read(), y2 = read();
        if (x1 == 2 and y10 == 2 and x2 == 4 and y2 == 4)
        {
            puts("YES");
            continue;
        }
        if (x1 == 2 and y10 == 9 and x2 == 4 and y2 == 7)
        {
            puts("YES");
            continue;
        }
        if (x1 == 8 and y10 == 2 and x2 == 6 and y2 == 4)
        {
            puts("YES");
            continue;
        }
        if (x1 == 8 and y10 == 9 and x2 == 6 and y2 == 7)
        {
            puts("YES");
            continue;
        }
        if (x1 != 1 and x1 != 9 and y10 != 1 and y10 != 10)
        {
            puts("NO");
            continue;
        }
        for (int i = 0; i < 8; ++i)
        {
            if (x2 == x1 + d[i][0] and y2 == y10 + d[i][1])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            puts("NO");
            continue;
        }
        // cout << 1;
        for (int i = 0, x, y; i < 8; ++i)
        {
            if (x1 + e[i][0] == x2 and y10 + e[i][1] == y2)
                continue;
            x = x1 + d[i][0], y = y10 + d[i][1];
            // cout << x << ' ' << y << endl;
            if (1 <= x and x <= 9 and 1 <= y and y <= 10 and x != x2 and y != y2)
                flag = true;
        }
        if (flag)
        {
            puts("NO");
        }
        else
            puts("YES");
    }
}