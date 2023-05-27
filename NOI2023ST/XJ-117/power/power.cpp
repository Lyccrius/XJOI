#include<bits/stdc++.h>
using namespace std;
int n, k, cnt, ans;
long long int a[10000010];
int main() {
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    cin >> n >> k;
    if(k == 1) {
        cout << n;
        return 0;
    }
    a[1] = 1;
    for(int i = 2; i <= n ; i++) {
        cnt = i;
        for(int j = 2 ; cnt < n ; j++) {
            cnt *= i;
            if(a[cnt] < j) a[cnt] = j;
        }
    }
    for(int i = 1 ; i <= n ; i++) {
        //cout << a[i] << " ";
        if(a[i] >= k) ans++;
    }
    cout << ans + 1;
    return 0;
}
//"I cannot get even 30 percents of points from this!"