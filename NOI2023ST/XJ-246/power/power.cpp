#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt=1;
ll k;
map<ll,ll> a;
ll jiecheng(ll a,ll b)
{
    ll ab=1;
    for(ll i=1;i<=b;i++)
    {
        ab*=a;
    }
    return ab;
}
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
    else
    {
        for(ll i=2;i<=sqrt(n);i++)
        {
            for(ll j=k;j<=60;j++)
            {
                ll md=jiecheng(i,j);
                if(md<=n&&md>0)
                {
                    if(a[md]!=1)
                    {
                        cnt++;
                        a[md]=1;
                        //cout<<"cnt="<<cnt<<" i^j="<<md<<" i="<<i<<" j="<<j<<" sqrt(n)="<<sqrt(n)<<" a[md]="<<a[md]<<endl;
                    }
                    else
                    {
                        continue;
                    }
                }
                else break;
            }
        }
        cout<<cnt;
    }
}