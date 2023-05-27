#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int main(){
	freopen("cities.in","r",stdin);
	freopen("cities.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
	}
	for(int i=1;i*i<=n;i++){
		if(n%i==0) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
