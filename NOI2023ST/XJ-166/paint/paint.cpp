#include<bits/stdc++.h>
using namespace std;
long long opt[100001],x[100001],c[100001],ans[100001][100001];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int n,m,q,t;
	cin>>t; 
	for(int i=1;i<=t;i++){
		cin>>n>>m>>q;
		if(q==0){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					cout<<"0 ";
				}
				cout<<endl;
			}
		}
		else{
			for(int j=1;j<=q;j++){
				cin>>opt[j]>>x[j]>>c[j];
				if(opt[j]==0){
					for(int p=1;p<=n;p++){
						ans[x[j]][p]=c[j];
					}
				}
				if(opt[j]==1){
					for(int k=1;k<=n;k++){
						ans[k][x[j]]=c[j];
					}
				}
			}
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					cout<<ans[j][k]<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
