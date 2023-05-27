#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath> 
using namespace std;
int b[90000005];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int k=0,n=0;
	cin >> n >> k;
	if(k==1){
		cout << n;
		return 0;
	}
	for(int i=1;i<=sqrt(n);i++){
		for(int j=k;j<=20;j++){
			if(pow(i,j)>90000005)break;
			int t=pow(i,j);
			if(t>n)break;
			b[t]=j;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(b[i]>=k){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
