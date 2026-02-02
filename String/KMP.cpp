#include <iostream>
#include <cstring>
using namespace std;
string a, b;
int const maxn = 2e6 + 7;
int p[maxn], c, ans;
int main()
{
    cin >> a >> b;
    c = b.length();
    b = b + '*' + a;
    for (int i = 1; i < b.length(); ++i)
    {
        int j = p[i - 1];
        while (j > 0 and b[j] != b[i])
            j = p[j - 1];
        if (b[j] == b[i])
            j++;
        p[i] = j;
        // printf("%d ", p[i]);
        if (p[i] == c)
            printf("%d\n", i - c - c + 1);
    }
    for (int i = 0; i < c; ++i)
        printf("%d ", p[i]);
    return 0;
}