#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);

    long long ans=0;
    long long n;
    int k,o,p,q;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        if(i==1&&k==1)
          ans++;
        else
        {
            for(int j=2;j<=(i/2);j++)
            {
                p=i%j;
                q=i/j;
                if(i==j&&k==1)
                  ans++;
                else if(p==0&&q>=k)
                {
                    ans++;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}