#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define lodou long double 
const int maxn=262160;
int n,k;
lodou f[25][maxn];
struct node{
    int u,v;
}z[25][maxn];
int ans[25],tot;
lodou xx[25],yy[25];
lodou val(int g,int h){
    return sqrt((xx[g]-xx[h])*(xx[g]-xx[h])+(yy[g]-yy[h])*(yy[g]-yy[h]));
}
int main(void){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    lodou mxy=0;
    for(int i=1;i<=n;i++){
        cin>>xx[i]>>yy[i];
        if(yy[i]>mxy) mxy=yy[i],k=i;
    }
    for(int i=0;i<25;i++){
        for(int j=0;j<maxn;j++){
            f[i][j]=100000005.0;
        }
    }
    f[k][1<<(k-1)]=0;
    for(int i=1;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            if((i&(1<<(j-1)))==0) continue;
            int x=i,y=1;
            while(x>0){
                if(y==j){
                    x/=2; y++;
                    continue;                    
                }
                if((x&1)==0){
                    x/=2; y++;
                    continue;
                }
                if(f[j][i]>(f[y][i^(1<<(j-1))]+val(j,y)))
                    f[j][i]=f[y][i^(1<<(j-1))]+val(j,y),
                    z[j][i].u=y, z[j][i].v=(i^(1<<(j-1)));
                x/=2; y++;
            }
        }
    }
    lodou mnk=100000005.0;
    int mi=0;
    for(int i=1;i<=n;i++){
        if(mnk>f[i][(1<<n)-1])
            mnk=f[i][(1<<n)-1],
            mi=i;
    }
    int mz=(1<<n)-1,l=0;
    while(mi){
        ans[++tot]=mi;
        l=mi;
        mi=z[mi][mz].u;
        mz=z[l][mz].v;
    }
    for(int i=tot;i>=1;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}