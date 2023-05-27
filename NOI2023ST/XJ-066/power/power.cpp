#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt=1;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin >> n >> k;
	if(k==1){
		cout << n << endl;
		return 0;
	}
	for(long long x=1;x<=n;x++){
		int flag=0;
		for(long long i=2;i<=x;i++){
			for(long long j=k;pow(i,j)<=n;j++){
									//cout << i << " " << j << " " << pow(i,j) << " " << x << endl;
				if(pow(i,j)==x){
					flag=1;
					cnt++;
					break;
				}
			}
			if(flag){
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
