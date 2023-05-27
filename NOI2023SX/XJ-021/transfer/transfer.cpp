#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100010;
struct node1{
    int x,v;
}pe[N];
int sid;
int n,k,m;
int p[N],pa[N];
int sum,delta;
int pnum[N];
void add(int a,int b)
{
    pe[++k].x=a;
    pe[k].v=b;
    int pre=pa[pe[k].x];
    pa[pe[k].x]=max(pa[pe[k].x],pe[k].v);
    delta=pa[pe[k].x]-pre;
    return;
}
void del(int a)
{
    int pre=pa[pe[a].x];
    if(pnum[pe[a].x]!=a)
    {
        delta=0;
        return;
    }
    else
    {
        pa[pe[a].x]=0;
        for(int i=1;i<=k;i++)
        {
            if(i!=a&&pe[i].x==pe[a].x)
            {
                if(pe[i].v>pa[pe[a].x])
                    pa[pe[a].x]=pe[i].v;
            }
        }
        delta=pa[pe[a].x]-pre;
        return;
    }
}
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    cin>>sid;
    cin>>n>>k>>m;
    p[1]=1;
    for(int i=2;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=k;i++)
    {
        cin>>pe[i].x>>pe[i].v;
        if(pe[i].v>pa[pe[i].x])
        {
             pa[pe[i].x]=pe[i].v;
             pnum[pe[i].x]=i;
        }
       
    }
    for(int i=1;i<=n;i++)
        sum+=pa[i];
    cout<<sum<<" ";
    int real=k;
   while(m--)
   {
       k=real;
       delta=0;
       int op;
       cin>>op;
       if(op==1)
       {
           int a,b;
           cin>>a>>b;
           add(a,b);
           cout<<sum+delta<<" ";
       }
       else if(op==2)
       {
           int a;
           cin>>a;
           del(a);
           cout<<sum+delta<<" ";
       }
   }
}