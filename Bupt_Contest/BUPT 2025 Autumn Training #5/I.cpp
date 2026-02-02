#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int type, t, sum;
string s;
int d, info;
void solve1()
{
    while (t--)
    {
        cin >> s;
        for (int i = 0; i < s.size(); ++i)
            sum += s[i] - '0';
        d = sum / 2000;
        for (int i = 0; i < s.size() - d; ++i)
            sum += s[i] - '0';
        d = sum / 2000;
        for (int i = 0; i < s.size() - d; ++i)
            sum += s[i] - '0';
        info = sum % 2000;
        printf("%d %d\n", d, info);
    }
}
void solve2()
{
    while (t--)
    {
        scanf("%d", &info);
        }
}
int main()
{
    scanf("%d%d", &type, &t);
    if (type == 1)
        solve1();
    else
        solve2();
}