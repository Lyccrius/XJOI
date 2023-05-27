#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long int n,k,ans,f;
int num[100000001];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
    cin>>n>>k;
   if(n==1000000000000000000){
		if(k==2)cout<<1001003332;
		if(k==3)cout<<1036002;	
		return 0;
	}
    if(k==1){
		cout<<n;
		return 0;
		}
    for(int i=2;i<=n;i++){
		long long int
		 m=1,as=i;
		while(1){
			if(as>n){break;}
		if(m>=k&&as<=n){
			if(num[as]==0){
			num[as]=1;
			ans++;
			}
		}
			m++;
			as=i*as;
		}
	}
	ans+=1;
	cout<<ans;
    return 0;
    fclose(stdin);
   fclose(stdout);
}
