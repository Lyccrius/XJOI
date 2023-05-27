#include <bits/stdc++.h>
using namespace std;

long long flag[100000010];

int main() {
	freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
	long long n, k;
	scanf("%lld%lld", &n, &k);
	if (k == 1) {
		printf("%lld\n", n);
	}else {
		flag[1] = 1;
		long long ans = 1;
		for (long long i = 2; i <= n; i++) {
			long long b = 1;
			for (long long j = 1; j <= k; j++) {
				b *= i;
			}
			for (long long j = b; j <= n; j *= i) {
				if (flag[j] == 0) {
					ans += 1;
				}
				flag[j] = 1;
			}
		}
		printf("%lld\n", ans);
	}
    return 0;
}
