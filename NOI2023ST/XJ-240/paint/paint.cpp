#include<bits/stdc++.h>
using namespace std;
long long T, n, m, q, opt, c, ans[10005][10005];
long long lie, hang, x;
int main()
{
	freopen ("power.in", "r", stdin);
	freopen ("power.out", "w", stdout);
	scanf ("%lld", &T);
	for (int i = 1; i <= T; i ++){
		scanf ("%lld %lld %lld", &n, &m, &q);	
		for (int j = 1; j <= q; j ++){
			scanf("%lld %lld %lld", &opt, &x, &c);
			if (opt == 1){
				lie = x;
				for (int k = 1; k <= m; k ++)
					ans[k][lie] = c;
			}
			if(opt == 0){
				hang = x;
				for (int k = 1; k <= n; k ++)
					ans[hang][k] = c;
			}
		}
		for (int j = 1; j <= n; j ++){
			for (int k = 1; k <= m; k ++)
				printf("%lld ", ans[j][k]);
			printf("\n");
		}
		for (int j = 1; j <= n; j ++)
			for (int k = 1; k <= m; k ++)
				ans[j][k] = 0;
	}

	return 0;
}
