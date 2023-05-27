#include<iostream>
#include<math.h>
using namespace std;
#define LL long long
LL n,k,ans=1;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int flag=-1;
    cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    for(LL i=2;i<=n;i++){
        flag=0;
        for(LL j=2;j<=i;j++){
            for(LL b=k;pow(j,b)<=i;b++){
                if(pow(j,b)==i){
                    ans++;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
             break;
        }
        
    }
    cout<<ans;
    return 0;
}