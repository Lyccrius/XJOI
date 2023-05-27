#include <bits/stdc++.h>
using namespace std;
long long n,k,ans=0;
bool a[1000000000000000010];
long long cm(int x,int a){
	for(long long i=1;i<=a;i++){
		i++;
		x*=x;
	}
	return x;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		int x=k;
		if(a[i]==0){
			for(long long j=1;j<=i;j++){
				if(cm(j,x)==i){
					ans++;
					for(long long b=i;b<=n;b+=i){
						if(b!=j){
							a[b]=1;
						}
					}
				}
			}
		}
		
	}
	printf("%lln",&ans);
	return 0;
}
