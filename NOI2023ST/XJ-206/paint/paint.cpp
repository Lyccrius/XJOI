#include<bits/stdc++.h>
using namespace std;
int a[10001][10001];
long long int t,n,m,q,opt,x,c;
void nm(long long int n,long long int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j]=0;
		}
	}
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>q;
		for(int j=1;j<=q;j++){
			cin>>opt>>x>>c;
			if(opt==0){
				for(int num=1;num<=m;num++){
					a[x][num]=c;
				}
			}
			else if(opt==1){
				for(int num=1;num<=n;num++){
					a[num][x]=c;
				}
			}	
		}
		for(int j=1;j<=n;j++){
			for(int jj=1;jj<=m;jj++){
				cout<<a[j][jj]<<" ";
			}
			cout<<endl;
		}	
		nm(n,m);
	}	
	return 0;
}
