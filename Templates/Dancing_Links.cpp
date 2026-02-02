#include <iostream>
#include <cstring>
using namespace std;
int const maxn = 1e5 + 7, maxm = 5e2 + 7;
int n, m, ans;
int cnt;
int col[maxn], row[maxn], siz[maxn], first[maxn];
int U[maxn], D[maxn], L[maxn], R[maxn];
int stk[maxm];
void build(int r, int c)
{
    ans = 0;
    n = r, m = c;
    cnt = c;
    for (int i = 0; i <= c; ++i)
    {
        L[i] = i - 1, R[i] = i + 1, U[i] = D[i] = i;
    }
    L[0] = c, R[c] = 0;
    memset(siz, 0, sizeof(siz));
    memset(first, 0, sizeof(first));
}
void remove(int c)
{
    L[R[c]] = L[c], R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i])
        for (int j = R[i]; j != i; j = R[j])
            U[D[j]] = U[j], D[U[j]] = D[j], --siz[col[j]];
}
void recover(int c)
{
    for (int i = U[c]; i != c; i = U[i])
        for (int j = L[i]; j != i; j = L[j])
            U[D[j]] = D[U[j]] = j, ++siz[col[j]];
    L[R[c]] = R[L[c]] = c;
}
void insert(int r, int c)
{
    ++cnt;
    col[cnt] = c, row[cnt] = r, ++siz[c];
    D[cnt] = D[c], U[D[c]] = cnt, U[cnt] = c, D[c] = cnt;
    if (first[r] == 0)
        first[r] = R[cnt] = L[cnt] = cnt;
    else
        R[cnt] = R[first[r]], L[R[first[r]]] = cnt, L[cnt] = first[r], R[first[r]] = cnt;
}
bool dance(int dep)
{
    if (R[0] == 0)
    {
        ans = dep;
        return true;
    }
    int c = R[0];
    for (int i = R[0]; i != 0; i = R[i])
        if (siz[i] < siz[c])
            c = i;
    remove(c);
    for (int i = D[c]; i != c; i = D[i])
    {
        stk[dep] = row[i];
        for (int j = R[i]; j != i; j = R[j])
            remove(col[j]);
        if (dance(dep + 1))
            return true;
        for (int j = L[i]; j != i; j = L[j])
            recover(col[j]);
    }
    recover(c);
    return false;
}
void init()
{
    scanf("%d%d", &n, &m);
    build(n, m);
    int x;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &x);
            if (x)
                insert(i, j);
        }
}
void solve()
{
    dance(1);
    if (ans)
        for (int i = 1; i < ans; ++i)
            printf("%d ", stk[i]);
    else
        printf("-1");
}
int main()
{
    init();
    solve();
    return 0;
}