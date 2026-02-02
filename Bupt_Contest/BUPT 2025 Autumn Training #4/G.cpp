#include <iostream>
#include <algorithm>

using namespace std;
int const maxn = 1e5 + 7;
int n;
int main()
{
    cin >> n;
    int m = n / 2;
    for (int i = 1; i <= m; ++i)
        cout << 1 << ' ' << 1 << endl;
    for (int i = 1; i <= n - m; ++i)
        cout << 100 << ' ' << 100 << endl;
    cout << endl;
    for (int i = 1; i <= m; ++i)
        cout << 1 << ' ' << 1 << endl;
    for (int i = 1; i <= n - m; ++i)
        cout << 100 << ' ' << 100 << endl;
    return 0;
}