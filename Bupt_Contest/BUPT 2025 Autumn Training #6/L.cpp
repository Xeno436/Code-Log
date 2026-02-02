// ac
#include <bits/stdc++.h>
using namespace std;
int n[2];
int a[10][2]; // heart
int f[10][2]; // attack
int s[2];     // alive
int b[10][2];
int score[3];
bool c, d;
double ans[3];
mt19937 rnd(time(0));
void dfs(bool o, double p)
{
    c = s[0], d = s[1];
    if ((c and d) == 0)
    {
        // cout << p << ' ';
        if (c == 0 and d == 0)
            ans[2] += p;
        if (c != 0 and d == 0)
            ans[0] += p;
        if (c == 0 and d != 0)
            ans[1] += p;
        return;
    }
    int mx = 1e9 + 7, u, v;
    for (int i = 1; i <= n[o]; ++i)
        if (a[i][o] > 0 and b[i][o] < mx)
        {
            mx = b[i][o];
            u = i;
        }
    double tmp = s[o ^ 1];
    for (v = 1; v <= n[o ^ 1]; ++v)
        if (a[v][o ^ 1] > 0)
        {
            a[u][o] -= f[v][o ^ 1], a[v][o ^ 1] -= f[u][o];
            if (a[u][o] <= 0)
                s[o]--;
            if (a[v][o ^ 1] <= 0)
                s[o ^ 1]--;
            b[u][o]++;
            dfs(o ^ 1, p / tmp);
            b[u][o]--;
            if (a[u][o] <= 0)
                s[o]++;
            if (a[v][o ^ 1] <= 0)
                s[o ^ 1]++;
            a[u][o] += f[v][o ^ 1], a[v][o ^ 1] += f[u][o];
        }
}
int main()
{
    // printf("%d %d\n", rnd(), rnd());
    scanf("%d%d", &n[0], &n[1]);
    s[0] = n[0], s[1] = n[1];
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= n[i]; ++j)
        {
            scanf("%d", &a[j][i]);
            f[j][i] = a[j][i];
        }
    if (n[0] == n[1])
        dfs(0, 0.5), dfs(1, 0.5);
    else if (n[0] < n[1])
        dfs(1, 1);
    else
        dfs(0, 1);
    for (int i = 0; i < 3; ++i)
        // cout << ans[i] << endl;
        printf("%0.10lf\n", ans[i]);
}