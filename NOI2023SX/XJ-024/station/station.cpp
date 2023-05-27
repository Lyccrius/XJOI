//100pts code by Curlin
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
bool st[N],vis[N];
int l[N],r[N];
int n,m,s;
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>s;
    int ll=s,rr=s;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        if(l[i]<ll&&r[i]>=ll) ll=l[i];
        if(r[i]>rr&&l[i]<=rr) rr=r[i];
    }
    sort(l+1,l+m+1);
    sort(r+1,r+m+1);
    for(int i=1;i<=m;i++){
        if(ll<=l[i]&&l[i]<s&&!vis[l[i]]){
            cout<<l[i]<<" ";
            vis[l[i]]=1;
        }
    }
    for(int i=1;i<=m;i++){
        if(rr>=r[i]&&r[i]>s&&!vis[r[i]]){
            cout<<r[i]<<" ";
            vis[r[i]]=1;
        }
    }
    return 0;
}