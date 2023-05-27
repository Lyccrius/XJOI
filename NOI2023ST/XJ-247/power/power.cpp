#include<bits/stdc++.h>
using namespace std;
int check(long long x,long long y){
	for(long long i=2;i<sqrt(x)+1;i++){
		long long t=x,sum=0;
		while(t>1&&t%i==0){
			t/=i;
			sum++;
		}
		if(t==1&&sum>=y){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long n;
	long long x;
	cin>>n>>x;
	if(x==1){
		cout<<n;
		return 0;
	}
	long long ans=0;
	for(long long i=2;i<=n;i++){
		if(check(i,x)) ans++;
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
}
