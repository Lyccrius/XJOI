#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200010;
int n,m,k;
int a[maxn];
int l[maxn],r[maxn];
int c[maxn];
int ans[maxn],cnt;
int main(void){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>k;
    int xi=0,yi=0;
    for(int i=1;i<=m;i++){
        cin>>xi>>yi;
        c[xi]++,c[yi+1]--;
        l[xi]=1,r[yi]=1;
    }
    for(int i=1;i<=n;i++){
        c[i]+=c[i-1];
    }
    int tot=k-1;
    while(tot>=1){
        if(c[tot]==0) break;
        if(l[tot]==1) ans[++cnt]=tot;
        tot--;
    }
    for(int i=cnt;i>=1;i--){
        cout<<ans[i]<<" ";
    }
    tot=k+1,cnt=0;
    while(tot<=n){
        if(c[tot]==0) break;
        if(r[tot]==1) ans[++cnt]=tot;
        tot++;
    }
    for(int i=1;i<=cnt;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}