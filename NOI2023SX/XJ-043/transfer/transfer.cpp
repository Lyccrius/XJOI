#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=5005;
int s,n,k,m;
vector<int> a[maxn];
int p[maxn];
struct node{
    int id,val;
}t[maxn][maxn];
int e[maxn];
int z[maxn][maxn];
int per[maxn],cnt[maxn];
bool cmp(int gg,int hh){
    return gg>hh;
}
void work(int x){
    cnt[x]=1;
    int f=0;
    e[x]=per[x];
    for(int i=1;i<=per[x];i++){
        z[x][i]=t[x][i].val;
    }
    for(int i=0;i<a[x].size();i++){
        int vv=a[x][i];
        work(vv);
        cnt[x]+=cnt[vv];
        f=1;
        while((f<=cnt[vv])&&(f<=e[vv])){
            z[x][++e[x]]=z[vv][f];
            f++;
        }
    }
    sort(z[x]+1,z[x]+1+e[x],cmp);
    if(x!=1) return;
    long long ans=0;
    for(int i=1;i<=min(e[x],cnt[x]);i++){
        ans+=(long long)(z[x][i]);
    }
    cout<<ans<<" ";
}
int main(void){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    cin>>s;
    cin>>n>>k>>m;
    for(int i=2;i<=n;i++){
        cin>>p[i];
        a[p[i]].push_back(i);
    }
    int op=0,g=0,h=0;
    for(int i=1;i<=k;i++){
        cin>>g>>h;
        t[g][++per[g]].id=i;
        t[g][++per[g]].val=h;
    }
    work(1);
    for(int i=1;i<=m;i++){
        cin>>op>>g;
        if(op==1){
            cin>>h;
            /*for(int j=per[g];j>=0;j--){
                  if(t[g][j].val<=h){
                      t[g][j+1]=t[g][j];
                  } else{
                      t[g][j+1].id=++k;
                      t[g][j+1].val=h;
                      break;
                  }
            }*/
            t[g][++per[g]].id=++k;
            t[g][per[g]].val=h;
            work(1);
        } else{
            int flg=0;
            for(int j=1;j<=per[g];j++){
                if(flg==1) t[g][j-1]=t[g][j];
                else if(g==t[g][j].id) flg=1;
            }
            per[g]--;
            work(1);
        }
    }
    return 0;
}