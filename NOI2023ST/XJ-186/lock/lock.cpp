#include<bits/stdc++.h>
using namespace std;
long minc=INT_MAX,t,k,n;
/*void yidong(long l,long c)
{
    if(c==0) return ;
    long b,d,i;
    if(c==1)
    {
        b=a[k][l];
        for(i=k-1;i>=1;i--)
        a[(i+1)%k][l]=a[i][l];
        a[1][l]=b;
    }
    else
    if(c==2)
    {
        b=a[k][l],d=a[k-1][l];
        for(i=k-2;i>=1;i--)
        a[(i+2%k)][l]=a[i][l];
        a[1][l]=d,a[2][l]=b;
    }
}*/
void fun(long l,long c,long a[10][50005])
{
    if(c>2||l>n) return ;
    long ax=-1,in=INT_MAX,ans=0,i,b,d;
    if(c==1)
    {
        b=a[k][l];
        for(i=k-1;i>=1;i--)
        a[(i+1)%k][l]=a[i][l];
        a[1][l]=b;
    }
    else
    if(c==2)
    {
        b=a[k][l],d=a[k-1][l];
        for(i=k-2;i>=1;i--)
        a[(i+2%k)][l]=a[i][l];
        a[1][l]=d,a[2][l]=b;
    }
    for(long i=1;i<=k;i++)
    {
        for(long j=1;j<=n;j++)
        {
            ax=max(ax,a[i][j]);
            in=min(in,a[i][j]);
        }
        ans+=ax-in;
    }
    minc=min(minc,ans);
    fun(l+1,c,a);
    fun(l,c+1,a);
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long i,j,ax=-1,in=INT_MAX,b;
    long a[10][50005];
    cin>>t>>k;
    while(t--)
    {
        if(k==1)
        {
            cin>>n;
            for(i=1;i<=n;i++)
            {
                cin>>b;
                ax=max(ax,b);
                in=min(in,b);
            }
            cout<<ax-in<<endl;
        }
        else
        {
            memset(a,0,sizeof(a));
            minc=INT_MAX;
            cin>>n;
            for(i=1;i<=k;i++)
            for(j=1;j<=n;j++)
            cin>>a[i][j];
            fun(1,0,a);
            cout<<minc<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}