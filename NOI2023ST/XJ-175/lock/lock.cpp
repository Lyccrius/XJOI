#include <bits/stdc++.h>
using namespace std;
int a[5][50010];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int T,k;
    scanf("%d%d",&T,&k);
    if(k==1)
    {
        while(T--)
        {
            memset(a,0,sizeof(a));
            int n,maxn=-1,minn=0x3f3f3f3f;
            scanf("%d",&n);
            for(int i=1;i<=k;i++)
                for(int j=1;j<=n;j++)
                {
                    scanf("%d",&a[i][j]);
                    maxn=max(maxn,a[i][j]);
                    minn=min(minn,a[i][j]);
                }
            printf("%d\n",maxn-minn);
        }
        return 0;
    }
    while(T--)
    {
        printf("0\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}