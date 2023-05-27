#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,ans=0;
long long qpow(long long a,long long b){
    long long base=a,res=1;
    while(b>0){
        if(b%2==1){
            res*=base;
        }
        base*=base;
        b/=2;
    }
    return res;
}
bool check(long long x){
	if(x==1){
		ans++;
		return true;
	}
    for(int a=2;a<=x;a++){
        for(int b=k;qpow(a,b)<=x;b++){
            if(qpow(a,b)==x){
                ans++;
                return true;
            }
        }
    }
    return false;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
    long long x;
    scanf("%lld%lld",&n,&k);
    for(x=1;x<=n;x++){
        if(check(x)){
            continue;
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
