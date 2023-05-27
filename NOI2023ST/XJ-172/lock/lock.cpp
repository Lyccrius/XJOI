#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int a[6][50001];
int main(){
  freopen("lock.in","r",stdin);
  freopen("lock.out","w",stdout);
  int t,k;scanf("%d%d",&t,&k);
  while(t--){
    memset(a,0,sizeof(a));
    int n;scanf("%d",&n);
    if(n==1){
      puts("0");
      continue;
    }
    if(k==1){
      int mx=-1e9,mn=1e9;
      for(int i=1;i<=n;++i)
        scanf("%d",&a[0][i]),mx=max(mx,a[0][i]),mn=min(mn,a[0][i]);
      printf("%d\n",mx-mn);
    }else if(k==2){
      for(int i=1;i<=n;++i)
        scanf("%d",&a[1][i]);
      for(int i=1;i<=n;++i){
        scanf("%d",&a[2][i]);
        if(a[1][i]>a[2][i])a[1][i]^=a[2][i]^=a[1][i]^=a[2][i];
      }
      for(int i=1;i<=n;++i){

      }
    }
  }
}