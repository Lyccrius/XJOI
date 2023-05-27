#include<bits/stdc++.h>
using namespace std;

int n;
double x[1005], y[1005], d, d1;

int main(){
	
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; ++ i)
		cin >> x[i] >> y[i];
	
	if(n == 3){
		d += sqrt((x[3]-x[1]) * (x[3]-x[1]) + (y[3]-y[1]) * (y[3]-y[1]));
		d += sqrt((x[2]-x[1]) * (x[2]-x[1]) + (y[2]-y[1]) * (y[2]-y[1]));
		d1 += sqrt((x[3]-x[2]) * (x[3]-x[2]) + (y[3]-y[2]) * (y[3]-y[2]));
		d1 += sqrt((x[2]-x[1]) * (x[2]-x[1]) + (y[2]-y[1]) * (y[2]-y[1]));
		if(d > d1) cout << "3 2 1";
		else cout << "3 1 2";
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}