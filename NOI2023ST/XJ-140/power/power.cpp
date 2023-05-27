#include<bits/stdc++.h>
using namespace std;
long long n;
int f[100000000];
int k,ans;
void judge(int a){
    for(long long i=2;i*i<=a;i++){
        int cnt=1;
        for(long long j=i,b=j;j<a;j=b*j,cnt++){
           f[j]=max(f[j],cnt);
       }
    }
}
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    memset(f,0,sizeof f);
    cin>>n>>k;
    if(n>1000000000)n=(int)sqrt(n);
    if(k==1){
        cout<<n;
        return 0;
    }
    f[1]=2147483647;
    judge(n);
    
    for(int i=1;i<n;i++){
        if(f[i]>=k)ans++;
        //cout<<f[i]<<endl;
    }
    cout<<ans;
    return 0;
}