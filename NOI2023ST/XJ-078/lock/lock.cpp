#include <bits/stdc++.h>
using namespace std;
int t,k,n;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    cin>>t>>k;
    while(t--){
		cin>>n;
		if(k==1){
			int maxn=-999999999,minn=999999999,a;
			for(int i=1;i<=n;i++){
				cin>>a;
				maxn=max(maxn,a);
				minn=min(minn,a);
			}
			int ans=maxn-minn;
			cout<<ans;
		}else if(k==2){
			int maxn[50005],minn[50005];
			for(int i=1;i<=n;i++) cin>>maxn[i];
			for(int i=1;i<=n;i++) cin>>minn[i];
			for(int i=1;i<=n;i++){
			    if(maxn[i]<minn[i]){
					swap(maxn[i],minn[i]);
				}
			}
			int xx=-999999999,nx=-999999999,xn=999999999,nn=999999999;
			for(int i=1;i<=n;i++) xx=max(xx,maxn[i]);
			for(int i=1;i<=n;i++) nx=max(nx,minn[i]);
			for(int i=1;i<=n;i++) xn=min(xn,maxn[i]);
			for(int i=1;i<=n;i++) nn=min(nn,minn[i]);
			int ans=max(xx-xn,nx-nn);
			cout<<ans;
		}
		cout<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
