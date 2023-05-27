#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
#define LL long long
LL b,k,ans;
int numsq(LL b)
{
    if(b==1)return k+1;
    for(LL j=2;j<=sqrt(b);j++)
    {
        LL ans=0,t=1;
        for(LL i=1;;i++)
        {
            if(t==b)
            {
                return ans;
            }
            else if(ans>=b)break;
            t=t*j;
            ans++;
        }
    }
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>b>>k;
    if(k==1)
    {
        cout<<b<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(LL i=1;i<=b;i++)
    {
        int tmp=numsq(i);
        if(tmp>=k)ans++;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}