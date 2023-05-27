#include<bits/stdc++.h>
using namespace std;
int n,m,T,q,a[1001][100001];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>q;
		memset(a,0,sizeof(a));
		for(int k=1;k<=q;k++){
			int opt,x,c;
			cin>>opt>>x>>c;
			if(opt==0){
				for(int i=x,j=1;j<=m;j++)
					a[i][j]=c;
			}
			else{
				for(int i=1,j=x;i<=n;i++)
					a[i][j]=c;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
