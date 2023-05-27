#include<bits/stdc++.h>
using namespace std;
long long n,m,t;
long long a[10000][10000];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	long long opt,x,c,n,m,q;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>q;
		memset(a,0,sizeof(a));
		for(int j=0;j<q;j++){
			cin>>opt>>x>>c;
			if(opt==0){
				for(int f=0;f<n;f++){
					a[x-1][f]=c;
				}
			}else{
				for(int f=0;f<m;f++){
					a[f][x-1]=c;
				}
			}
		}
		for(int k=0;k<n;k++){
			for(int j=0;j<m;j++){
				cout<<a[k][j]<<' ';
			}
			cout<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
