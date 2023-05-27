#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,x;
int vis[N],vis1[N],ans[N],cnt;
vector<int> s[N];
struct road{
    int l,r;
}ro[N];
bool cmp(road x,road y){
    if(x.l!=y.l)
        return x.l<y.l;
    else
        return x.r<y.r;
}
void findle(int x){
    int flag=0;
    for(int i=0;i<s[x].size();i++){
        int l=ro[s[x][i]].l;
        if(x==l){
            continue;
        }
        if(!vis[l]&&l!=x){
            ans[cnt++]=l;
            vis[l]=1;
            for(int j=x-1;j>=l;j--){
                if(s[j].size()>1&&!vis1[j]){
                    flag=1;
                    vis1[j]=1;
                    findle(j);
                }
            }
        }
    }
    if(!flag){
        return;
    }
}
void findri(int x){
    int flag=0;
    for(int i=0;i<s[x].size();i++){
        int r=ro[s[x][i]].r;
        if(x==r){
            continue;
        }
        if(!vis[r]&&r!=x){
            ans[cnt++]=r;
            vis[r]=1;
            for(int j=x+1;j<=r;j++){
                if(s[j].size()>1&&!vis1[j]){
                    flag=1;
                    vis1[j]=1;
                    findri(j);
                }
            }
        }
    }
    if(!flag){
        return;
    }
}
int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int l1,r1;
        cin>>l1>>r1;
        ro[i].l=l1;
        ro[i].r=r1;
    }
    sort(ro,ro+m,cmp);
    for(int i=0;i<m;i++){
        for(int j=ro[i].l;j<=ro[i].r;j++){
            s[j].push_back(i);
        }
    }
    if(x==1){
        findri(x);
    }
    else{
        findle(x);
        findri(x);
    }
    sort(ans,ans+cnt);
    for(int i=0;i<cnt;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}