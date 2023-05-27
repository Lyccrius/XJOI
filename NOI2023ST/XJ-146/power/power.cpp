#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int k;
int a[100000005];
int ans=0;
int get(int x,int y,int z){
	if(x==1)return x;
	if(y==1)return x*z;
	if(y==0) return 1;
	if(y%2==0) return get(x*x,y/2,z);
	else {
		y--;
		z=z*x;
		return get(x*x,y/2,z);
	}
}

signed main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	//cout<<get(n,k,1);
	memset(a,0,sizeof a);
	for(int i=1;i<=n/k+1;i++){
		if(i==1){
			a[1]=1;
			continue;
		}
		int b=get(i,k,1);
		if(a[b]!=0) continue;
		while(b<=n){
			a[b]++;
			b*=i;
			
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0) ans++;
	}
	cout<<ans;
	return 0;
}
