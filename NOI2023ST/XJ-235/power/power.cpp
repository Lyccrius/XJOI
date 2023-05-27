#include <bits/stdc++.h>
using namespace std;
int      flag[1000010];
int main()
{
    long long k;
    int ans=0;
    long long n;
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1)
    {
        cout<<n;
        return 0;
    }
        int t=(int)sqrt(n);
        int flg=0,ches=1,j;
    for(int nn=3;nn<=t;nn++)
    {
        if(flag[nn]==0)
        {
            flg=0,ches=1,j=nn;
            while(j<=n)
            {
             if(j<=t) flag[j]=1;

                if(ches>=k) {ans++;flg=1;}
                ches++;
                j*=nn;
            }
            if(flg==0) break;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}