#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int p=998244353;
int n,m,k;
int u[220000],v[220000];
int s[220000],b[110000];
queue <int> q;
int ans=0;
void dfs(int i){
    if(i>m){
        while(q.size()>0){
            q.pop();
        }
        memset(b,0,sizeof(int)*110000);
        int bmax=0,bmin=10000000,bt=0,lt=0;
        for(int j=1;j<=m;j++){
            if(s[j]==1){
                if(b[u[j]]==0){
                    lt++;
                    b[u[j]]=1;
                }
                if(b[v[j]]==0){
                    lt++;
                    b[v[j]]=1;
                }
            }
        }
        memset(b,0,sizeof(int)*110000);
        for(int j=1;j<=n;j++){
            if(b[j]==0){
                while(q.size()>0){
                    q.pop();
                }
                q.push(j);
                b[j]=-1;
                int bans=0;
                while(q.size()>0){
                    int temp=q.front();
                    for(int ek=1;ek<=m;ek++){
                        if(s[ek]==0){
                            if(u[ek]==temp){
                               if(b[v[ek]]==0){
                                    b[v[ek]]=-1;
                                    q.push(v[ek]);
                                    bans++;
                                }
                            }
                            else if(v[ek]==temp){
                                if(b[u[ek]]==0){
                                    b[u[ek]]=-1;
                                    q.push(u[ek]);
                                    bans++;
                                }
                            }
                        }
                    }
                    q.pop();
                }
                if(bans>bmax){
                    bmax=bans;
                }
                if(bans<bmin){
                    bmin=bans;
                }
                b[j]=bans;
                bt++;
            }
        }
        if(bmax-bmin<=k&&bmax-bmin>=0&&bt>=2&&lt==bt){
            ans++;
        }
        return;
    }
    s[i]=1;
    dfs(i+1);
    s[i]=0;
    dfs(i+1);
    return;
}
int main(){
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}