#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int sid,n,m,k;
struct worker{
    int x;
    int v;
}w[N];
vector<int> nw[N];
vector<int> G[N];
void build(int x,int y){
    G[x].push_back(y);
    G[y].push_back(x);
}
int minn=N,sum=0;
bool dfs1(int x,int fa,int num){
    bool flag=false;
    for(int i=0;i<G[x].size();i++){
        int y=G[x][i];
        if(y!=fa){
            for(int j=0;j<nw[y].size();j++){
                if(w[nw[y][j]].v<minn){
                    minn=w[nw[y][j]].v;
                }
            }
            if(nw[y].size()==0){
                return true;
            }
            else{
                flag=dfs1(y,x,num);
            }
        }
    }
    return flag;

}
void dfs(int x,int fa){
    if(nw[x].size()>1){
        int maxn=0,maxnum=0;
        for(int i=0;i<nw[x].size();i++){
            if(w[nw[x][i]].v>maxn){
                maxn=w[nw[x][i]].v;
                if(maxnum){
                    if(dfs1(x,fa,maxnum)==false){
                        sum-=min(minn,w[maxnum].v);
                        minn=N;
                    }
                }
                maxnum=nw[x][i];
            }
            else{
                if(dfs1(x,fa,maxnum)==false){
                    sum-=min(minn,w[nw[x][i]].v);
                    minn=N;
                }
            }
        }
    }
    for(int i=0;i<G[x].size();i++){
        if(G[x][i]!=fa)
            dfs(G[x][i],x);
    }
    return;
}
int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    cin>>sid;
    cin>>n>>k>>m;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        build(i,p);
    }
    for(int i=1;i<=k;i++){
        cin>>w[i].x>>w[i].v;
        nw[w[i].x].push_back(i);
        sum+=w[i].v;
    }
    int sum1=sum;
    dfs(1,0);
    cout<<sum<<" ";
    for(int i=1;i<=m;i++){
        int tmp,x,v;
        cin>>tmp;
        sum=sum1;
        if(tmp==1){
            cin>>x>>v;
            w[k+1].x=x;
            w[k+1].v=v;
            nw[w[i].x].push_back(k+1);
            sum+=w[k+1].v;
            k+=1;
            dfs(1,0);
            cout<<sum<<" ";
        }
    }
    return 0;
}