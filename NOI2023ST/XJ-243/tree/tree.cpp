#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
int n,s;
struct pos
{
    double x;
    double y;
}a[1010];
double maxn=-INF;
double dis(int m,int n){
    double cx=a[m].x-a[n].x;
    double cy=a[m].y-a[n].y;
    double sum=cy*cy+cx*cx;
    return sqrt(sum);
}
int vis[1010],ans=0;
void dfs(int s){
    vis[s]=1;
    ans++;
    cout<<s<<" ";
    double m=INF,nex;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            double d=dis(s,i);
            if(d<m){
                m=d;
                nex=i;
            }
        }
    }
    if(ans<n){
        dfs(nex);
    }
    else{
        return;
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        if(a[i].y>maxn){
            maxn=a[i].y;
            s=i;
        }
    }
    dfs(s);
    return 0;
}