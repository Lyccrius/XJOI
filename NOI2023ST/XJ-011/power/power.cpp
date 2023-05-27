#include<bits/stdc++.h>
using namespace std;

long long n, ans = 1;
int k, a[1e8];

int main(){

	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);

	cin >> n >> k;
	if(k == 1) cout << n;

	for(long long i = 2; i <= n; ++ i){
		long long x = i;
		int y = 1;
		if(a[i] == 0){
			while(x <= n){
				x = x * i;
				y ++;
				if(y >= k && x <= n) ans ++;
				a[x] = 1;
			}
		}
		
	}

	cout << ans;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
