#include <bits/stdc++.h>
using namespace std;
int n,m,k,r1[200005],r2[200005];
int main(){
	int ans;
	freopen("cities.in","r",stdin);
	freopen("cities.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>r1[i]>>r2[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
