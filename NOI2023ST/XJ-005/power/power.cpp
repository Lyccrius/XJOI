#include<bits/stdc++.h>
using namespace std;
int a[1050][1050];
int main(){
	int n;
	freopen("power.in","r",stdin);
	freopen("power.out","r",stdout);
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<=n;z++){
				if(i==j*j&&z>=k){
					cout<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
