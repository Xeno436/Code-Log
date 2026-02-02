// BAC
#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 10;
int n;
double b[M], B, r;
double a[M];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        B = max(B, b[i]);
    }
    for (int i = 1; i <= 10000; ++i)
    {
        // cout << i << ' ';
        r = double(i) / B;
        bool flag = true;
        for (int j = 1; j <= n; ++j)
        {
            double c = r * b[j];
            if (abs(c - round(c)) > 1e-6)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    for (int j = 1; j <= n; ++j)
        cout << round(r * b[j]) << endl;
    return 0;
}