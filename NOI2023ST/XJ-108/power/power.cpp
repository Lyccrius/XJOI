#include<iostream>
#include<cmath>
using namespace std;
long long int ans=1;
long long int n,k,cnt=0;
long long mi[3000000];
long long qpow(long long x,int bt)
{
    long long base=x;
    long long anst=1;
    while(bt)
    {
        if(bt&1)
        {
            if(anst>n/base)return (n+1);
            anst*=base;
        }
        base*=base;
        bt>>=1;
        if(anst>n)return n+1;
    }
    return anst;
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
    for(int i=k;(1<<i)<=n;i++)
    {
        for(int j=2;;j++)
        {
            long long t=qpow(j,i);
            if(t>n)break;
            bool f=true;
            for(int l=1;l<=cnt;l++)
            {
                if(mi[l]==t)
                {
					f=false;
                    break;
                }
            }
            if(f==false)continue;
            else
            {
                ans++;
                mi[++cnt]=t;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
