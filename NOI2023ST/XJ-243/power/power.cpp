#include<bits/stdc++.h>
using namespace std;
long long a[100000010];
int n,k,ans=1;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        cout<<n<<endl;
        return 0;
    }
    for(int i=2;pow(i,k)<=n;i++){
        if(!a[i]){
            long long s=pow(i,k);
            while(s<=n){
                if(!a[s]){
                    ans++;
                    a[s]=1;
                }
                s*=i;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}