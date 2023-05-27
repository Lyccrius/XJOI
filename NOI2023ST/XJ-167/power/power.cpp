#include<bits/stdc++.h>
#include<cmath>
using namespace std;

long long int n,k,cnt,ans,a[10000000];

void dfs(int p,int q){
    if(p==1||!p%q) return;
    if(p%q==0){
        cnt+=1;
        dfs(p/q,q);
    }else cnt=0;
}

int main(){
    freopen("./power.in","r",stdin);
    freopen("./power.out","w",stdout);
    cin>>n>>k;
    if(k==1) cout<<n;
    else{
        for(int i=2;i<=n;i++){
            for(int j=2;j<=i;j++){
                if(i%j==0&&a[i]==0){
                    cnt=0;
                    dfs(i,j);
                    if(cnt>=k){
                        ans++;
                        a[i]=1;
                    }
                }
                else if(a[i]==1){
                    break;
                }
            }
        }
    cout<<ans+1;
    }
    return 0;
}