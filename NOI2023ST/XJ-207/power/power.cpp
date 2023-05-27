#include<bits/stdc++.h>
using namespace std;
long long int n,k,b;
long long int ans=1,c,m=1;
int main(){
	freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1){
		cout<<n;
		return 0;
	}
    for(long long int i=4;i<=n;i++){
		for(long long int j=2;j<=i;j++){
			c=j;
			m=1;
			while(c<i){
				m++;
				c*=j;
			}
			if(c==i&&m>=k){
				ans++;
				break;
			}
		}
	}
    cout<<ans;
    return 0;
}
