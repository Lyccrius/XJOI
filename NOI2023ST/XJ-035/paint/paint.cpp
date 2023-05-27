#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int t;
	cin>>t;
	for(int e=1;e<=t;e++){
	int opt,x,c,m,n,q,a[105][105];
	cin>>n>>m>>q;
		for(int j=1;j<=q;j++){
			cin>>opt>>x>>c;
			if(opt==0){
				for(int g=1;g<=n;g++){
					a[x][g]=c;
					}
			}
			if(opt==1){
				for(int g=1;g<=n;g++){
					a[g][x]=c;
					}
				}
		}
	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
				if(j==m){
					cout<<endl;
					}
					
				}
			}
		}
	return 0;
}
