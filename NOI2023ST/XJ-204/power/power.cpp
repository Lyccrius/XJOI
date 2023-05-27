#include <iostream>
#include <cstdio>
using namespace std;
int a[100010]={0};
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n,k,x=1,y=1;
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	else for(int s=2;s*s<=n;s++){
			for(int l=k;l<=10;l++){
				x*=s;
			}
			if(x<=n){
				if(a[x]==1)continue;
				else {
					y+=1;
					a[x]=1;
				}
		}
	}
	cout<<y;
	return 0;
}
