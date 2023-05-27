#include <iostream>
#include <cmath>
using namespace std;
int a[400000000];
int main(){
	long long int i,j,n,k,t,p=0,b,s=0;
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	b=k;
	for(i=2;i<=sqrt(n);i++){
		t=0;
		for(j=2;j<=sqrt(i);j++){
			if(i%j==0){
				t++;
			}
		}
		if(t==0){
			a[p]=i;
			p++;
		}
	}
	for(i=4;i<=n;i++){
		for(j=0;j<p;j++){
			b=1;
			t=0;
			while(b<i){
				b=b*a[j];
				t++;
			}
			if(b==i && t>=k){
				cout<<b<<endl;
				s++;
				break;
			}
		}
	}
	cout<<s+1;
	return 0;
}
