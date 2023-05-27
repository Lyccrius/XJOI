#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double x[1010],y[1010];
double f[1010][1010];
int u[1010];
int n;
int ans1[1010];
int now1[1010];
double b=0;
double mi=10000000000000000;
int cnt;
void dfs(int x,int d)
{
    u[x]=1;
    now1[d]=x;
    b+=f[now1[d]][now1[d-1]];
    if(b>=mi)
    {
        u[x]=0;
        b-=f[now1[d]][now1[d-1]];
        now1[d]=0;
        return;
    }
    if(d==n)
    {
        if(mi>b)
        {
            for(int i=1;i<=n;i++)
            {
                ans1[i]=now1[i];
            }
            mi=b;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(u[i]==0) dfs(i,d+1);
    }
    u[x]=0;
    b-=f[now1[d]][now1[d-1]];
    now1[d]=0;
    return;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    double p=-100000000;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf %lf",&x[i],&y[i]);
        p=max(p,y[i]);
    }
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(y[i]==p)
        {
            k=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    if(n<=12)
    {
        dfs(k,1);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans1[i]);
        }
        printf("\n");
        return 0;
    }
    u[k]=1;
    printf("%d ",k);
    for(int i=2;i<=n;i++)
    {
        double r=1e9;
        int w=0;
        int j=k+1;
        if(j>n) j-=n;
        if(u[j]==0)
        {
            if(r>f[i][j]) r=f[i][j],w=j;
        }
        j=k-1;
        if(j<1) j+=n;
        if(u[j]==0)
        {
            if(r>f[i][j]) r=f[i][j],w=j;
        }
        k=w;
        u[w]=1;
        printf("%d ",w);
    }
    printf("\n");
    return 0;
}