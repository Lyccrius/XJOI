#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
int i,j,n,k,ans=1;
long long int num;
int cnt[100000010];
using namespace std;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1)
    {
        cout<<n;
        return 0;
    }
    for(i=2;i<=sqrt(n);i++)
    {
        num=i;
        for(j=2;num<n;j++)
        {
            num*=i;
            if(num<=n) cnt[num]++;
        }
    }
    for(i=2;i<=n;i++)
        if(cnt[i]+1>=k) ans++;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
