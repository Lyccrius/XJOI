#include<iostream>
#include<cmath>
using namespace std;
const int N=1000005;
bool a[N];
int c[N];
long long n;
long long t;
long long s;
long long ans=1;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	for(long long i=2;i<=N;i++){
		if(a[i])continue;
		for(long long j=i*i;j*i<=N;j=j*i){
			a[j]=1;
		}
	}
	int tot=1;
	for(long long i=2;i<=N;i++){
		if(!a[i]){c[tot]=i,tot++;}
	}
	cin>>n>>s;
	if(s==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=100;i++)
		cout<<c[i]<<" ";
	for(int i=1;i<=tot;i++){
		t=log(n)/log(c[i]);
		if(t<s)break;
		t=t-s+1;
		ans+=t;
	}
	cout<<endl<<ans;
}
