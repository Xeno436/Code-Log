#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int const maxn = 30, maxm = 607;
int n, m;
vector<int> adj[maxn];
int deg[maxn];
bool vis[maxn];
vector<int> stu, ans;
bool par, und, opt;
void sort()
{
    par = und = false;
    stu.clear();
    ans.clear();
    for (int u = 1; u <= n; ++u)
    {
        vis[u] = false;
        for (int v : adj[u])
        {
            deg[v]++;
        }
    }
    for (int u = 1; u <= n; ++u)
        if (!deg[u])
            stu.push_back(u);
    int u;
    while (!stu.empty())
    {
        if (stu.size() >= 2)
            und = true;
        u = stu.back();
        vis[u] = true;
        ans.push_back(u);
        stu.pop_back();
        for (int v : adj[u])
        {
            deg[v]--;
            if (!deg[v])
                stu.push_back(v);
        }
    }
    for (int u = 1; u <= n; ++u)
        if (!vis[u])
        {
            par = true;
            break;
        }
}
char s[maxm][5];
void add(int m)
{
    for (int i = 1; i < m; ++i)
        if (s[i] == s[m])
            return;
    int u = s[m][0] - 'A' + 1;
    int v = s[m][2] - 'A' + 1;
    if (s[m][1] == '<')
        adj[u].push_back(v);
    else
        adj[v].push_back(u);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", &s[i]);
        add(i);
        sort();
        if (par)
        {
            printf("Inconsistency found after %d relations.", i);
            opt = true;
            break;
        }
        if (!und)
        {
            printf("Sorted sequence determined after %d relations: ", i);
            for (int u : ans)
                printf("%c", u + 'A' - 1);
            printf(".");
            opt = true;
            break;
        }
    }
    if (!opt)
        printf("Sorted sequence cannot be determined.");
}