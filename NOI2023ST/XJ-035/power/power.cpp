#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long int b,k,n,x=0,a[1005]={0},flag=0,y=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(b=k;pow(i,b)<=n;b++){
			if(i==1){
				x++;
				break;
				}
				flag++;
			 for(int j=1;j<=flag;j++){
				 if(pow(i,b)==a[j]){
					 y++;
					 }
				 }
				 if(y==0){
					 a[flag]=pow(i,b);
					 x++;
					 }
					 y=0;
			}
		}
		cout<<x;
		return 0;
}
