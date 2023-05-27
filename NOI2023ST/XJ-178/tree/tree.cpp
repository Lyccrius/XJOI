#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int i,j,n,tmp,start,tmp1,tmp2[5],ans[5];
double x[5],y[5],minn=2147483647.0,maxx,maxy,dist[5][5];
bool a[5];
void dfs(int cha,int from,double tot)
{
    int xx;
    if(cha==n)
    {
        if(minn>tot)
        {
            minn=tot;
            memcpy(ans,tmp2,sizeof(tmp2));
        }
        return ;
    }
    for(xx=1;xx<=n;xx++)
    {
        if(a[xx]==1)continue;
        a[xx]=1;
        tmp2[cha+1]=xx;
        dfs(cha+1,xx,tot+dist[from][xx]);
        a[xx]=0;
        tmp2[cha+1]=0;
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        maxx=max(maxx,x[i]);
        if(y[i]>maxy)
        {
            maxy=max(maxy,y[i]);
            start=i;
            a[i]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(j==i) continue;
            tmp=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            dist[i][j]=dist[j][i]=sqrt(tmp);
        }
    }
    tmp2[1]=start;
    dfs(1,start,0.0);
    for(i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}