#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
const int N=1010;
using namespace std;
struct node{
    double x,y;
}p[N];
int n,k;
int ans[N],num=1,tnp,vis[N],rans[N];//ans1 num  ans2 lenth 
double sum,flagsum=100000000;
double len(int a,int b)
{
    return sqrt(pow(p[a].x-p[b].x,2)+pow(p[a].y-p[b].y,2));
}
void dfs(int x,int al)
{
    ans[al]=x;
   // cout<<al<<endl;
    if(al>=n)
    {   
       // cout<<sum<<" "<<flagsum<<endl;
        if(sum<flagsum)
        {
            flagsum=sum;
           // cout<<flagsum<<endl;
            for(int i=1;i<=n;i++)
                rans[i]=ans[i];
        }
         return;
    }
    for(int i=1;i<=n;i++)
    {
        
       if(vis[i]==0)
        {
            vis[i]=1;
            sum+=len(x,i);
            //cout<<i<<" "<<sum<<" "<<ans[al]<<endl;
            dfs(i,al+1);
            sum-=len(x,i);
            vis[i]=0;
        }
    
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    double tmp=-1e8;
    //cout<<tmp<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
        if(p[i].y>tmp)
        {
            tmp=p[i].y;
            k=i;
        }
    }
    /*cout<<k<<endl;
    for(int i=1;i<=n;i++)
        cout<<p[i].x<<" "<<p[i].y<<endl;*/
    //choose k as the num
    vis[k]=1;
    dfs(k,num); 
    for(int i=1;i<=n;i++)
    cout<<rans[i]<<" ";
    return 0;
}