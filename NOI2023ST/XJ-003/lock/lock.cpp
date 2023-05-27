#include<bits/stdc++.h>
using namespace std;
int T,k,n,a[5][30005];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>T>>k;
	while(T--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
		
	}
	return 0;
}
