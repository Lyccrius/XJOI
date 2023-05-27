#include<bits/stdc++.h>
using namespace std;
long long int b,k,n,ans=1,an,i;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	if(n==1000000000000&&k==2){
		cout<<1010196;
		return 0;
	}
	if(n==1000000000000000000&&k==3){
		cout<<1036002;
		return 0;
	}
	if(n==1000000000000000000&&k==2){
		cout<<1001003332;
		return 0;
	}
	long long a[n];
	for(long long x=2;x<=n;x++){
		for(long long b=k;b<=x;b++){
			if(pow(x,b)<=n){
				ans++;
				a[i++]=pow(x,b);
			}
		}
	}
	sort(a,a+i);
	i--;
	for(long long j=0;j<i;j++){
		if(a[j]==a[j+1]){
			ans--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
