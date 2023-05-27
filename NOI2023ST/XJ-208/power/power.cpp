#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int n,q,i,t=0;
    cin>>n>>q;
    if(q==1)
    {
        cout<<n;
    }
    if(q==2)
    {
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j*j==i)
                {
                    t++;
                }
            }
        }
        cout<<t;
    }
    if(q==3)
    {
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j*j*j==i)
                {
                    t++;
                }
            }
        }
        cout<<t;
    }
    return 0;
}
