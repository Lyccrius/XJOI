#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k, ans = 1;
bool b[1000000005];
int main(){
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    cin >> n >> k;
    if (k == 1){
        cout << n;
        return 0;
    }
    for (ll i = 2; i <= n; i++){
        if (b[i] == 1) continue;
        ll sum = pow(i, k - 1);
        while (1){
            sum *= i;
            if (b[sum] == 1) break;
            if (sum > n) break;
            ans++;
            b[sum] = 1;
        }
    }
    cout << ans;
    return 0;
}