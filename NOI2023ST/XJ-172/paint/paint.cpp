#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int read(){
  char c;
  int r=0;
  while((c=getchar())<'0'||c>'9');
  while('0'<=c&&c<='9'){
    r=(r<<3)+(r<<1)+(c^48);
    c=getchar();
  }
  return r;
}
int main(){
  freopen("paint.in","r",stdin);
  freopen("paint.out","w",stdout);
  int t;cin>>t;
  while(t--){
    int n,m,q;n=read();m=read();q=read();
    if(max(n,m)*q<=1e7&&n*m<=1e7){
      int a[n+10][m+10]{};
      while(q--){
        int op,x,c;op=read();x=read();c=read();
        if(!op){
          for(int j=1;j<=m;++j)
            a[x][j]=c;
        }else{
          for(int i=1;i<=n;++i)
            a[i][x]=c;
        }
      }
      for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
          printf("%d ",a[i][j]);
        puts("");
      }
    }else{
      int a[n+10]{};
      while(q--){
        int op,x,c;op=read();x=read();c=read();
        a[x]=c;
      }
      for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
          printf("%d ",a[i]);
        puts("");
      }
    }
  }
}