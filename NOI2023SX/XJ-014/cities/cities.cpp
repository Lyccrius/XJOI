//code by MisakaE
#include<bits/stdc++.h>
using namespace std;
const int N = 1048576;
struct node{
    int a,b;
}e[35];
int n,m,k,tot;
int t[24],siz[24],fata;
bool vis[24];
int finds(int x){
    if(t[x]==x)return x;
    t[x]=finds(t[x]);
    return t[x];
}
bool check(int da){
    for(int i=1;i<=n;++i)t[i]=i,siz[i]=1,vis[i]=0;
    fata=n;
    for(int i=1;i<=m;++i){
        if((da&(1<<(i-1)))==0)continue;
        int fa=finds(e[i].a),fb=finds(e[i].b);
        if(fa==fb)continue;
        t[fa]=fb;
        fata--;
        siz[fb]+=siz[fa];
    }
    int kot=0;
    for(int i=1;i<=m;++i){
        if((da&(1<<(i-1)))==0){
            if(vis[e[i].a]==0)kot++;
            vis[e[i].a]=1;
            if(vis[e[i].b]==0)kot++;
            vis[e[i].b]=1;
        }
    }
    if(kot>fata)return 0;
    int ma=0,mi=100;
    for(int i=1;i<=n;++i){
        int h=siz[finds(i)];
        ma=max(ma,h);
        mi=min(mi,h);
    }
    if(ma-mi<=k&&ma!=n)return 1;
    return 0;
}
int main()
{
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int js=1;
    js<<=m;
    js-=1;
    for(int i=1;i<=m;++i){
        int sa,sb;
        scanf("%d%d",&sa,&sb);
        e[++tot]=(node){sa,sb};
    }
    int cnt=0;
    for(int i=0;i<=js;++i){
        if(check(i))++cnt;
    }
    printf("%d",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}