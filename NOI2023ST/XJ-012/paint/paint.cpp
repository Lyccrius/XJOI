#include<bits/stdc++.h>
using namespace std;
int p[100005][100005];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int opt,n,m,q,x,c,t;
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>m>>q;
		for(int i=1;i<=q;i++){
			cin>>opt>>x>>c;
			if(opt==0){
				for(int j=1;j<=m;j++){
					p[x][j]=c;
				}
			}
			else if(opt==1){
				for(int j=1;j<=n;j++){
					p[j][x]=c;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<p[i][j]<<" ";
				p[i][j]=0;
			}
			cout<<endl;
		}
	}
	return 0;	
}
