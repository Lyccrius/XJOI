#include <bits/stdc++.h>
using namespace std;
long long a,b,maxmi,ans,s[1000005],scnt;
bool prime[100005];
long long primes[100005],primecnt;
long long cimi(long long ds,long long zs){
	long long fhz=1;
	for(int i=1;i<=zs;i++){
		fhz*=ds;
	}
	return fhz;
}
void findprime(){
	primes[1]=2;
	prime[2]=true;
	primecnt=1;
	for(int i=3;i<=100000;i++){
		int flagp=0;
		for(int j=1;j<=primecnt;j++){
			if(i%primes[j]==0){
				flagp=1;
				break;
			}
		}
		if(flagp==0){
			primecnt++;
			prime[i]=true;
			primes[primecnt]=i;
		}
	}
	return;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	findprime();
    cin>>a>>b;
	for(int i=b;cimi(2,i)<=a;i++){
		int flag=0;
		for(int j=b;j*2<=i;j++){
			if(i%j==0&&i!=j){
				flag=1;
				break;
			}
		}
		if(flag==1) continue;
		for(long long j=2;j;j++){
			if(cimi(j,i)<=a){
				int flag1=0;
				for(int k=1;k<=scnt;k++){
					if(s[k]==cimi(j,i)){
						flag1=1;
						break;
					}
				}
				if(flag1==1) continue;
				if(flag1==0&&prime[j]==false){
					scnt++;
					s[scnt]=cimi(j,i);
				}
				ans++;
			}
			else break;
		}
	}
	cout<<ans+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
