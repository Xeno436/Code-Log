#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int k;
	for (int i = 0, j = 10, k = 0; i < j; i++, j--)
	{
		k += i * j;
	}
	cout << k << endl;
}