#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int opt,x,c;
	int ans[10005][10005],t,n,m,k;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans[i][j]=0;
			}
		}
		for(int i=1;i<=k;i++){
			cin>>opt>>x>>c;
			for(int j=1;j<=k;j++){
				if(opt==0){
					ans[x][j]=c;
				}
				if(opt==1){
					ans[j][x]=c;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
