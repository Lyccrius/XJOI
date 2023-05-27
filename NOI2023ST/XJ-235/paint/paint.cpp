#include <bits/stdc++.h>
#define N 1000010
#define M 100010
using namespace std;
long long T,n,m,q;
long long ma[N],la[N];
long long hangf[N],hangl[N],lief[N],liel[N];
bool flag[N];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    while (T--)
    {
        memset(ma,0,sizeof ma);
        memset(hangf,0,sizeof hangf);
        memset(hangl, 0, sizeof hangl);
        memset(flag,0,sizeof flag);
        memset(la,0,sizeof la);
        //memset(a,0,sizeof a);
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++)
        {
            int opt,x,c;
            cin>>opt>>x>>c;
            if(opt==1)
            {
                for(int i=x;i<=m*n;i+=m)
                {
                    la[i]=c;
                    flag[i]=1;
                }
            }
            else
            {
                ma[m*(x-1)+1]+=c-hangf[x];
                ma[m*x+1]-=c-hangl[x];
                hangf[x]=c;
                hangl[x]=c;
                for(int i=1;i<=m;i++)
                {
                    flag[m*(x-1)+i]=0;
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n*m;i++)
        {
            ans+=ma[i];
            if(flag[i]==0)cout<<ans<<" ";
            else cout<<la[i]<<" ";
            if(i%m==0) cout<<endl;
        }
    }
    
    return 0;

}