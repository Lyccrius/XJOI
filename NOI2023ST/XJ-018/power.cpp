#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int pd[N];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long int n,k,i,j,h,cnt=1;
	cin>>n>>k;
	memset(pd,0,sizeof(N));
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(h=k;h<=100;h++){
				if(i==pow(j,h)&&i!=1&&pd[i]==0){
					pd[i]++;
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
