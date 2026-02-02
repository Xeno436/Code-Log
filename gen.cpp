#include <bits/stdc++.h>
#include <sys/timeb.h>
int main()
{
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);
    // 生成随机数种子，利用 timeb 生成毫秒级别随机数
    printf("%d %d\n", rand(), rand());
    // 这样就生成了2个随机数
}