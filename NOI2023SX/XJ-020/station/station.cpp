//code by YOO_koishi
//AFO
#include<bits/stdc++.h>
using namespace std;
int n,m,x,vis[200050],st,y,mmax=-1,mmin=2147483641,path[200050][2];
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>st;
    for(int i=1;i<=m;i++){
        cin>>path[i][0]>>path[i][1];
        //vis[path[i][0]]=vis[path[i][1]]=1;
    }
    for(int i=1;i<=m;i++){
        if(path[i][1]==st){
            vis[path[i][0]]=1;
            mmin=min(mmin,path[i][0]);
            }
        if(path[i][0]==st){
            mmax=max(mmax,path[i][1]);
            vis[path[i][1]]=1;}
    }
    for(int i=1;i<=m;i++){
        if(path[i][0]<=mmin&&path[i][1]>=mmin&&path[i][1]<st){
            vis[path[i][0]]=1;
        }
         if(path[i][1]>=mmax&&path[i][0]<=mmax&&path[i][0]>st){
            vis[path[i][1]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i])cout<<i<<" ";
       // cout<<i<<":"<<vis[i]<<" ";
    }
    return 0;
}