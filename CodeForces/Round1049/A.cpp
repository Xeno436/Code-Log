#include <iostream>
using namespace std;
int t, n;
int a, b;
string s;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        a = b = 0;
        cin >> s;
        for (int i = 0; i < n; ++i)
            a += s[i] - '0';
        for (int i = 0; i < n - a; ++i)
            b += s[i] - '0';
        printf("%d", b);
        if (t)
            printf("\n");
    }
}