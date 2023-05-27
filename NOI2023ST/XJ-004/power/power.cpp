#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
long long n,k,sum=1;
bool flag=true;
priority_queue <int> pq;
int p(int n,int x){
	int y=1;
	while(x--){
		y*=n;
	}
	return y;
}
bool z(int x){
	for(int i=2;i*i<=x;i++){
		int q=x;
		if(q%i==0){
			q/=i;
			while(q!=1){
				if(q%i!=0){
					break;
				}
				q/=i;
			}
			if(q==1){
				flag=false;
			}
		}
		if(!flag){
			break;
		}
	}
	if(!flag)return true;
	else return false;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	while(p(2,k)<=n){
		for(int i=2;p(i,k)<=n;i++){
			flag=true;
			if(z(i)){
				continue;
			}
			sum++;
		}
		k++;	
	}
	cout<<sum;
	return 0;
}
