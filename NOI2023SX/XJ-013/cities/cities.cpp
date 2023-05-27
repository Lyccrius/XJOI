#include <bits/stdc++.h>
#define N 6010
using namespace std;
int n,m,k;
int head[N],cnt,num[N];
int check[N];
bool  fl[N];
struct qwq{
    int to,nxt;
}q[N];
void addedge(int x,int y)
{
    q[++cnt].to=y;
    q[cnt].nxt=head[x];
    head[x]=cnt;
}
void dfs(int s)
{
    if(fl[s]!=0) return ;
    fl[s]==1;

    int flag=0;
    for(int i=head[s];i!=0;i=q[i].nxt)
    {
        if(fl[q[i].to]!=0) continue;
        flag=1;

    cout<<s<<endl;
        dfs(q[i].to);
        num[s]+=num[q[i].to];
    }
        if(flag==0) 
    {
        num[s]=1;
        return ;
    }
    return ;
}
int main()
{
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        addedge(x,y);
        addedge(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        check[num[i]]++;
    }
    int ans=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0) ans++;
    }
    cout<<ans;
    return 0;

}