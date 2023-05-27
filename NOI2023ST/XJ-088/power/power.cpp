#include<bits/stdc++.h>
using namespace std;
long long int n,k;
long long int a[1000000000000000010];
long long int s;
bool doing (long int n1,long int k1){
    long long int s1=1;
   for(int i=1;i<=k1;i++){
        if(i>=k)a[s1]=1;
        s1*=n1;
        if(s1>n1)return false;
    }
    return true;
}

bool go(long long int n1,long long int k1){
     if(a[n1]==1||doing (n1,k1))return true;
     else if(go(n1+1,k1))return true;
     else if(go(n1,k1+1))return true;
     else return false; 
}
int main(){
    // freopen("power.in","r",stdin);
    // freopen("power.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    if(k==1){
        printf("%lld",n);
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1||go(i,k))s++;
    }
    printf("%lld",s);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
