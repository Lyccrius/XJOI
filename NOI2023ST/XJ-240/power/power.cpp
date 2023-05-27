#include<bits/stdc++.h>
using namespace std;
long long n, k, a, ans, check[1000005];
int main()
{
	freopen ("power.in", "r", stdin);
	freopen ("power.out", "w", stdout);
	cin >> n >> k;
	if (1 <= n)	a ++, check[1] = 1;
	for (int j = 2; j <= n; j ++){
		ans = j;
		for (int p = 2; p <= k; p ++)	ans *= ans;
		for (int i = k; ; i ++){
			if (ans <= n){
				if (check[ans] != 1)	a ++;
				check[ans] = 1;
			}
			ans *= ans;
			if (ans > n)	break;
		}
	}
	cout << a << endl;
	return 0;
}
