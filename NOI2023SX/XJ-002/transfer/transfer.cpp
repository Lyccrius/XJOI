#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int nm=1e5+5;
struct node
{
    int x,v;
}id[nm];
int sid;
int n,k,m;
int p[nm],x[nm],v[nm];
int number,x1,v1,id1;
int bumen[nm]={0};
ll ans;
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    ans=0;
    cin>>sid;
    cin>>n>>k>>m;
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
    }	
    for(int i=1;i<=k;i++)
    {
        cin>>id[i].x>>id[i].v;
        if(bumen[id[i].x]<id[i].v)
        {
            bumen[id[i].x]=id[i].v;
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans+=bumen[i];
    }
    cout<<ans<<" ";
    while(m--)
    {
        ans=0;
        memset(bumen,0,sizeof(bumen));
        cin>>number;
        if(number==1)
        {
            cin>>x1>>v1;
            k++;
            id[k].x=x1;id[k].v=v1;
        }
        else
        {
            cin>>id1;
            id[id1].v=0;
        }
        for(int i=1;i<=k;i++)
        {
            if(bumen[id[i].x]<id[i].v)
            {
                bumen[id[i].x]=id[i].v;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans+=bumen[i];
        }
        cout<<ans<<" ";
    }
}
