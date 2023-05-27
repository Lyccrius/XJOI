#include <bits/stdc++.h>
using namespace std;
int a[10001][10001];
int m,n,p,i,j,opt,x,c;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);

	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>p;
		for(i=1;i<=p;i++){
			cin>>opt>>x>>c;
			if(opt==1){
				for(j=1;j<=n;j++){
					a[j][x]=c;
				}
			}else if(opt==0){
				for(j=1;j<=n;j++){
					a[x][j]=c;
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
				a[i][j]=0;
			}
			cout<<endl;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
