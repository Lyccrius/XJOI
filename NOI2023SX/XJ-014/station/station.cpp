//code by MisakaE
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct sta{
    int l;
    bool ed;
}e[N];
bool t[N];
int n,m,x,lc=N,rc;
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;++i){
        int lt,rt;
        scanf("%d%d",&lt,&rt);
        if(lt<x&&rt>x){
            e[lt].ed=true;
            e[rt].ed=true;
            lc=min(lc,lt);
            rc=max(rc,rt);
        }
        else if(rt<=x){
            e[lt].ed=true;
            if(e[rt].l==0)e[rt].l=lt;
            else e[rt].l=min(e[rt].l,lt);
            if(rt==x)lc=min(lc,lt);
        }
        else if(lt>=x){
            e[rt].ed=true;
            e[lt].l=max(e[lt].l,rt);
            if(lt==x)rc=max(rc,rt);
        }
    }
    for(int i=x-1;i>=lc;--i){
        if(e[i].l!=0)lc=min(lc,e[i].l);
        t[i]=e[i].ed;
    }
    for(int i=x+1;i<=rc;++i){
        if(e[i].l!=0)rc=max(rc,e[i].l);
        t[i]=e[i].ed;
    }
    for(int i=1;i<=n;++i)if(t[i])printf("%d ",i);
    fclose(stdin);
    fclose(stdout);
    return 0;
}