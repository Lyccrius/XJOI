#include<stdio.h>
#include<math.h>
int n,da[1010],vis[1010],c[1010];
double x[1010],y[1010],ans=100000000.0;
double qiu(int xx,int yy)
{
    return sqrt((x[xx]-x[yy])*(x[xx]-x[yy])+(y[xx]-y[yy])*(y[xx]-y[yy]));
}
void dfs(int dep,int x,double k)
{
    if(k>=ans)return ;
    if(dep==n)
    {
        ans=k;
        for(int i=2;i<=n;i++)
        da[i]=c[i];
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            c[dep+1]=i;
            vis[i]=1;
            dfs(dep+1,i,k+qiu(i,x));
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    int s;
    double ma=-10000010;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf %lf",&x[i],&y[i]);
        if(y[i]>ma)
        {
            ma=y[i];
            s=i;
        }
    }
    da[1]=s;
    vis[s]=1;
    dfs(1,s,0);
    for(int i=1;i<=n;i++)
    printf("%d ",da[i]);
    return 0;
}