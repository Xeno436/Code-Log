#include <iostream>
#include <vector>
using namespace std;
int n, m;
struct graph
{
    vector<int> info, next, to;
    graph(int n = 0, int m = 0) : to(0), next(0)
    {
        info.resize(n);
        next.reserve(m);
        to.reserve(m);
    }
    int edge_size()
    {
        return to.size();
    }
    int vertex_size()
    {
        return info.size();
    }
    void expand(int i)
    {
        if (info.size() <= i + 1)
            info.resize(i + 1);
    }
    void add(int i, int j)
    {
        expand(i), expand(j);
        next.push_back(info[i]);
        to.push_back(j);
        info[i] = to.size() - 1;
    }
    void del_back()
    {
        for (int i = 0; i < info.size(); ++i)
        {
            if (info[i] == to.size() - 1)
            {
                info[i] = next.back();
                break;
            }
        }
        to.pop_back();
        next.pop_back();
    }
    void clear()
    {
        info.clear();
        next.resize(0);
        to.resize(0);
    }
};
int main()
{
    graph g(10, 0);
    vector<int> a;
    a.push_back(1);
    printf("%d %d ", a.size(), a[0]);
    printf("%d", g.info[0]);
    return 0;
}