#include<iostream>
#include<vector>
#include<queue>
#define lc u<<1;
#define rc u<<1|1;
using namespace std;
int n,k,m;
const int N=100005;
int head[N],nxt[N],ver[N];
int vis[N];
int a[N];
int sid;
int ans=0;
/*vector<int>edge[N];
int sid;
int cnt=0;
int ans=0;
void add(int x,int y){
    ver[++cnt]=y;
    nxt[cnt]=head[x];
    head[x]=cnt;    
}
void dfs(int x){

}*/
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
    cin>>sid;
    cin>>n>>k>>m;
    if(sid==9){
        for(int i=2;i<=n;i++){
			int f;
            cin>>f;
        }
        for(int i=1;i<=k;i++){
            int x,v;
            cin>>x>>v;
            if(a[x]==0)a[x]=v,ans+=v;
            else {
                if(a[x]<v)swap(a[x],v),ans+=a[x]-v;
				for(int j=x+1;j<=n;j++){
					if(a[j]==0){
						a[j]=v;
						ans+=v;
						cout<<a[j];
						break;
					}
					else{
						if(a[j]<v)swap(a[j],v),ans+=a[j]-v;
					}
				}
            }
        }
        cout<<ans<<" ";
        for(int i=1;i<=m;i++){
            int id,x,v;
            cin>>id;
            if(id==1){
                cin>>x>>v;
                if(a[x]==0)a[x]=v,ans+=v;
				else {
					if(a[x]<v)swap(a[x],v),ans+=a[x]-v;
					for(int j=x+1;j<=n;j++){
						if(a[j]==0){
							a[j]=v;
							ans+=v;
							break;
						}
						else{
							if(a[j]<v)swap(a[j],v),ans+=a[j]-v;
						}
					}	
				}
            }
            cout<<ans<<" ";
        }
        return 0;
    }
    /*for(int i=2;i<=n;i++){
        int f;
        cin>>f;
        add(i,f);
        add(f,i);
    }
    for(int i=1;i<=k;i++){
        int x,v;
        cin>>x>>v;
        edge[x].push_back(v);
    }
    dfs(1);
    cout<<ans<<" ";
    if(sid==8||sid==10){
        for(int i=1;i<=m;i++){
            int id,x,y;
            cin>>id;
            if(id==1){
                cin>>x>>y;
                edge[x].push_back(y);
                dfs(1);
                cout<<ans;
            }    
        }
    }*/
}
