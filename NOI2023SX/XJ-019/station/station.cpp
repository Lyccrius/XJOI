#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,x,h[201000],vis[201000],cnt,zm,rm;
struct node
{
    int d,nxt;
}e[201000];
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d %d %d",&n,&m,&x);
    zm=rm=x;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        l=min(l,r);
        r=max(l,r);
        if(l<x&&r>x)
        {
            vis[l]=1;
            vis[r]=1;
            zm=min(zm,l);
            rm=max(rm,r);
        }
        else if(l>=x)
        {
            e[++cnt].d=r;
            e[cnt].nxt=h[l];
            h[l]=cnt;
        }
        else
        {
            e[++cnt].d=l;
            e[cnt].nxt=h[r];
            h[r]=cnt;
        }
    }
    for(int i=x;i;i--)
    {
        if(i>=zm)
        {
            for(int j=h[i];j;j=e[j].nxt)
            {
                int v=e[j].d;
                vis[v]=1;
                zm=min(zm,v);
            }
        }
        else break;
    }
    for(int i=x;i<=n;i++)
    {
        if(i<=rm)
        {
            for(int j=h[i];j;j=e[j].nxt)
            {
                int v=e[j].d;
                vis[v]=1;
                rm=max(rm,v);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(vis[i]&&i!=x)printf("%d ",i);
    return 0;
}