#include<stdio.h>
#include<math.h>
#include<map>
int n,cnt,path[10001];;
long double f[10001][10001];
long double x[10001],y[10001];
struct pos
{
    long double x,y;
};
struct mix
{
    pos a,b;
    bool operator < (const mix a)const
    {
        return true;
    }
};
std::map<mix,long double>distenses;
long double distense(pos a,pos b)
{
    mix tmp1;
    tmp1.a.x=a.x;
    tmp1.b.y=a.y;
    tmp1.b.x=b.x;
    tmp1.b.y=b.y;
    mix tmp2;
    tmp2.a.x=b.x;
    tmp2.b.y=b.y;
    tmp2.b.x=a.x;
    tmp2.b.y=a.y;
    if(distenses[tmp1]!=0)return distenses[tmp1];
    if(distenses[tmp2]!=0)return distenses[tmp2];
    return distenses[tmp1]=distenses[tmp2]=std::sqrt(std::pow(a.x-b.x,2)+std::pow(a.y-b.y,2));
}
bool vis[10001];
pos position(int no)
{
    pos tmp;
    tmp.x=x[no];
    tmp.y=y[no];
    return tmp;
}
long double dfs(int start,int end)
{
    if(f[start][end]!=0)return f[start][end];
    long double ans=0x7f7f7f7f;
    if(start==end)return 0;
    for(int i=1;i<=n;i++)
    {
        if(i==start)continue;
        if(vis[i]==true)continue;
        else
        {
            vis[i]=true;
            long double tmp = distense(position(start),position(i))+dfs(i,end);
            ans=tmp<ans?tmp:ans;
            vis[i]=false;
        }
    }
    return f[start][end]=ans;
}
void pt(int start,int end)
{
    printf("%d",start);
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(i==start)continue;
        if(vis[i]==true)continue;
        else
        {
            vis[i]=true;

            //printf("%d ",start);
            dfs(i,end);
            
            vis[i]=false;
        }
    }
    return;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    int start=1;
    for (int i=1;i<=n;i++)
    {
        scanf("%Lf %Lf",&x[i],&y[i]);
        start=y[start]<y[i]?i:start;
    }
    int Min=0x7f7f7f7f;
    int end;
    for(int j=1;j<=n;j++)
    {
        if(j==start)continue;
        long double tmp=dfs(start,j);
        if(tmp<Min)
        {
            Min=tmp;
            end=j;
        }
    }
    pt(start,end);
    fclose(stdin);
    fclose(stdout);
    return 0;
}