#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cnt[536800000];
int ans;
ll f(ll a, ll k){
	int base = a, res = 1;
	while(k){
		if(k%2)
			res *= base;
		base *= base;
		k /= 2;
	}
	return res;
}
int main(){
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    if(k == 1){
		cout << n;
		return 0;
	}
	for(int i = 2; i <= n; i ++)
		for(int j = k; f(i, j) <= n; j ++)
			cnt[f(i, j)] = 1;
	for(int i = 4; i <= n; i ++)
		if(cnt[i])
			ans ++;
	cout << ans + 1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
