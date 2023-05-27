#include<bits/stdc++.h>
using namespace std;
int T,n,m,q,opt,x,c,a[1000005];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cin>>n>>m>>q;
		while(q--){
			cin>>opt>>x>>c;
			if(!opt) for(int i=1;i<=m;i++) a[m*(x-1)+i]=c;
			else for(int i=1;i<=n;i++) a[(i-1)*m+x]=c;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cout<<a[(i-1)*m+j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
