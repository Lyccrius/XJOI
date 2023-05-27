// #define K 889
#include<cstdio>
#include<cstring>
int read(){
  int res=0;
  char c;
  while((c=getchar())<'0'||c>'9');
  while('0'<=c&&c<='9'){
    res=(res<<3)+(res<<1)+(c^48);
    c=getchar();
  }
  return res;
}
int T,n,m;
int s[3][150010],t[3][150010];
int a[150010],b[150010];
int vis[150010];
bool A,B,C,D,vis1[150010];
int b_min,ans_X;
int max(int a,int b){
  return a>b?a:b;
}
int min(int a,int b){
  return a<b?a:b;
}
void dfs(int i,bool tr){
  if(!tr&&i>=n){
    b_min=0x7fffffff;
    // fputs("A:\n",stderr);
    dfs(0,1);
    ans_X=(ans_X>=b_min?ans_X:b_min);
    return;
  }
  if(tr&&i>=n){
    // for(int i=0;i<n;++i)
    //   fprintf(stderr,"%d ",a[i]);
    // fputs("\n",stderr);
    // for(int i=0;i<n;++i)
    //   fprintf(stderr,"%d ",b[i]);
    // fputs("\n",stderr);
    int X=0;
    if(!A){
      for(int i=0;i<n;++i)
        X+=(a[i]==b[i]);
    }
    // fprintf(stderr,"%d\n",X);
    // if(b_min>X)fputs("yes\n\n",stderr);
    // else fputs("no\n\n",stderr);
    b_min=(b_min<=X?b_min:X);
    return;
  }
  if(!tr){
    a[i]=s[0][i],dfs(i+1,0);
    if(s[2][i]==2)
      a[i]=s[1][i],dfs(i+1,0);
    a[i]=0;
  }else{
    if(!vis[t[0][i]]){
      b[i]=t[0][i];
      vis[t[0][i]]=1;
      dfs(i+1,1);
      vis[t[0][i]]=0;
    }
    if(t[2][i]==2&&!vis[t[1][i]]){
      b[i]=t[1][i];
      vis[t[1][i]]=1;
      dfs(i+1,1);
      vis[t[1][i]]=0;
    }
    b[i]=0;
  }
}
int main(){
  // freopen("in","r",stdin);
 	freopen("game.in","r",stdin);
 	freopen("game.out","w",stdout);
  int _T=T=read();
  while(T--){
    n=read();
    m=read();
    A=B=C=D=1;
    memset(vis,0,sizeof vis);
    for(int i=0;i<n;++i){
      s[2][i]=read();
      C&=(s[2][i]==1);
      for(int j=0;j<s[2][i];++j)
        s[j][i]=read();
    }
    for(int i=0;i<n;++i){
      t[2][i]=read();
      for(int j=0;j<t[2][i];++j){
        t[j][i]=read();
        A&=(t[j][i]!=s[0][i]&&(s[2][i]==1||t[j][i]!=s[1][i]));
      }
      if(t[2][i]==1)B=0;
      else{
        if(i<n-1&&t[0][i]>t[1][i]||i==n-1&&t[0][i]<t[1][i]){
          int tmp=t[0][i];
          t[0][i]=t[1][i];
          t[1][i]=tmp;
        }
        B&=(i<n-1&&t[0][i]==i+1&&t[1][i]==i+2||i==n-1&&t[0][i]==n&&t[1][i]==1);
      }
    }
#ifdef K
    if(T==_T-K){
      printf("%d %d\n",n,m);
      for(int i=0;i<n;++i){
        printf("%d ",s[2][i]);
        if(s[2][i]==1)
          printf("%d",s[0][i]);
        else
          printf("%d %d",min(s[0][i],s[1][i]),max(s[0][i],s[1][i]));
        puts("");
      }
      for(int i=0;i<n;++i){
        printf("%d ",t[2][i]);
        if(t[2][i]==1)
          printf("%d",t[0][i]);
        else
          printf("%d %d",min(t[0][i],t[1][i]),max(t[0][i],t[1][i]));
        puts("");
      }
    }
#endif
    if(n<=10&&m<=10){
      ans_X=0;
      dfs(0,0);
      printf("%d\n",ans_X==0x7fffffff?-1:ans_X);
    }else if(A){
      int cnt=0;
      bool f=1;
      for(int i=0;i<n;++i){
        for(int j=0;j<t[2][i];++j){
          cnt+=!vis[t[j][i]];
          ++vis[t[j][i]];
        }
      }
      // memset(vis1,0,sizeof vis1);
      for(int i=0;i<n;++i){
        if(t[2][i]==2&&vis[t[0][i]]==1&&vis[t[1][i]]==1)
          cnt-=1;
      }
      memset(vis,0,sizeof vis);
      for(int i=0;i<n;++i){
        if(t[2][i]==1){
          if(vis[t[0][i]]){
            f=0;
            break;
          }
          vis[t[0][i]]=1;
        }
      }
      if(f&&cnt>=n)puts("0");
      else puts("-1");
    }else if(B){
      int X1=0,X2=0,X3=0,X4=0;
      for(int i=0;i<n;++i)
        X1+=(s[0][i]==t[0][i]&&(a[i]=s[0][i],1)||s[1][i]==t[0][i]&&(a[i]=s[1][i],1));
      for(int i=0;i<n;++i)
        X2+=(a[i]==t[1][i]);
      for(int i=0;i<n;++i)
        X3+=(s[0][i]==t[1][i]&&(a[i]=s[0][i],1)||s[1][i]==t[1][i]&&(a[i]=s[1][i],1));
      for(int i=0;i<n;++i)
        X4+=(a[i]==t[0][i]);
      printf("%d\n",max(min(X1,X2),min(X3,X4)));
    }else if(C){
      int X;
      for(int i=0;i<n;++i)
        X+=(s[0][i]==t[0][i]&&(t[2][i]==1||s[0][i]==t[1][i]));
      printf("%d\n",X);
    }
  }
}