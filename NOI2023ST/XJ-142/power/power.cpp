#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long int n,k,a,b,f=0,c=0;
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	m
	for(int i=1;i<=n;i++){
		for(a=2;pow(a,k)<=i;a++){
			f=0;
			for(b=k;pow(a,b)<=i&&b<=100;b++){
				if(pow(a,b)==i){
					f=1;
					c++;
					break;
				}
			}
			if(f==1){
				break;
			}
		}
	}
	cout<<c+1;
	return 0;
}
