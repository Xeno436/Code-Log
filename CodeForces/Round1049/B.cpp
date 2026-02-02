#include <iostream>
using namespace std;
int t, n;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d", n * 2);
        if (t)
            printf("\n");
    }
}