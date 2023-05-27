#include<bits/stdc++.h>
using namespace std;

int main(){	
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int n,m;
	int T;
	cin>>T;
	int q;
	while(T--){
		cin>>n>>m>>q;
		int a[10000][10000]={0};
		int opt[10000],x[10000],c[10000];
		for(int i=1;i<=q;i++){
			cin>>opt[i]>>x[i]>>c[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++){
				if(opt[i]==0){
					a[x[i]][j]=c[i];
				}
				if(opt[i]==1){
					a[i][x[i]]=c[i];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		
	}	
	return 0;
}
