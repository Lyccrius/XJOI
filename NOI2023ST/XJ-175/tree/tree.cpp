#include <bits/stdc++.h>
using namespace std;
struct light
{
    int id;
    double x,y;
    friend bool operator<(light a,light b)
    {
        return a.y>b.y;
    }
}l[1010];
int n,vis[1010],q1[1010],q2[1010];
double ans=1000000000;
double get_dis(int u,int v)
{
    return sqrt((l[u].x-l[v].x)*(l[u].x-l[v].x)+(l[u].y-l[v].y)*(l[u].y-l[v].y));
}
void dfs(int now,double dis,int id)
{
    if(now==n)
    {
        if(dis<ans)
        {
            ans=dis;
            for(int i=1;i<=n;i++)
                q2[i]=q1[i];
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        vis[i]=1;
        q1[now+1]=l[i].id;
        dfs(now+1,dis+get_dis(id,i),i);
        vis[i]=0;
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&l[i].x,&l[i].y);
        l[i].id=i;
    }
    sort(l+1,l+1+n);
    if(n<=18)
    {
        vis[1]=1;
        q1[1]=l[1].id;
        dfs(1,0,1);
    }
    else
    {
        int i=1;
        for(i=1;i<=n;i++)
            if(l[i].id!=i)break;
        if(i-1==n)
        {
            for(int i=1;i<=n;i++)
                printf("%d ",i);
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",q2[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}