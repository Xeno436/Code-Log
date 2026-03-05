#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int const maxn = 2e5 + 7;
int t, n, a;
int check(int x) {
    int i = 1;
    while (x > (1 << i)) i++;
    if (x == (1 << i)) return 0;
    return a = x - (1 << i - 1);
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (check(n) == 0) {
            puts("-1");
            continue;
        }
        if (n % 2 == 1) {
            printf("%d ", n - 1);
            for (int i = 2; i < n; i++)
                if (i % 2)
                    printf("%d ", i - 1);
                else
                    printf("%d ", i + 1);
            printf("%d\n", 1);
        } else {
            for (int i = 1; i < n; i++) {
                if (i == 1)
                    printf("%d ", a + 1);
                else if (i == a)
                    printf("%d ", n);
                else if (i % 2)
                    printf("%d ", i - 1);
                else
                    printf("%d ", i + 1);
            }
            printf("%d\n", 1);
        }
    }
    return 0;
}