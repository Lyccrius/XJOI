#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	if(k==1){  
		cout<<n;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=2;j<=k;j++){
				if(pow(i,j)<=n){
					sum++;
					break;
				}	
			}
		}
	}
	cout<<sum;
	return 0;
}
