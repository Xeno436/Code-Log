#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int const maxn = 1e6 + 7;
int n, pi[maxn];
char a[maxn];
string s, t;
int main()
{
    cin >> n;
    cin >> s;
    t = s;
    reverse(s.begin(), s.end());
    s = s + '*' + t;
    // cout << s;
    for (int i = 1; i < n * 2 + 1; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    cout << n - pi[2 * n];
}