#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main()
{
    v.push_back(1);
    v.push_back(2);
    printf("%d %d ", v[0], v[1]);
    v.pop_back();
    printf("%d", v.size());
    return 0;
}