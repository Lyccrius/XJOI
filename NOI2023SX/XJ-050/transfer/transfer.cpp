#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct xd{
    int x,v,id;
};
struct big_sort{
    bool operator()(xd a,xd b){
        if(a.v<b.v) return 1;
        return 0;
    }
};
int sid;
int n,k,m;
int p[110000];
int x[110000],v[110000];
priority_queue <xd,vector<xd>,big_sort> q;
queue<int> dl[110000];
queue<xd> yg[110000];
long long ans=0;
short b[110000];
void dfs(int i){
    int yg_size=yg[i].size();
    for(int j=1;j<=yg_size;j++){
        xd temp=yg[i].front();
        yg[i].pop();
        yg[i].push(temp);
        q.push(temp);
    }
    while(q.size()>0){
        xd temp=q.top();
        q.pop();
        if(b[temp.id]==0){
            ans+=temp.v;
            break;
        }
    }
    int dl_size=dl[i].size();
    for(int j=1;j<=dl_size;j++){
        int temp=dl[i].front();
        dl[i].pop();
        dl[i].push(temp);
        dfs(temp);
    }
    for(int j=1;j<=yg_size;j++){
        xd temp=yg[i].front();
        yg[i].pop();
        yg[i].push(temp);
        b[temp.id]=1;
    }
    return;
}
void gf(){
    ans=0;
    while(q.size()>0){
        q.pop();
    }
    memset(b,0,sizeof(short)*110000);
    dfs(1);
    printf("%lld\n",ans);
    return;
}
int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    scanf("%d",&sid);
    scanf("%d%d%d",&n,&k,&m);
    for(int i=2;i<=n;i++){
        scanf("%d",&p[i]);
        dl[p[i]].push(i);
    }
    for(int i=1;i<=k;i++){
        scanf("%d%d",&x[i],&v[i]);
        yg[x[i]].push({x[i],v[i],i});
    }
    gf();
    for(int i=1;i<=m;i++){
        int op,xr,vr;
        scanf("%d%d",&op,&xr);
        if(op==1){
            scanf("%d",&vr);
            k++;
            yg[xr].push({xr,vr,k});
        }
        else{
            
        }
        gf();
    }
    return 0;
}
//g++ transfer.cpp -o transfer
//./transfer