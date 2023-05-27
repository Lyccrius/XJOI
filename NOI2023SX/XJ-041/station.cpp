#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
void checkin(int a[],int l,int r)
{
    for(int i=l;i<=r;i++)
    {
        if(a[i]==0)
        {
            a[i]=1;
        }
    }
    return ;
}
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    int n,m,x;
    cin>>n>>m>>x;
    int l[m+1],r[m+1];
    int res[n+1];
    int undercover[n+1];
    for(int i=0;i<=n;i++)
    {
        res[i]=0;
        undercover[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    undercover[x]=1;
    int flag=1;
    while(flag==1)
    {
        flag=0;
        for(int i=1;i<=n;i++)
        {
            if(undercover[i]==1)
            {
                flag=1;
                undercover[i]=2;
                for(int j=1;j<=m;j++)
                {
                    if(l[j]==i)
                    {
                        if(i-x>=0)
                        {
                            checkin(undercover,l[j],r[j]);
                            res[r[j]]=1;
                        }
                    }
                    if(r[j]==i)
                    {
                        if(i-x<=0)
                        {
                            checkin(undercover,l[j],r[j]);
                            res[l[j]]=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(res[i]==1)
        {
            cout<<i<<" ";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}