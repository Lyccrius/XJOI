#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);	
	long long int k,num=1;
	long long int n;
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	long long int k2,n2;
	for(long long int j=4;j<=n;j++){
		for(long long int i=2;pow(i,k)<=j;i+=2){
			
		}
		
	}
	
	cout<<num;
	return 0;
}
