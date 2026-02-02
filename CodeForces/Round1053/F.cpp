#include <iostream>
#include <vector>
using namespace std;
int const maxn = 307;
int t, n, ans, siz;
bool o;
vector<int> lbot, rbot, lout, rout, btmp, otmp;
bool getans(int l, int r, int x)
{
    printf("? %d %d", x, r - l + 1);
    for (int i = l; i <= r; ++i)
        printf(" %d", i);
    printf("\n");
    fflush(stdout);
    scanf("%d", &o);
    return o;
}
void binary(int l, int r, vector<int> bot, vector<int> out)
{
    // printf("%d %d\n", l, r);
    if (l == r)
    {
        ans = bot[0];
        return;
    }
    lbot.clear();
    rbot.clear();
    lout.clear();
    rout.clear();
    siz = bot.size();
    bool lo, ro;
    int mid = l + (r - l >> 1);
    // printf("%d\n", mid);
    for (int i = 0; i < siz; ++i)
    {
        lo = getans(l, mid, bot[i]);
        ro = getans(mid + 1, r, bot[i]);
        if (lo and ro)
        {
            lout.push_back(bot[i]);
            rout.push_back(bot[i]);
        }
        if (lo and !ro)
            lbot.push_back(bot[i]);
        if (!lo and ro)
            rbot.push_back(bot[i]);
    }
    siz = out.size();
    for (int i = 0; i < siz; ++i)
    {
        if (getans(l, mid, out[i]))
            lout.push_back(out[i]);
        else
            rout.push_back(out[i]);
    }
    if (lbot.size() * 2 + lout.size() == mid - l + 2)
    {
        binary(l, mid, lbot, lout);
    }
    else
    {
        binary(mid + 1, r, rbot, rout);
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        btmp.clear();
        for (int i = 1; i <= n; ++i)
            btmp.push_back(i);
        otmp.clear();
        binary(1, 2 * n - 1, btmp, otmp);
        printf("! %d", ans);
        if (t)
            printf("\n");
        fflush(stdout);
    }
}