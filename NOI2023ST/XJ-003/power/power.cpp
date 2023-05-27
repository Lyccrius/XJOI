#include<bits/stdc++.h>
using namespace std;
long long n;
int k,num=1;
bool v[1000000005];
long long power(int a,int b){
	long long sum=1;
	while(b--) sum*=a;
	return sum;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	memset(v,0,sizeof(v));
	if(k==1){
		cout<<n;
		return 0;
	}
	for(int i=2;i<n;i++){
		for(int j=k;;j++){
			long long s=power(i,j);
			if(s>n) break;
			if(!v[s]) num++;
			v[s]=1;
		}
	}
	cout<<num;
	return 0;
}
