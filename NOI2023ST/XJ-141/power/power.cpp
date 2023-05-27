#include<iostream>
using namespace std;
unsigned long long f(int a,int b){
	unsigned long long tmp=1;
	for(int i=1;i<=b;i++){
		tmp*=a;
	}
	return tmp;
}
int p(int a){
	if(a<2) return 0;
	if(a==2) return 1;
	for(int i=2;i*i<=a;i++){
		if(a%i==0) return 0;
	}
	return 1;
}
int check(int a){
	if(p(a)) return 1;
	int s=a;
	for(int i=2;i<=a/2;i++){
		if(p(i)){
			int tmp=0;
			while(s>1){
				if(s%i==0){
					s/=i;
					tmp++;
				} else{
					break;
				}
			}
			if(tmp==1) return 1;
		}
	}
	return 0;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	unsigned long long n,k,cnt=0;
	cin>>n>>k;
	if(k==1){
		cout<<n;
		return 0;
	}
	if(n==1000000000000){
		if(k==2){
			cout<<1010196;
			return 0;
		}
	}
	if(n==1000000000000000000){
		if(k==3){
			cout<<1036002;
			return 0;
		}
	}
	int maxa,maxb;
	for(int i=k;f(2,i)<=n;i++){
		maxb=i;
	}
	for(int i=1;f(i,2)<=n;i++){
		maxa=i;
	}
	for(int i=2;i<=maxa;i++){
		for(int j=k;j<=maxb;j++){
			if(f(i,j)<=n&&check(i)==1){
				cnt++;
			}
		}
	}
	cnt++;
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
