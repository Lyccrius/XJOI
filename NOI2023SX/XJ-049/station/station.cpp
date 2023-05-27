#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[200010];
int a2[200010][2];
void dfs1(int q){
	for(int i=1;i<=m;i++){
		if(a2[i][1]==q){
			a[a2[i][0]]=1;
			for(int j=1;j<=m;j++){
				if(a2[j][1]<a2[i][1]&&a2[j][1]>=a2[i][0]){
					a[a2[j][0]]=1;
					dfs1(a2[j][1]);
				}
			}
		}

	}
	return ;
}
void dfsn(int q){
	for(int i=1;i<=m;i++){
		if(a2[i][0]==q){
			a[a2[i][1]]=1;
			for(int j=1;j<=m;j++){
				if(a2[j][0]<=a2[i][1]&&a2[j][0]>a2[i][0]){
					a[a2[j][1]]=1;
					dfsn(a2[j][0]);
				}
			}
		}

	}
	return ;
}
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin >> n >> m >> x;
	for(int i=1;i<=m;i++){
		cin >> a2[i][0] >> a2[i][1];
	}
	dfs1(x);
	dfsn(x);
	for(int i=1;i<=n;i++){
		if(i==x) continue;
		if(a[i]==1) cout << i << " ";
	}
	return 0;
}
