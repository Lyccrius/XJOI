#include <bits/stdc++.h>
int u,w,K,U,M;
using namespace std;
struct R
{
    int used,f,h;
};

int k=0,ans1[100005],ans[100005],ans2[100005],bns[10000],bns1[10000],bns2[10000];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int T;
    cin>>T;
    while(T>0){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+2],b[n+2],A[n+2],B[n+2];
    int result[m+2],result1[m+2],result2[m+2];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(result,0,sizeof(m));
    for(int i=1;i<=n;++i){
       int key;
       scanf("%d",&key);
       if(key==2){
           k++;
           ans1[k]=i;
           scanf("%d%d",&a[i],&A[i]);
           }
       else{scanf("%d",&a[i]);}
    }
    for(int i=1;i<=n;++i){
       int key;
       scanf("%d",&key);
     if(key==2){
           K++;
           bns1[K]=i;
           scanf("%d%d",&b[i],&B[i]);
           }
       else{scanf("%d",&b[i]);}  
    }
    int r,c[k+2];
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;++i){
        ans[i]=a[i];
    }
        
    while(c[k+1]==0){
    r=1;
    c[r]++;
    ans[ans1[r]]=A[ans1[r]];
    while(c[r]>1){
        c[r]=0;
        ans[ans1[r]]=a[ans1[r]];
        r++;
        c[r]++;
        ans[ans1[r]]=A[ans1[r]];
    }
    while(c[K+1]==0){
    r=1;
    c[r]++;
    ans[ans1[r]]=A[ans1[r]];
    while(c[r]>1){
        c[r]=0;
        bns[bns1[r]]=b[bns1[r]];
        r++;
        c[r]++;
        bns[bns1[r]]=B[bns1[r]];
    }
    for(int i=1;i<=n;++i){
        if(bns[i]==ans[i])u++;
    }
    U=min(U,u);
    u=0;
    }
    M++;
    result[M]=U;
    for(int i=1;i<=n;++i){
        bns[i]=b[i];
    }}
sort(result+1,result+M+1);
cout<<result[M]<<endl;

    T--;

    }
}