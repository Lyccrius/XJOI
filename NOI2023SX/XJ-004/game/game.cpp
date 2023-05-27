#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int T,n,m;
const int N=150005;
vector<int>s[N],t[N];
bool vis[4000007];
bool flag=false;
int cnt=0;
void dfs(int now){
    if(now>=cnt){
        flag=true;
        return;
    }
    for(int i=1;i<t[now][1];i++){
        if(vis[t[now][i]]==0){
            vis[t[now][i]]=1;
            dfs(now+1);
            vis[t[now][i]]=0;
        }
    }
    return;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            int c;
            cin>>c;
            cnt++;
            s[cnt].push_back(c);
            for(int i=2;i<=c+1;i++){
                int a;
                cin>>a;
                s[cnt].push_back(a);
            }
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            int c;
            cin>>c;
            cnt++;
            t[cnt].push_back(c);
            for(int i=2;i<=c+1;i++){
                int a;
                cin>>a;
                t[cnt].push_back(a);
            }
            //cout<<t[cnt][1]<<endl;
        }
        dfs(1);
        if(flag==false)cout<<"-1"<<endl;
        else cout<<"0"<<endl;
    }
}
