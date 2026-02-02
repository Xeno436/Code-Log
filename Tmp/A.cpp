#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 1e4 + 7;
bool a[maxn];
int n;
int pri[maxn], cnt;
void p()
{
    for (int i = 2; i < maxn; ++i)
    {
        if (!a[i])
            pri[++cnt] = i;
        for (int j = 1; j <= cnt and pri[j] * i < maxn; ++j)
        {
            a[pri[j] * i] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}
int main()
{
    // p();
    // for (int i = 1; i <= 25; ++i)
    //     cout << pri[i] << ' ';
    // cin >> n;
    // for (int i = 2; i <= 1e4; ++i)
    //     a[i] = 1;
    // for (int i = 2; i <= 1e4; ++i)
    //     for (int j = 2; j < i; ++j)
    //         if (i % j == 0)
    //             a[i] = 0;
    // for (int i = 2; i + i <= n; ++i)
    //     if (a[i] and a[n - i])
    //         printf("%d and %d\n", i, n - i);
    char **s;
    strcpy(*s, "book");
    *s = "book";
    cout << *s;
}