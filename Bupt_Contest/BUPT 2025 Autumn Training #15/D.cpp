#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int const maxn = 1e5 + 7;
int a[4], b[4];
string c[4];
int main()
{
    for (int i = 1; i <= 3; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 3 + 1);
    if (b[1] + b[2] < b[3])
    {
        printf("No");
        return 0;
    }
    printf("Yes\n");
    int x = b[1] + b[2] - b[3];
    for (int i = 1; i <= b[1] - x + b[2] - x; ++i)
        c[1] += 'z';
    for (int i = 1; i <= b[1] - x; ++i)
        c[2] += 'b', c[3] += 'z';

    for (int i = 1; i <= b[2] - x; ++i)
        c[2] += 'z', c[3] += 'c';
    for (int i = 1; i <= 3; ++i)
    {
        c[i] += 'a';
        for (int j = 1; j <= x; ++j)
            c[i] += 'c' + (i);
    }
    if (a[1] <= a[2] and a[2] <= a[3])
    {
        cout << c[1] << endl
             << c[2] << endl
             << c[3];
    }
    else if (a[1] <= a[3] and a[3] <= a[2])
    {
        cout << c[2] << endl
             << c[1] << endl
             << c[3];
    }
    else if (a[2] <= a[1] and a[1] <= a[3])
    {
        cout << c[1] << endl
             << c[3] << endl
             << c[2];
    }
    else if (a[2] <= a[3] and a[3] <= a[1])
    {
        cout << c[2] << endl
             << c[3] << endl
             << c[1];
    }
    else if (a[3] <= a[1] and a[1] <= a[2])
    {
        cout << c[3] << endl
             << c[1] << endl
             << c[2];
    }
    else if (a[3] <= a[2] and a[2] <= a[1])
    {
        cout << c[3] << endl
             << c[2] << endl
             << c[1];
    }
    return 0;
}