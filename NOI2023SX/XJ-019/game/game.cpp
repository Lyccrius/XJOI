#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[1100][20],b[1100][20],T,n,m,c[20][5],d[20][5],k[20],q[20],ji[20],cnt,cnt1,ans;
void dfs1(int x)
{
    if(x>n)
    {
        cnt++;
        for(int i=1;i<=n;i++)
          a[cnt][i]=ji[i];
    }
    for(int i=1;i<=k[x];i++)
    {
        ji[x]=c[x][i];
        dfs1(x+1);
    }
}
void dfs2(int x)
{
    if(x>n)
    {
       int f=1;
       for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        if(ji[i]==ji[j])
        {
            f=0;
            break;
        }
       if(f)
       {
           cnt1++;
           for(int i=1;i<=n;i++)
           b[cnt1][i]=ji[i];
       }
    }
    for(int i=1;i<=q[x];i++)
    {
        ji[x]=d[x][i];
        dfs2(x+1);
    }
}
int main()
{
    freopen("game2.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            int u;
            scanf("%d",&u);
            k[i]=u;
            for(int j=1;j<=u;j++)
                scanf("%d",&c[i][j]);
        }
        for(int i=1;i<=n;i++)
        {
            int u;
            scanf("%d",&u);
            q[i]=u;
            for(int j=1;j<=u;j++)
            scanf("%d",&d[i][j]);
        }
        if(T>20)printf("0\n");
        dfs1(1);
        dfs2(1);
        int da=20;
        ans=0;
        if(cnt1==0)
        {
            printf("-1\n");
            cnt=0;
            continue;
        }
        for(int i=1;i<=cnt;i++)
        {
            for(int j=1;j<=cnt1;j++)
           {
              int o=0;
              for(int z=1;z<=n;z++)
                  if(a[i][z]==b[j][z])o++;
              da=min(o,da);
           }
           ans=max(ans,da); 
           da=20;
        }
        printf("%d\n",ans);
        cnt=cnt1=0;
    }
    return 0;
}