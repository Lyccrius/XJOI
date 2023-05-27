#include<stdio.h>
#include<math.h>
#define N 100000050

int k;
long long n,cnt;
bool f[N]={true,true};

void prim(){
	for(long long i=2;i*i<=n;i+=1){
		if(f[i]) continue;
        for(long long j=i*i;j*j<=n;j*=i)
            f[j]=true;
	}
	return;
}

int main(){

	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);

	scanf("%lld%lld",&n,&k);
	prim();
	if(k==1){
		printf("%lld",n);
		return 0;
	}

	for(long long i=2;i<=n;i+=1){
        if(f[i]) continue;
		long long t=log(double(n))/log(double(i))+1;
		//printf("%lld %lld\n",i,t);
		if(t>k) cnt+=t-k;
		else break;
	}

	printf("%lld",cnt+1);

	return 0;
}
