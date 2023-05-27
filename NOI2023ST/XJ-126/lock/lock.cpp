#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int t,k;
    scanf("%d %d",&t,&k);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[k+2][n+10];
        int mi=1e9,ma=0;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                mi=min(a[i][j],mi);
                ma=max(a[i][j],ma);
            }
        }
        if(k==1)
        {
            printf("%d\n",ma-mi);
        }
        if(k==2)
        {
            int mi1=1e9,mi2=1e9,ma1=0,ma2=0;
            for(int i=1;i<=n;i++)
            {
                if(a[1][i]>a[2][i]) swap(a[1][i],a[2][i]);
                mi1=min(mi1,a[1][i]);
                mi2=min(mi2,a[2][i]);
                ma1=max(ma1,a[1][i]);
                ma2=max(ma2,a[2][i]);
            }
            printf("%d\n",max(ma1-mi1,ma2-mi2));
        }
        if(k==3)
        {
            int mi1=1e9,mi2=1e9,mi3=1e9,ma1=0,ma2=0,ma3=0;
            for(int i=1;i<=n;i++)
            {
                if(a[3][i]<a[2][i]||a[2][i]<a[1][i])
                {
                    int q=a[2][i];
                    a[1][i]=a[3][i];
                    a[2][i]=a[1][i];
                    a[3][i]=q;
                }
                if(a[3][i]<a[2][i]||a[2][i]<a[1][i])
                {
                    int q=a[2][i];
                    a[1][i]=a[3][i];
                    a[2][i]=a[1][i];
                    a[3][i]=q;
                }
                mi1=min(mi1,a[1][i]);
                mi2=min(mi2,a[2][i]);
                mi3=min(mi3,a[3][i]);
                ma1=max(ma1,a[1][i]);
                ma2=max(ma2,a[2][i]);
                ma3=max(ma3,a[3][i]);
            }
            int ans1=max(max(ma1-mi1,ma2-mi2),ma3-mi3);
            mi1=1e9,mi2=1e9,mi3=1e9,ma1=0,ma2=0,ma3=0;
            for(int i=1;i<=n;i++)
            {
                if(a[1][i]>a[2][i]&&a[1][i]<a[3][i])
                {
                    int q=a[2][i];
                    a[1][i]=a[3][i];
                    a[2][i]=a[1][i];
                    a[3][i]=q;
                }
                mi1=min(mi1,a[1][i]);
                mi2=min(mi2,a[2][i]);
                mi3=min(mi3,a[3][i]);
                ma1=max(ma1,a[1][i]);
                ma2=max(ma2,a[2][i]);
                ma3=max(ma3,a[3][i]);
            }
            int ans2=max(max(ma1-mi1,ma2-mi2),ma3-mi3);
            mi1=1e9,mi2=1e9,mi3=1e9,ma1=0,ma2=0,ma3=0;
            for(int i=1;i<=n;i++)
            {
                if(a[1][i]>a[2][i]&&a[2][i]>a[3][i])
                {
                    int q=a[2][i];
                    a[1][i]=a[3][i];
                    a[2][i]=a[1][i];
                    a[3][i]=q;
                }
                mi1=min(mi1,a[1][i]);
                mi2=min(mi2,a[2][i]);
                mi3=min(mi3,a[3][i]);
                ma1=max(ma1,a[1][i]);
                ma2=max(ma2,a[2][i]);
                ma3=max(ma3,a[3][i]);
            }
            int ans3=max(max(ma1-mi1,ma2-mi2),ma3-mi3);
            printf("%d\n",min(min(ans1,ans2),ans3));
        }
        if(k==4)
        {
            int mi1=1e9,mi2=1e9,mi3=1e9,mi4=1e9,ma1=0,ma2=0,ma3=0,ma4=0;
            for(int i=1;i<=n;i++)
            {
                if(a[1][i]>a[2][i]) swap(a[1][i],a[2][i]);
                if(a[1][i]>a[3][i]) swap(a[1][i],a[3][i]);
                if(a[1][i]>a[4][i]) swap(a[1][i],a[4][i]);
                if(a[2][i]>a[3][i]) swap(a[2][i],a[3][i]);
                if(a[2][i]>a[4][i]) swap(a[2][i],a[4][i]);
                if(a[3][i]>a[4][i]) swap(a[3][i],a[4][i]);
                mi1=min(mi1,a[1][i]);
                mi2=min(mi2,a[2][i]);
                mi3=min(mi3,a[3][i]);
                mi4=min(mi4,a[4][i]);
                ma1=max(ma1,a[1][i]);
                ma2=max(ma2,a[2][i]);
                ma3=max(ma3,a[3][i]);
                ma4=max(ma4,a[4][i]);
            }
            printf("%d\n",max(max(ma1-mi1,ma2-mi2),max(ma3-mi3,ma4-mi4)));
        }
    }
    return 0;
}