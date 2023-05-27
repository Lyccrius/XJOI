#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
long long p[100010];
vector<int> f[100010];
struct node
{
    long long x,v;
}l[200010];
int q[100010];
long long w[100010];
long long b[100010];
long long s[100010];
int n,k,m;
int sid;
int y[100010],z=0;
void ans(int r)
{
    if(r==n+1) return;
    for(int i=0;i<f[r].size();i++)
    {
        b[i+1]=f[r][i];
    }
    sort(b+1,b+f[r].size()+1);
    for(int i=1;i<=n/2;i++)
    {
        int u=b[i];
        b[i]=b[n-i+1];
        b[n-i+1]=u;
    }
    for(int i=1;i<=n;i++)
    {
        s[i]=max(s[i],b[i+r-1]);
    }
    ans(r+1);
    if(r==1)
    {
        long long v=0;
        for(int i=1;i<=n;i++)
        {
            v+=s[i];
        }
        printf("%lld\n",v);
    }
    return;
}
void solveb()
{
    ans(1);
    for(int i=1;i<=m;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%lld %lld",&l[++k].x,&l[k].v);
            f[l[k].x].push_back(l[k].v);
        }
        else 
        {
            int b;
            scanf("%d",&b);
            for(int j=0;j<f[b].size();j++)
            {
                if(f[b][j]==l[b].v) {f[b][j]=0;break;}
            }
            l[b].v=0,l[b].x=0;
        }
        ans(1);
    }
    return;
}
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    scanf("%d",&sid);
    scanf("%d %d %d",&n,&k,&m);
    for(int i=2;i<=n;i++)
    {
        scanf("%lld",&p[i]);
        f[p[i]].push_back(i);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%lld %lld",&l[i].x,&l[i].v);
        w[l[i].x]++;
        f[l[i].x].push_back(l[i].v);
    }
    solveb();
    return 0;
}