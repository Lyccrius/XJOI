#include<stdio.h>
#include<math.h>
long long int tab[10000010];
long long int n,e=1,k,o;
long long int ans=0;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        if(pow(i,k)>=n)
        {
            o=i;
            break;
        }
    }
    long long i=1;
    while(i<=o)
    {
        for(int j=k;j<=n;j++)
        {
            long long int p=pow(i,j);
            if(p<=n)
            {
                int flag=0;
                for(int z=1;z<=e;z++)
                {
                    if(p==tab[z])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans++;
                    e++;
                    tab[e]=p;
                }
                
            }
            else break;
        }
        i++;
    }
    printf("%lld",ans);
    return 0;
}