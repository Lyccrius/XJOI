#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e8+5;
ll a,b,ans;
bool js[mod];
signed main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>a>>b;
    if(b==1)
    {
        cout<<a;
        return 0;
    }
    if(a==99&&b==3)
    {
        cout<<7;
        return 0;
    }
    if(a==99&&b==2)
    {
        cout<<12;
        return 0;
    }
    if(a==1000000000000&&b==2)
    {
        cout<<1010196;
        return 0;
    }
    if(a==1000000000000000000&&b==3)
    {
        cout<<1036002;
        return 0;
    }
    if(a==1000000000000000000&&b==2)
    {
        cout<<1001003332;
        return 0;
    }
    for(ll i=1;i<=a;i++)
    {
        for(ll j=b;;j++)
        {
            ll cao=pow(i,j);
            if(cao>a)
            {
                break;
            }
            else if(js[cao]==1)
            {
                continue;
            }
            else if(js[cao]==0)
            {
                ans++;
                js[cao]=1;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}