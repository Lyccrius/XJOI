#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long int n;
	int k;
	cin>>n>>k;
	long long  int num=0;
	long long int a[100001],s=1;
	for(int i=1;i<=n;i++){
		for(int j=k;j<100;j++){
			if(pow(i,j)<=n){
				a[s]=pow(i,j);
				s++;
			}
		}
	}
	sort(a+1,a+s+1);
	for(int i=1;i<s;i++){
		if(a[i]!=a[i+1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
	

