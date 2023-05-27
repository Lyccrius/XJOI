#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("transfer.in", "r", stdin);
    freopen("transfer.out", "w", stdout);
    int sid, n, k, m, a, mx = 0, mn = 100010, ans = 0;
    cin>>sid>>n>>k>>m;
    for(int i = 2; i <= n; i ++)
        cin >> a;
    for(int i = 1; i <= k; i ++){
        int x, y;
        cin >> x >> y;
        ans += y;
    }
        cout << ans;
    return 0;
}