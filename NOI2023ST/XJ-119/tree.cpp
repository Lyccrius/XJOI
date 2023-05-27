#include <bits/stdc++.h>
using namespace std;

struct XY {
	int id;
	double x, y;
};

int n;
XY a[1010];

bool cmp(XY tx, XY ty) {
	return tx.y > ty.y;
}

int vis[1010];
int points[1010];
int mn = -1;
int ans[1010];

void dfs(int depth, double len) {
	if (depth > n) {
		if (mn == -1) {
			mn = len;
			for (int i = 1; i <= n; i++) {
				ans[i] = a[points[i]].id;
			}
		}else {
			if (mn > len) {
				mn = len;
				for (int i = 1; i <= n; i++) {
					ans[i] = a[points[i]].id;
				}
			}
		}
	}
	XY last = a[points[depth - 1]];
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			int dx = abs(last.x - a[i].x) * abs(last.x - a[i].x);
			int dy = abs(last.y - a[i].y) * abs(last.y - a[i].y);
			int tlen = sqrt(dx + dy);
			points[depth] = i;
			dfs(depth + 1, len + tlen);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	/*for (int i = 0; i < n; i++) {
		printf("%.9f %.9f\n", a[i].x, a[i].y);
	}*/
	vis[1] = 1;
	points[1] = 1;
	dfs(2, 0);
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
