#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=200100;

int n,m,x;
vector<int> rr[N];
vector<int> ll[N];
int vis[N];
void rdfs(int a)
{
    
    if(rr[a].empty())
        return;
    for(int i=0;i<rr[a].size();i++)
    {
        if(vis[rr[a][i]]==0)
        {
            vis[rr[a][i]]=1;
            rdfs(rr[a][i]);
        }
    }
}
void ldfs(int a)
{
    if(ll[a].empty())
        return;
    for(int i=0;i<ll[a].size();i++)
    {
        if(vis[ll[a][i]]==0)
        {
            vis[ll[a][i]]=1;
            ldfs(ll[a][i]);
        }
    }
}
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        for(int i=l;i<r;i++)
            rr[i].push_back(r);
        for(int i=r;i>l;i--)
            ll[i].push_back(l);
    }
    vis[x]=1;
    rdfs(x);
    ldfs(x);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1&&i!=x)
        cout<<i<<" ";
    }
}