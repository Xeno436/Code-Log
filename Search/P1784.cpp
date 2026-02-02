#include <iostream>
#include <cstring>
using namespace std;
// 729rows 324cols
// maxn = 729 * 4 + 324 =
int const maxn = 4207, maxm = 807;
int n, m, cnt;
int row[maxn], col[maxn], siz[maxn], first[maxn];
int U[maxn], D[maxn], L[maxn], R[maxn];
int ans, stk[maxm], num[10][10];
void build()
{
    cnt = m;
    for (int i = 0; i <= m; ++i)
        L[i] = i - 1, R[i] = i + 1, U[i] = D[i] = i;
    L[0] = m, R[m] = 0;
    memset(siz, 0, sizeof(siz));
    memset(first, 0, sizeof(first));
}
void insert(int r, int c)
{
    // printf("%d %d %d\n", r, c, cnt);
    ++cnt;
    col[cnt] = c, row[cnt] = r, ++siz[c];
    U[D[c]] = cnt, D[cnt] = D[c], D[c] = cnt, U[cnt] = c;
    if (first[r] == 0)
        first[r] = L[cnt] = R[cnt] = cnt;
    else
        L[R[first[r]]] = cnt, R[cnt] = R[first[r]], R[first[r]] = cnt, L[cnt] = first[r];
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
bool dance(int dep)
{
    // printf("%d ", dep);
    if (R[0] == 0)
    {
        ans = dep;
        return true;
    }
    int c = R[0];
    for (int i = R[0]; i != 0; i = R[i])
    {
        // printf("%d ", cnt);
        if (siz[i] < siz[c])
            c = i;
    }
    // printf("1");
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
int block(int i, int j)
{
    return i / 3 * 3 + j / 3;
}
void insert(int i, int j, int k)
{
    int r, c;
    r = i * 81 + j * 9 + k + 1;
    c = 81 * 0 + i * 9 + k + 1;
    insert(r, c);
    c = 81 * 1 + j * 9 + k + 1;
    insert(r, c);
    c = 81 * 2 + block(i, j) * 9 + k + 1;
    insert(r, c);
    c = 81 * 3 + i * 9 + j + 1;
    insert(r, c);
}
void init()
{
    n = 729, m = 324;
    build();
    for (int i = 1, x; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
        {
            scanf("%d", &x);
            for (int k = 1; k <= 9; ++k)
                if (x == 0 or x == k)
                    insert(i - 1, j - 1, k - 1);
        }
}
void solve()
{
    dance(1);
    int i, j, k;
    if (ans)
        for (int t = 1; t < ans; ++t)
        {
            // printf("%d\n", stk[i]);
            k = (stk[t] - 1) % 9;
            j = (stk[t] - 1) / 9 % 9;
            i = (stk[t] - 1) / 81;
            num[i + 1][j + 1] = k + 1;
        }
    else
        printf("%d\n", ans);
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
            printf("%d ", num[i][j]);
        puts("");
    }
}
int main()
{
    init();
    solve();
    return 0;
}
/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

8 1 2 7 5 3 6 4 9
9 4 3 6 8 2 1 7 5
6 7 5 4 9 1 0 8 3
1 5 4 2 3 7 8 9 6
3 6 9 8 4 5 7 2 1
2 8 7 1 6 9 5 3 4
5 2 1 9 7 4 3 6 8
4 3 8 5 2 6 9 1 7
7 9 6 3 1 8 4 5 2
*/