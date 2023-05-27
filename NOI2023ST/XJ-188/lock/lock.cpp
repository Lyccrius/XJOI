#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int T,n,k,a[50010];
    cin>>T>>k;
    while(T--){
        cin>>n;
        if(k==1){
           for(int i=1;i<=n;i++){
               cin>>a[i];
           }
           sort(a+1,a+n+1);
           cout<<a[n]-a[1];
        }
    }
    return 0;
}