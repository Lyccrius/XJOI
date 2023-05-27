#include<bits/stdc++.h>
using namespace std;
const int N=5e4+20;
const int inf=0x3f3f3f3f;
int T,k;
int n;
int a[N][4];

namespace subtask1{
    void solve()
    {
        int maxx=-inf,minn=inf;
        for(int i=1;i<=n;i++)
            maxx=max(maxx,a[i][1]),minn=min(minn,a[i][1]);
        printf("%d\n",maxx-minn);
    }
}

namespace subtask2{
    int b[N][4];

    int calc()
    {
        int ans=-inf;
        int maxx=-inf,minn=inf;
        for(int i=1;i<=n;i++) maxx=max(maxx,b[i][1]),minn=min(minn,b[i][1]);
        ans=maxx-minn;
        maxx=-inf,minn=inf;
        for(int i=1;i<=n;i++) maxx=max(maxx,b[i][2]),minn=min(minn,b[i][2]);
        return max(maxx-minn,ans);
    }

    void solve()
    {
        int ans=inf;
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>>j&1) b[j+1][1]=a[j+1][1],b[j+1][2]=a[j+1][2];
                else b[j+1][1]=a[j+1][2],b[j+1][2]=a[j+1][1];
            }
            ans=min(ans,calc());
        }
        printf("%d\n",ans);
    }
}


int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d%d",&T,&k);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++) scanf("%d",&a[j][i]);
        if(k==1) subtask1::solve();
        else if(k==2) subtask2::solve();
    }
}