#include <cstdio>
#include <queue>
using namespace std;
struct xd{
    int l,r;
};
struct xd_sort{
    bool operator()(xd a,xd b){
        if(a.r>b.r) return 1;
        else if(a.r==b.r&&a.l>b.l) return 1;
        return 0;
    }
};
int n,m,x;
xd d[220000],td;
priority_queue <xd,vector<xd>,xd_sort> q;
int zl=0,zr=0;
short ans[220000];
int hou[220000];
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d%d%d",&n,&m,&x);
    zl=n+1;zr=0;
    for(int i=1;i<=m;i++){
        td.l=0;td.r=0;
        scanf("%d%d",&td.l,&td.r);
        q.push(td);
    }
    for(int i=1;i<=m;i++){
        d[i]=q.top();
        q.pop();
    }
    hou[m]=d[m].l;
    for(int i=m-1;i>=1;i--){
        hou[i]=hou[i+1];
        if(d[i].l<hou[i]){
            hou[i]=d[i].l;
        }
    }
    for(int i=x,lj=1;i<=n;i++){
        for(int j=lj;j<=m;j++){
            if(d[j].l<=i&&i<=d[j].r&&zr<d[j].r){
                zr=d[j].r;
                lj=j;
            }
            if(i<hou[j]){
                break;
            }
        }
        if(zr<=i){
            break;
        }
        i=zr;
    }
    for(int i=1;i<=m;i++){
        if(d[i].l<=zr&&x<=d[i].r){
            ans[d[i].r]=1;
        }
    }
    for(int i=x,lj=m;i>=1;i--){
        for(int j=lj;j>=1;j--){
            if(d[j].l<=i&&i<=d[j].r&&zl>d[j].l){
                zl=d[j].l;
                lj=j;
            }
            if(i>d[j].r){
                break;
            }
        }
        if(zl>=i){
            break;
        }
        i=zl;
    }
    for(int i=1;i<=m;i++){
        if(zl<=d[i].r&&d[i].l<=x){
            ans[d[i].l]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==1&&i!=x){
            printf("%d ",i);
        }
    }
    return 0;
}