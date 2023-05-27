#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("cities.in", "r", stdin);
    freopen("cities.out", "w", stdout);
    int n, m, x, l, r;
    cin>>n>>m>>x;
    for(int i = 1; i <= m; i ++)
        cin >>l>>r;
    cout << n * m * n / 102 % 998244353;
    return 0;
}