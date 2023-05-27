#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int T;
int n,m,vis1[N];
vector<int> s[N];
vector<int> t[N];
vector<int> v[N];
map<int,pair<int,int>> M;
vector<int> vis[N];
bool find(int s){
    int a[N]={0},sum=0,ans=N;
    if(vis1[s]){
        sum++;
    }
    for(int i=0;i<vis[s].size();i++){
        int x=M[vis[s][i]].second;
        if(vis1[x]){
            x=0;
        }
        if(x==0){
            sum++;
            continue;
        }
        if(a[x]==1&&vis1[s]!=x){
            vis1[x]=s;
            ans=x;
            sum++;
            continue;
        }
        a[x]++;
    }
    if(vis1[s]==0&&sum==1){
        vis1[s]=ans;
    }
    if(sum>=2){
        return false;
    }
    return true;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m;
        if(n>m){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            v[i].resize(0);
            t[i].resize(0);
            s[i].resize(0);
        }
        for(int i=1;i<=m;i++){
            vis[i].resize(0);
            vis1[i]=0;
        }
        for(int i=1;i<=n;i++){
            int cnt,x;
            cin>>cnt;
            for (int p=v[i].size()-1;p<=m;p++){
                v[i].push_back(0);
            }
            for(int j=1;j<=cnt;j++){
                cin>>x;
                s[i].push_back(x);
                v[i][x]=1;
            }
        }
        int sum1=0,sum2=0,f=0;
        for(int i=1,num=1;i<=n;i++){
            int cnt,x,flag=0;
            cin>>cnt;
            for(int j=1;j<=cnt;j++){
                cin>>x;
                t[i].push_back(x);
                if(v[i][x]==0){
                    flag++;
                }
            }
             if(cnt==1){
                M[num]=make_pair(x,0);
                vis[x].push_back(num);
                num++;
            }
            if(cnt==2){
                int z=t[i][0];
                M[num]=make_pair(z,x);
                vis[z].push_back(num);
                num++;
                M[num]=make_pair(x,z);
                vis[x].push_back(num);
                num++;
            }
            if(flag<cnt){
                sum2++;
            }
        }
        for(int i=1;i<=m;i++){
            if(find(i)==false){
                f=1;
                break;
            }
        }
        if(f==1){
            cout<<-1<<endl;
            continue;
        }
        if(sum2==0&&f==0){
            cout<<0<<endl;
            continue;
        }
    }
    return 0;
}