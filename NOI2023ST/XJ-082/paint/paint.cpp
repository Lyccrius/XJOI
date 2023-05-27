#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	long long t,m,n,q,a[100005][100005],l,e;
	int o;
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>m>>q;
		for(int y;y<=n;y++){
			for(int h;h<=m;h++){
				a[y][h]=0;
			}
		}
		for(int i=1;i<=q;i++){
			cin>>o>>l>>e;
			if(o==1){
				for(int j=1;j<=n;j++){
					a[j][l]=e;
				}
			}
			if(o==0){
				for(int p=1;p<=m;p++){
					a[l][p]=e;
				}
			}
		}
		for(int t=1;t<=n;t++){//n为行数，m为列数
			for(int u=1;u<=m;u++){
				cout<<a[t][u]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
