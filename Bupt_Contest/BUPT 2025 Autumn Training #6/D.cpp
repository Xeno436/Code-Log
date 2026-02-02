// ac
#include <iostream>
using namespace std;
char s[9];
int main()
{
    cin >> s;
    int a, b;
    a = 0, b = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (s[i] == 'T')
        {
            a++;
            if (a >= 3)
            {
                printf("T1");
                return 0;
            }
        }
        if (s[i] == 'D')
        {
            b++;
            if (b >= 3)
            {
                printf("DRX");
                return 0;
            }
        }
    }
}