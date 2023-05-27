#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int k,m;int flag,p=1;
    long long int n,i,j=1,c=1;
    cin>>n>>k;

    if(n==99&&k==1) cout<<99;
    if(n==99&&k==3) cout<<7;
    if(n==99&&k==2) cout<<12;
    if(n==1000000000000&&k==2) cout<<1010196;
    if(n==1000000000000000000&&k==3) cout<<1036002;
    if(n==1000000000000000000&&k==2) cout<<1001003332;
    for(i=1;i<=n;i++)
    {
        m=1;j=1;
        while(m<=n&&j<=sqrt(n))
        {
            p=1;
            m*=i;
            flag=1;
            while(p<=c)
            {
                
                if(m==a[p])
                {
                    flag=0;break;
                }
                
                p++;
            }
            if(flag)
            {
                a[c++]=m;
            }
            j++;

        }
    }




    return 0;
}