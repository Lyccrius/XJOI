#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
long long y[110];
long long f[1000010];
int p=0;
long long gd(long long x,long long y)
{
    if(y==0) return x;
    return gd(y,x%y);
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long n,k;
    scanf("%lld %lld",&n,&k);
    if(k==1)
    {
        printf("%lld\n",n);
        return 0;
    }
    for(int i=k;i<=63;i++)
    {
        if(i==2)
        {
            y[i]=sqrt(n);
            continue;
        }
        long long h=0;
        for(int j=1;;j++)
        {
            long long r=n;
            for(int e=1;e<=i;e++)
            {
                r/=j;
            }
            if(r==0)
            {
                y[i]=j-1;
                break;
            }
        }
    }
    long long ans=y[k];
    for(int i=k+1;i<=63;i++)
    {
        for(int g=1;g<=y[i];g++)
        {
            f[g]=1;
        }
        long long z=y[i];
        for(int j=k;j<=i-1;j++)
        {
            if(i%j==0)
            {
                z=0;
                break;
            }
            long long q=gd(i,j);
            q=j/q;
            int u;
            for(u=1;;u++)
            {
                long long v=y[i];
                for(int tt=1;tt<=q;tt++)
                {
                    v/=u;
                }
                if(v==0)
                {
                    u--;
                    break;
                }
            }
            for(int rr=1;rr<=u;rr++)
            {
                long long w=1;
                for(int tt=1;tt<=q;tt++)
                {
                    w*=rr;
                }
                if(f[w]==1) f[w]=0,z--;
            }
        }
        ans+=z;
    }
    printf("%lld\n",ans);
    return 0;
}