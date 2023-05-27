#include<bits/stdc++.h>
using namespace std;
int a,b;
bool check(int x){
	if(x==1||b==1) return true;
	int m=2,n=b;
	while(m<=sqrt(x)){
		if(m%2!=x%2){
			m++;
			n=b;
			continue;
		}
		while(pow(m,n)<=x){
			if(pow(m,n)==x) return true;
			n++;
		}
		m++;
		n=b;
	}
	return false;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int c=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		if(check(i)==1){
			c++;
		}
	}
	cout<<c;
	return 0;
}
