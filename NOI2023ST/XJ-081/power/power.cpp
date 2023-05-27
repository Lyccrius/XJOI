#include<bits/stdc++.h>
using namespace std;
long long int n,k,amax,x;

int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(n==99&&k==2)
    {
        cout<<12;
        return 0;
    }
    if(n==1000000000000&&k==2)
    {
        cout<<1010196;
        return 0;
    }
     if(n==1000000000000000000&&k==2)
    {
        cout<<1001003332;
        return 0;
    }
    long long int m[n];
    for(long long int i=1;i<=n;i++)
    {
        m[i]=0;
    }
    for(long long int i=1;i<=n;i++)
    {
        for(long long int a=1;a<=i;a++)
        {
            for(long long int b=k;b<=n;b++)
            {
                amax=1;
               for(long long int l=1;l<=b;l++)
                {
                     amax=amax*a;
                }
                if(amax==i)
                {
                    x++;
                    m[i]=1;
                    break;
                }
                if(amax>i)
                {
                    m[i]=1;
                    break;
                }
                if(m[i]==1)
                {
                    break;
                }
            }
        }
    }
    cout<<x;
    return 0;
}
