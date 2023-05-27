//code by MisakaE
#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,id;
    friend bool operator < (const node a,const node b){
        return a.v<b.v;
    }
};
struct nods{
    int p,v;
    friend bool operator < (const nods a,const nods b){
        return a.v>b.v;
    }
};
struct peo{
    priority_queue<node> rpk;
    priority_queue<nods> lk;
    vector<int> son;
};
struct trees{
    peo pe[2400];
    int f[2400],mx[2400];
}stk[2];
priority_queue<nods> rj;
//vector<node> wai[2400];
int spt,n,k,m;
void dfs(int fa,int nw){
    for(int i=0;i<stk[0].pe[nw].son.size();++i){
        int y=stk[0].pe[nw].son[i];
        dfs(nw,y);
        rj=stk[0].pe[y].lk;
        while(!stk[0].pe[y].lk.empty()){
            nods u=rj.top();
            rj.pop();
            if(u.v!=stk[0].mx[u.p])continue;
            stk[0].pe[nw].lk.push(u);
        }
    }
    int sk;
    if(stk[0].pe[nw].rpk.empty())sk=0;
    else sk=stk[0].pe[nw].rpk.top().v;
    stk[0].pe[nw].lk.push((nods){nw,sk});
    stk[0].mx[nw]=sk;
    int nx=0;
    while(!stk[0].pe[nw].rpk.empty()&&nx!=nw){
        node h=stk[0].pe[nw].rpk.top();
        stk[0].pe[nw].rpk.pop();
        if(stk[0].f[h.id]!=nw)continue;
        if(stk[0].pe[nw].rpk.empty())sk=0;
        else sk=stk[0].pe[nw].rpk.top().v;
        stk[0].pe[nw].lk.push((nods){nw,sk});
        stk[0].mx[nw]=sk;

        while (!stk[0].pe[nw].lk.empty())
        {
            nods g=stk[0].pe[nw].lk.top();
            if(g.v!=stk[0].mx[g.p])continue;
            nx=g.p;
            stk[0].f[h.id]=g.p;
            stk[0].pe[g.p].rpk.push(h);
            
            break;
        }
        
        

    }

}
int main()
{
    scanf("%d%d%d%d",&spt,&n,&k,&m);
    for(int i=2;i<=n;++i){
        int l;
        scanf("%d",&l);
        stk[0].pe[l].son.push_back(i);
    }
    for(int i=1;i<=k;++i){
        int l,l2;
        scanf("%d%d",&l,&l2);
        stk[0].pe[l].rpk.push((node){l2,i});
        stk[0].f[i]=l;
    }

    


}