#include<bits/stdc++.h>
using namespace std;
int f[100000005];
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long int n,k,sum=0;
    scanf("%lld %lld",&n,&k);
    for(int i=k;;i++)
    {
        for(int j=1;j<=n;j++)
        {
            long long int p=pow(j,i);
            if(p>n)
            {
                if(j==2)
                {
                    printf("%lld\n",sum);
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                break;
            }
            else 
            {
                if(f[p]==0)
                {
                    f[p]=1;
                    sum++;
                }
            }
        }
    }
}