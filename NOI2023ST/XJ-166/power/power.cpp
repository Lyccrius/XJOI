#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long n,k,i,j,ans,flag[1000001],sum=0;
	cin>>n>>k;
	if(k==1){
		cout<<n;
	}
	for(i=1;i<=n;i++){
		for(j=k;j<=n;j++){
			ans=i*i;
		}
		if(flag[ans]=0&&ans<=n){
			sum++;
			flag[ans]=1;
			ans=0;
		}
	}
	cout<<sum<<endl;
	return 0;
}
