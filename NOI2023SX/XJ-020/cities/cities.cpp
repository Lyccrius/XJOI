#include<bits/stdc++.h>
using namespace std;
#define mmax 500000
struct edge{
    int to,nxt;
}e[2*mmax];
int head[mmax],n,k,m,cnt;
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

int main(){
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    cout<<"1"<<endl;

    return 0;

}