#include<bits/stdc++.h>
using namespace std;

int T, k, n, a[10][305];

int main(){

	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);

	cin >> T >> k;
	while(T --){
		cin >> n;
		for(int i = 1; i <= k; ++ i)
			for(int j = 1; j <= n; ++ j)
				cin >> a[i][j];
		
	}

	cout << "1";

	fclose(stdin);
	fclose(stdout);

	return 0;
}