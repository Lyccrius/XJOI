#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,m,q;
int maps[10005][10005];
signed main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>t;

	while(t--){
		memset(maps,0,sizeof maps);
		cin>>n>>m>>q;
		for(int i=1;i<=q;i++){//times
			int opt,x,c;
			cin>>opt>>x>>c;
			if(opt==0){//row
				for(int j=1;j<=m;j++){
					maps[x][j]=c;
				}
			}else if(opt==1){
				for(int j=1;j<=n;j++){
					maps[j][x]=c;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<maps[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
