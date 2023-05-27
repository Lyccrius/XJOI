#include <stdio.h>
#include <vector>
using namespace std;
vector<int> q[100010];
int mod=998244353;
long long ans=1;
int n,m,k;
int h[100010],vis[100010];
int f[100010];
void bian(int r)
{
    h[r]=1;
    vis[r]=1;
    for(int i=0;i<q[r].size();i++)
    {
        if(!vis[q[r][i]]) bian(q[r][i]);
        h[i]+=h[q[r][i]];
    }
    return;
}
int main()
{
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        q[x].push_back(y);
        q[y].push_back(x);
    }
    if(k==0)
    {
        for(int i=1;i<=n-1;i++)
        {
            if(n%i==0) f[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            bian(i);
            for(int j=2;j<=n/2;j++)
            {
                if(f[j]==0) continue;
                int p=0;
                for(int k=1;k<=n;k++)
                {
                    if(h[k]%j==0) p++;
                }
                if(p!=n/j) f[j]=0;
            }
            for(int j=1;j<=n;j++)
            {
                h[j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans+=f[i];
        }
        printf("%lld\n",ans);
        return 0;
    }
}