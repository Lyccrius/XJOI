#include <bits/stdc++.h>
using namespace std;
int a[10][1500005],f[1500005];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int T,k;
    scanf("%d%d",&T,&k);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
               scanf("%d",&a[i][j]); 
            }
        }
        for(int i=1;i<=n;i++)
        {
            f[i]=a[1][i];
        }
        sort(f+1,f+n+1);
        int ans;
        ans=f[n]-f[1];
        printf("%d\n",ans);
    }
    return 0;
}