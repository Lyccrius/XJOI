#include<bits/stdc++.h>
using namespace std;
long long n,k,cmp,ans;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1)
    {
        cout<<n;
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=i;j++)
        {
            while(i)
            {
                if(i%j!=0) break;
                i/=j;
                cmp++;
                if(cmp>=k)
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}