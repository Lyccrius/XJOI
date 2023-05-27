#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int maxt(int a[],int n)
{
    if(n==0)
    {
        return 0;
        }
    int r=a[0];
    for(int i=1;i<n;i++)
    {
        r=max(a[i],r);
    }
    return r;
}
int sum(int a[],int n)
{
    int r=0;
    for(int i=0;i<n;i++)
    {
        r+=a[i];

    }
    return r;
}
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    int sid;
    cin>>sid;
    int n,m,k;
    cin>>n>>m>>k;
    int p;
    for(int i=0;i<n-1;i++)
    {
        cin>>p;
    }
    int x[k],v[k];
    for(int i=0;i<k;i++)
    {
        cin>>x[i]>>v[i];
    }
    int diyu[n+k+m];
    int dn=0;
    int anpai[n];
    int idanpai[n];
    for(int i=0;i<n;i++)
    {
        anpai[i]=0;
        idanpai[i]=0;
    }
    for(int i=0;i<k;i++)
    {
        for(int j=x[i];i<=n;i++)
        {
            if(anpai[j]==0)
            {
                anpai[j]=v[i];
                idanpai[j]=i;
                break;
            }
            if(anpai[j]<v[i])
            {
                int t=v[i];
                v[i]=anpai[j];
                anpai[j]=t;
                idanpai[j]=i;
            }
            if(j==n)
            {
                diyu[dn]=v[i];
                dn++;
            }
        }
    }
    cout<<sum(anpai,n)<<" ";
    for(int T=0;T<m;T++)
    {
        int con;
        cin>>con;
        if(con==1)
        {
            k++;
            int x,v;
            cin>>x>>v;
            int i=k;
            for(int j=x;i<=n;i++)
        {
            if(anpai[j]==0)
            {
                anpai[j]=v;
                break;
            }
            if(anpai[j]<v)
            {
                int t=v;
                v=anpai[j];
                anpai[j]=t;
            }
            if(i==n)
            {
                diyu[dn]=v;
                dn++;
            }
            cout<<sum(anpai,n)<<" ";
        }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}