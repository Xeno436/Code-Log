#include <bits/stdc++.h>
#include <cstring>
using namespace std;
char a[6007];
int main()
{

    int i = 1;
    scanf("%c", &a[i]);
    while (a[i] != '\n')
    {
        i++;
        scanf("%c", &a[i]);
    }
    string c(a, 1, i - 1);
    cout << c << endl;
    // int pos1 = c.find("n ", 0);

    // while (pos1 != -1)
    // {
    //     c = c.replace(pos1, 2, "ng ");
    //     pos1 = c.find("n ", pos1);
    // }
    // cout << c << endl;
    return 0;
}