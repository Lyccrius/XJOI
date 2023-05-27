#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define se second
#define fi first
using namespace std;
const int N=2e5+10;
int n,m,s;
int l[N],r[N],fa[N];
bool ans[N];
vector<pair<int,int> >v[N];
int find(int x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>s;
    rep(i,1,m)scanf("%d%d",&l[i],&r[i]);
    l[++m]=s,r[m]=s;
    rep(i,1,m)v[l[i]].emplace_back(r[i],i),fa[i]=i;
    int mx=0,pos=0;
    rep(i,1,n){
        for(auto x:v[i]){
            if(mx>=i)fa[x.se]=find(pos);
            if(x.fi>mx)mx=x.fi,pos=x.se;
        }
    }
    rep(i,1,m-1)if(find(i)==find(m)){
        if(l[i]<s)ans[l[i]]=1;
        if(r[i]>s)ans[r[i]]=1;
    }
    rep(i,1,n)if(ans[i])printf("%d ",i);
    return 0;
}
/*
flood#head0413
*/