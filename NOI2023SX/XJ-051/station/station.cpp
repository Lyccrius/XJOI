#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int head[100005],t,n,m,x,cnt;
int ans[100005],as;
int mp[20005][20005];
int main(){
		freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		mp[a][b]=1;
		mp[b][a]=1;
}
	for(int i=t;i>=1;i--){
		if(mp[t][i])ans[i]=1;
		for(int j=t;j>=i;j--){
				for(int k=j;k>=1;k--)
					if(mp[j][k])ans[k]=1;
		}
	}
	for(int i=t;i<=n;i++){
		if(mp[t][i])ans[i]=1;
		for(int j=t;j<=i;j++){
				for(int k=j;k<=n;k++)
					if(mp[j][k])ans[k]=1;
		}
	}
	for(int i=1;i<=n;i++){
			if(ans[i]&&i!=t)cout<<i<<" ";
	}
	return 0;
	
}
