#include<bits/stdc++.h>
using namespace std;
long long int n,k,ans,vis[99999999];
int main(){
   /*freopen("power.in","r",stdin);
   freopen("power.out","w",stdout);*/
   cin>>n>>k;
   if(k==1){
       cout<<n;
       return 0;
   }
   for(int i=k;i<=50;i++){
       for(int j=2;j<=n/2;j++){
           int a=1;
           for(int g=1;g<=i;g++){
              a*=j;
           }
           if(a<=n&&vis[a]==0){
               ans++;
               vis[a]=1;
           }else if(a>n){
               break;
           }
       }
   }
   for(int i=1;i<=100;i++){
    cout<<vis[i];
   }
   cout<<ans+1;
   return 0;
}
