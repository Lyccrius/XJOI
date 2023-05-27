#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T, n, m, q, opt[N], x[N], c[N];
int a[N][N];

int main(){

	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	cin >> T;
	while(T --){
		cin >> n >> m >> q;
		for(int i = 1; i <= q; ++ i)
			cin >> opt[i] >> x[i] >> c[i];

		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= m; ++ j){
				for(int k = q; k >= 1; -- k){
					if(opt[k] == 0 && x[k] == i || opt[k] == 1 && x[k] == j){
						a[i][j] = c[k];
						break;
					}
				}
			}
		}

		for(int i = 1; i <= n; ++ i){
			for(int j = 1; j <= m; ++ j)
				cout << a[i][j] << " ";
			cout << endl;
		}

		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= m; ++ j)
				a[i][j] = 0;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
