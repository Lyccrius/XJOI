#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
	long long n,k,ans = 1,i = 2,a[1000000000000000005];
	scanf("%lld%lld",&n,&k);
	while(1){
		long long v = i;
		for(int j = 1; j < k; j++){
			i = i * i;
		}
		if(i > n){
			break;
		}
		for(int j = k; i <= n; j++){
			if(i <= n){
				a[i] = 1;
			}else{
				i = v + 1;
				break;
			}
			i = i * i;
		}
	}
	for(long long j = 1; j <= n; j++){
		if(a[j] == 1){
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
