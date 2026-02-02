#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int const maxn = 1e5 + 7;
string a[maxn][2];
int n;
int e[maxn << 2][52], tot = 1;
vector<int> v[maxn << 2];
inline int form(char c)
{
    if ('a' <= c and c <= 'z')
        return c - 'a';
    return c - 'A' + 26;
}
bool flag = true;
int ans[maxn][2], res;
void insert(string s, int x)
{
    int u = 1;
    for (int i = 0, j; i < 4; ++i)
    {
        j = form(s[i]);
        if (!e[u][j])
            e[u][j] = ++tot;
        u = e[u][j];
    }
    if (x <= n)
        v[u].push_back(x);
    else
    {
        if (v[u].empty())
            flag = false;
        else
        {
            res++;
            ans[res][0] = v[u].back();
            ans[res][1] = x;
            v[u].pop_back();
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i][0];
        insert(a[i][0], i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i][1];
        insert(a[i][1], i + n);
    }
    if (flag)
    {
        puts("YES");
        for (int i = 1; i <= n; ++i)
            cout << a[ans[i][0]][0] << ' ' << a[ans[i][1] - n][1] << endl;
    }
    else
        puts("NO");
    for (int i = 1; i <= n; ++i)
    {
        ;
    }
    return 0;
}